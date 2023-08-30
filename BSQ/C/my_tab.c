/*
** my_tab.c for  in /home/b00bix/delivery/CProgElem/CPE_2016_BSQ
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Mon Dec 12 14:53:00 2016 Matthieu BRAULT
** Last update Tue Dec 13 23:24:44 2016 Matthieu BRAULT
*/

#include "bsq.h"

void	create_char_tab(char *str, t_tab *map)
{
  int	s;

  s = 0;
  map->width = get_width(str);
  map->line = get_line(str);
  if ((map->char_map = malloc(sizeof(char *) * (map->line + 1))) == NULL)
    exit(84);
  while (s <= map->line)
    {
      if ((map->char_map[s] = malloc(sizeof(char) * map->width + 1)) == NULL)
	exit(84);
      s = s + 1;
    }
}

void	create_int_tab(char *str, t_tab *map)
{
  int	s;

  s = 0;
  map->width = get_width(str);
  map->line = get_line(str);
  if ((map->int_map = malloc(sizeof(int *) * (map->line + 1))) == NULL)
    exit(84);
  while (s <= map->line)
    {
      if ((map->int_map[s] = malloc(sizeof(int) * map->width + 4)) == NULL)
	exit(84);
      s = s + 1;
    }
}

void	fill_char_tab(char *str, t_tab *tab)
{
  int	s;
  int	x;
  int	y;

  create_char_tab(str, tab);
  s = 0;
  y = 0;
  while (str[y] != '\n')
    y = y + 1;
  y = y + 1;
  while (s < tab->line)
    {
      x = 0;
      while (x <= tab->width)
	{
	  tab->char_map[s][x] = str[y];
	  x = x + 1;
	  y = y + 1;
	}
      s = s + 1;
    }
}

void	fill_int_tab(char *str, t_tab *tab)
{
  int	s;
  int	x;
  int	y;

  create_int_tab(str, tab);
  s = 0;
  y = 0;
  while (str[y] != '\n')
    y = y + 1;
  y = y + 1;
  while (s < tab->line)
    {
      x = 0;
      while (x <= tab->width)
	{
	  if (str[y] == '.')
	    tab->int_map[s][x] = 1;
	  if (str[y] == 'o')
	    tab->int_map[s][x] = 0;
	  x = x + 1;
	  y = y + 1;
	}
      s = s + 1;
    }
}
