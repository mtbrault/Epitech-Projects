/*
** error.c for  in /home/b00bix/delivery/CProgElem/CPE_2016_BSQ
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Wed Dec 14 14:42:34 2016 Matthieu BRAULT
** Last update Wed Dec 14 14:48:45 2016 Matthieu BRAULT
*/

#include "bsq.h"

void	check_first_line(char *str)
{
  int	s;
  int	y;

  s = 0;
  y = 0;
  while (str[s] != '\0')
    {
      if (str[s] == '\n')
	y = y + 1;
      s = s + 1;
    }
  if (y == 0)
    exit(84);
}
