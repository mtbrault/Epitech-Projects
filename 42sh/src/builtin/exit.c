/*
** exit.c for  in /home/b00bix/PSU_2016_42sh
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Wed Apr 12 17:01:02 2017 Matthieu BRAULT
** Last update Sun May 21 20:53:39 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

char		check_is_num(char *str)
{
  int		nb;

  nb = 0;
  if (str == NULL)
    return (FAIL);
  while (str[nb] != '\0' && str[nb] >= '0' && str[nb] <= '9')
    nb = nb + 1;
  if (str[nb] != '\0')
    return (FAIL);
  return (SUCCESS);
}

void	free_exit(char **tab)
{
  int	nb;

  nb = 0;
  while (tab != NULL && tab[nb] != NULL)
    {
      free(tab[nb]);
      nb = nb + 1;
    }
}

int	my_exit(char **argument, t_list **env, int *fd)
{
  int	tmp;

  env = env;
  if (argument != NULL && argument[1] == NULL)
    {
      my_putstr(EXIT);
      free_exit(argument);
      free_env(*env);
      exit(fd[2]);
    }
  else if (argument != NULL && check_is_num(argument[1]) == SUCCESS)
    {
      my_putstr(EXIT);
      tmp = my_atoi(argument[1]);
      free_env(*env);
      free_exit(argument);
      exit(tmp);
    }
  else
    my_puterror(SYNTAX_ERROR, SUCCESS);
  return (fd[2] = 1);
}
