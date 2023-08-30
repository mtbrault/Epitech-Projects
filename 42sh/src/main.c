/*
** main.c for PSU_2016_42sh in /home/antoine.casse/Desktop/PSU_2016_42sh/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Wed Apr 12 19:40:07 2017 Capitaine CASSE
** Last update Sun May 21 20:56:39 2017 Matthieu BRAULT
*/

#include <unistd.h>
#include <signal.h>
#include "mysh.h"

int		main(int ac, char **av, char **env)
{
  t_alias	**alias;
  t_list	*list;
  int		ret;

  ac = ac;
  av = av;
  ret = 0;
  alias = NULL;
  signal(SIGINT, ctr_c);
  if (env != NULL && env[0] != NULL)
    {
      if ((list = list_fill(env)) == NULL)
	return (ERROR);
    }
  else
    list = NULL;
  if (my_shrc(&list, &alias) == ERROR)
    return (ERROR);
  if (loop(list, &ret, alias) == ERROR)
    {
      free_list(list);
      return (ERROR);
    }
  free_env(list);
  return (ret);
}
