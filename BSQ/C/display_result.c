/*
** display_result.c for  in /home/b00bix/delivery/CProgElem/CPE_2016_BSQ
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Tue Dec 13 20:56:22 2016 Matthieu BRAULT
** Last update Wed Dec 14 00:10:37 2016 Matthieu BRAULT
*/

#include "bsq.h"

int	find_higher(t_tab *tab)
{
  int	s;
  int	x;
  int	abs;
  int	ord;

  s = tab->int_map[0][0];
  ord = 0;
  while (ord < tab->line)
    {
      abs = 0;
      while (abs < tab->width)
	{
	  x = tab->int_map[ord][abs];
	  if (x > s)
	    s = x;
	  abs = abs + 1;
	}
      ord = ord + 1;
    }
  return (s);
}

void	display_result(t_tab *tab)
{
  int	abs;
  int	ord;
  int	square;

  ord = 0;
  square = find_higher(tab);
  while (ord < tab->line)
    {
      abs = 0;
      while (abs < tab->width)
	{
	  if (tab->int_map[ord][abs] == square)
	    {
	      put_x(tab, ord, abs, square);
	      return ;
	    }
	  abs = abs + 1;
	}
      ord = ord + 1;
    }
}

void	put_x(t_tab *tab, int x, int y, int size)
{
  int	s;
  int	a;
  int	b;

  a = 0;
  while (a < size)
    {
      s = 0;
      b = y;
      while (s < size)
	{
	  tab->char_map[x][b] = 'x';
	  b = b + 1;
	  s = s + 1;
	}
      a = a + 1;
      x = x + 1;
    }
  show_map(tab);
}

void	my_putstr2(char *str, t_tab *tab)
{
  write(1, str, tab->width);
}

void	show_map(t_tab *lst)
{
  int   k;

  k = 0;
  while (k < lst->line)
    {
      my_putstr2(lst->char_map[k], lst);
      my_putchar('\n');
      k = k + 1;
    }
}
