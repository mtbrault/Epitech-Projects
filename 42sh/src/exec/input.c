/*
** input.c for PSU_2016_42sh in /home/antoine.casse/Desktop/PSU_2016_42sh/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Wed Apr 12 17:01:10 2017 Capitaine CASSE
** Last update Sun May 21 20:55:47 2017 Matthieu BRAULT
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"

static t_built	g_builtins[NB_BUILTS] =
  {
    {CD, my_cd},
    {SETENV, my_setenv},
    {UNSETENV, my_unsetenv},
    {ENV, my_env},
    {ECHO, my_echo},
    {EXIT_S, my_exit},
    {SET_HIST, history},
  };

static char	exec_prep(char **tab, t_list **list, int *fd)
{
  int		i;

  i = 0;
  if (tab != NULL && tab[0] != NULL)
    {
      while (tab[0][i] && tab[0][i] != '/')
	i += 1;
      if (tab[0][i] && !access(tab[0], F_OK | X_OK))
	return (exec_prog(tab[0], tab, list, fd));
      else if (!tab[0][i] && my_path(tab, list, fd))
	{
	  my_puterror(tab[0], 0);
	  my_puterror(CMD_NF, 0);
	}
      else
	{
	  my_puterror(tab[0], 0);
	  my_puterror(CMD_NF, 0);
	}
    }
  return (SUCCESS);
}

int		input_man(char **tab, t_list **list, int *fd, int w)
{
  int		nb;
  pid_t		pid;

  nb = 0;
  while (nb < NB_BUILTS)
    {
      if (tab != NULL && !my_strcmp(tab[0], g_builtins[nb].name))
	return (g_builtins[nb].p(tab, list, fd));
      nb += 1;
    }
  nb = 0;
  if ((pid = fork()) < 0)
    return (84);
  else if (!pid)
    {
      exec_prep(tab, list, fd);
      exit(1);
    }
  if (w)
    waitpid(pid, fd + 2, WUNTRACED);
  check_exec(fd);
  return (pid);
}
