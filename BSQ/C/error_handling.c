/*
** error_handling.c for  in /home/b00bix/delivery/CProgElem/CPE_2016_BSQ
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Thu Dec  8 14:31:42 2016 Matthieu BRAULT
** Last update Fri Dec 16 11:13:15 2016 Matthieu BRAULT
*/

#include "bsq.h"

void	check_character(char *buff)
{
  int	s;

  s = 0;
  while (buff[s] != '\n')
    s = s + 1;
  while (buff[s] != '\0')
    {
      if (buff[s] != 'o' && buff[s] != '.' && buff[s] != '\n')
	{
	  my_puterror("Invalid character in the files\n");
	  exit (84);
	}
      s = s + 1;
    }
}

void	check_line(char *str)
{
  int	x;
  int	y;
  int	s;

  x = get_line(str);
  s = 0;
  y = 0;
  while (str[s] != '\0')
    {
      if (str[s] == '\n')
	y = y + 1;
      s = s + 1;
    }
  y = y - 1;
  if (x != y)
    {
      my_puterror("Invalid number of lines\n");
      exit(84);
    }
}

int	get_line(char *str)
{
  char	*nb;
  int	s;
  int	x;

  check_first_line(str);
  if ((nb = malloc(sizeof(char) * my_strlen2(str) + 1)) == NULL)
    exit(84);
  s = 0;
  while (str[s] != '\n')
    {
      nb[s] = str[s];
      s = s + 1;
    }
  nb[s] = '\0';
  x = my_atoi(nb);
  free(nb);
  if (x == 0)
    exit(84);
  return (x);
}

int	get_width(char *str)
{
  int	s;
  int	x;

  s = 0;
  x = 0;
  while (str[s] != '\n')
    s = s + 1;
  s = s + 1;
  while (str[s] != '\n')
    {
      s = s + 1;
      x = x + 1;
    }
  return (x);
}

void	error_handling(char *str)
{
  check_line(str);
  check_character(str);
}
