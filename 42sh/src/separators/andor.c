/*
** andor.c for PSU_2016_42sh in /home/antoine.casse/Desktop/42/PSU_2016_42sh/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sat May 20 13:21:25 2017 Capitaine CASSE
** Last update Sun May 21 21:00:16 2017 Matthieu BRAULT
*/

#include <unistd.h>
#include <fcntl.h>
#include "mysh.h"

static void	set_end(char **tab, char *tmp, t_ctrl *ctrl, int *give)
{
  if (tmp != NULL && !my_strcmp(tmp, ">"))
    {
      give[1] = open(tab[ctrl->e + 1], O_WRONLY | O_CREAT | O_TRUNC, RIGHTS);
      ctrl->skip += 1;
    }
  else if (tmp != NULL && !my_strcmp(tmp, ">>"))
    {
      give[1] = open(tab[ctrl->e + 1], O_WRONLY | O_CREAT | O_APPEND, RIGHTS);
      ctrl->skip += 1;
    }
}

static int	or_loop(char **tab, t_ctrl ctrl, t_list **env, int *ret)
{
  int		give[3];
  char		*tmp;

  give[0] = -1;
  give[1] = -1;
  while (ctrl.s < ctrl.max)
    {
      find_next(tab, &(ctrl.e));
      tmp = tab[ctrl.e];
      tab[ctrl.e] = NULL;
      give[2] = *ret;
      if (ctrl.skip + 1 == ctrl.r)
	set_end(tab, tmp, &ctrl, give);
      input_man(tab + ctrl.s, env, give, 1);
      tab[ctrl.e] = tmp;
      if (!(*ret = give[2]))
	return (ctrl.r);
      ctrl.s = ctrl.e < ctrl.max ? ++ctrl.e : ctrl.e;
      ctrl.skip += 1;
    }
  return (ctrl.skip);
}

static int	and_loop(char **tab, t_ctrl ctrl, t_list **env, int *ret)
{
  int		give[3];
  char		*tmp;

  give[0] = -1;
  give[1] = -1;
  while (ctrl.s < ctrl.max)
    {
      find_next(tab, &(ctrl.e));
      tmp = tab[ctrl.e];
      tab[ctrl.e] = NULL;
      give[2] = *ret;
      if (ctrl.skip + 1 == ctrl.r)
	set_end(tab, tmp, &ctrl, give);
      input_man(tab + ctrl.s, env, give, 1);
      tab[ctrl.e] = tmp;
      if ((*ret = give[2]) != 0)
	return (ctrl.r);
      ctrl.s = ctrl.e < ctrl.max ? ++ctrl.e : ctrl.e;
      ctrl.skip += 1;
    }
  return (ctrl.skip);
}

int		oror(t_cmd **act, t_list **env, int *ret)
{
  t_ctrl	ctrl;
  int		nb;

  ctrl.e = 0;
  ctrl.s = 0;
  ctrl.max = 0;
  ctrl.r = 1;
  ctrl.in = -1;
  ctrl.skip = 0;
  ctrl.fdlist = NULL;
  find_next((*act)->cmd, &(ctrl.max));
  while (find_next((*act)->cmd, &(ctrl.max)) == 7 && ++ctrl.r)
    ctrl.max += 1;
  if ((nb = or_loop((*act)->cmd, ctrl, env, ret)) == -1)
    return (1);
  while (--nb != 0 && (*act) != NULL)
    *act = (*act)->next;
  return (0);
}

int		andand(t_cmd **act, t_list **env, int *ret)
{
  t_ctrl	ctrl;
  int		nb;

  ctrl.e = 0;
  ctrl.s = 0;
  ctrl.max = 0;
  ctrl.r = 1;
  ctrl.in = -1;
  ctrl.skip = 0;
  ctrl.fdlist = NULL;
  find_next((*act)->cmd, &(ctrl.max));
  while (find_next((*act)->cmd, &(ctrl.max)) == 6 && ++ctrl.r)
    ctrl.max += 1;
  if ((nb = and_loop((*act)->cmd, ctrl, env, ret)) == -1)
    return (1);
  while (--nb != 0 && (*act) != NULL)
    *act = (*act)->next;
  return (0);
}
