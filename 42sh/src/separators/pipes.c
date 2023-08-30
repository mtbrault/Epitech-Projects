/*
** tmp.c for PSU_2016_42sh in /home/antoine.casse/Desktop/42/PSU_2016_42sh
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Thu May 18 16:19:00 2017 Capitaine CASSE
** Last update Sun May 21 21:00:21 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"

static char	add_to_list(t_ctrl *ctrl, t_cmd **pars)
{
  if (ctrl->fdlist == NULL)
    {
      if ((ctrl->fdlist = malloc(sizeof(t_cmd))) == NULL)
	return (FAIL);
      *pars = ctrl->fdlist;
    }
  else
    {
      if (((*pars)->next = malloc(sizeof(t_cmd))) == NULL)
	return (FAIL);
      *pars = (*pars)->next;
    }
  return (0);
}

static char	fork_func(char **tab, t_list **env, int *give, t_ctrl *ctrl)
{
  pid_t		pid;
  t_cmd		*pars;

  pars = ctrl->fdlist;
  while (pars != NULL && pars->next != NULL)
    pars = pars->next;
  pid = input_man(tab, env, give, 0);
  add_to_list(ctrl, &pars);
  pars->cmd = NULL;
  pars->mode = pid;
  pars->next = NULL;
  if (give[1] == -1)
    {
      pars = ctrl->fdlist;
      while (pars != NULL)
	{
	  waitpid(pars->mode, give + 2, WUNTRACED);
	  check_exec(give);
	  if (give[2] != 0)
	    return (FAIL);
	  pars = pars->next;
	}
    }
  return (SUCCESS);
}

static void	set_end_pipes(char **tab, char *tmp, t_ctrl *ctrl, int *give)
{
  ctrl->skip += 1;
  if (tmp != NULL && !my_strcmp(tmp, ">"))
    give[1] = open(tab[ctrl->e + 1], O_WRONLY | O_CREAT | O_TRUNC, RIGHTS);
  else if (tmp != NULL && !my_strcmp(tmp, ">>"))
    give[1] = open(tab[ctrl->e + 1], O_WRONLY | O_CREAT | O_APPEND, RIGHTS);
  else
    {
      give[1] = -1;
      ctrl->skip -= 1;
    }
}

static int	pipe_loop(char **tab, t_ctrl ctrl, t_list **env, int *ret)
{
  int		pipefd[2];
  int		give[3];
  char		*tmp;

  while (ctrl.s < ctrl.max && pipe(pipefd) != FAIL)
    {
      find_next(tab, &(ctrl.e));
      tmp = tab[ctrl.e];
      tab[ctrl.e] = NULL;
      give[0] = ctrl.in;
      if (ctrl.skip + 1 == ctrl.r)
	set_end_pipes(tab, tmp, &ctrl, give);
      else
	give[1] = pipefd[1];
      give[2] = *ret;
      fork_func(tab + ctrl.s, env, give, &ctrl);
      *ret = give[2];
      give[0] == -1 ? 0 : close(give[0]);
      give[1] == -1 ? 0 : close(give[1]);
      ctrl.in = pipefd[0];
      tab[ctrl.e] = tmp;
      ctrl.s = ctrl.e < ctrl.max ? ++ctrl.e : ctrl.e;
      ctrl.skip += 1;
    }
  return (ctrl.skip);
}

int		pipe_it(t_cmd **act, t_list **env, int *ret)
{
  t_ctrl	ctrl;
  int		j;

  ctrl.e = 0;
  ctrl.s = 0;
  ctrl.max = 0;
  ctrl.r = 1;
  ctrl.in = -1;
  ctrl.skip = 0;
  ctrl.fdlist = NULL;
  find_next((*act)->cmd, &(ctrl.max));
  while (find_next((*act)->cmd, &(ctrl.max)) == 1 && ++ctrl.r)
    ctrl.max += 1;
  if ((j = pipe_loop((*act)->cmd, ctrl, env, ret)) == -1)
    return (1);
  while (--j > 0 && (*act) != NULL)
    *act = (*act)->next;
  return (SUCCESS);
}
