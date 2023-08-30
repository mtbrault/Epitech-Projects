/*
** my_echo.c for  in /home/b00bix/PSU_2016_42sh/src/echo
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Wed Apr 12 16:29:43 2017 Matthieu BRAULT
** Last update Sun May 21 20:54:07 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

int	my_echo(char **argument, t_list **env, int *fd)
{
  int	nb;

  nb = 1;
  env = env;
  fd_management_two(fd, 1);
  if (!argument[1] || argument == NULL)
    {
      my_putchar('\n');
      fd_management_two(fd, 0);
      return (0);
    }
  else if (my_strcmp(argument[1], "-n") == 0)
    nb = 2;
  while (argument[nb] != NULL && argument[nb][0] != '\0')
    {
      my_putstr(argument[nb]);
      if (argument[nb + 1] != NULL)
	my_putchar(' ');
      nb = nb + 1;
    }
  if (my_strcmp(argument[1], "-n") != 0)
    my_putchar('\n');
  fd_management_two(fd, 0);
  return (0);
}
