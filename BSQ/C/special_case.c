/*
** special_case.c for  in /home/b00bix/delivery/CProgElem/CPE_2016_BSQ
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Fri Dec 16 23:43:24 2016 Matthieu BRAULT
** Last update Sat Dec 17 00:00:26 2016 Matthieu BRAULT
*/

#include "bsq.h"

int	check_if_empty(char *str)
{
  int	s;

  s = 0;
  while (str[s] != '\0')
    {
      if (str[s] == 'o')
	return (1);
      s = s + 1;
    }
  return (0);
}

int	special_case(t_tab *t, char *str)
{
  if (check_if_empty(str) == 1)
    return (0);
  if (t->line >= t->width)
    put_x(t, 0, 0, t->width);
  else if (t->width > t->line)
    put_x(t, 0, 0, t->line);
  free_malloc(t, str);
  exit(0);
}
