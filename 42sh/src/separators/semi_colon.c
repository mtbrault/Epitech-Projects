/*
** semi_colon.c for PSU_2016_42sh in /home/antoine.casse/Desktop/tmp/PSU_2016_42sh
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun May 21 15:36:41 2017 Capitaine CASSE
** Last update Sun May 21 21:00:48 2017 Matthieu BRAULT
*/

#include <unistd.h>
#include "mysh.h"

int	semi_colon(t_cmd **act, t_list **env, int *ret)
{
  int	e;
  int	give[3];
  char	*tmp;

  e = 0;
  find_next((*act)->cmd, &e);
  tmp = (*act)->cmd[e];
  (*act)->cmd[e] = NULL;
  give[2] = *ret;
  give[0] = -1;
  give[1] = -1;
  input_man((*act)->cmd, env, give, 1);
  (*act)->cmd[e] = tmp;
  *ret = give[2];
  return (0);
}
