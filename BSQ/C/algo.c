/*
** algo.c for  in /home/b00bix/delivery/CProgElem/CPE_2016_BSQ
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Tue Dec 13 19:15:55 2016 Matthieu BRAULT
** Last update Wed Dec 14 00:09:45 2016 Matthieu BRAULT
*/

#include "bsq.h"

int	my_min(t_tab *tab, int s, int x)
{
  int	a;
  int	b;
  int	c;

  a = tab->int_map[s][x + 1];
  b = tab->int_map[s + 1][x + 1];
  c = tab->int_map[s + 1][x];
  if (a <= b)
    {
      if (c <= a)
	return (c);
      else
	return (a);
    }
  else if (b <= a)
    {
      if (c <= b)
	return (c);
      else
	return (b);
    }
  return (0);
}

void	my_algo(t_tab *tab)
{
  int	s;
  int	x;

  s = tab->line - 2;
  while (s >= 0)
    {
      x = tab->width - 2;
      while (x > 0)
	{
	  if (tab->int_map[s][x] != 0)
	    tab->int_map[s][x] = 1 + my_min(tab, s, x);
	  x = x - 1;
	}
      s = s - 1;
    }
}
