/*
** my_putstr.c for  in /home/b00bix/delivery/CPool_Day04
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Thu Oct  6 21:33:46 2016 Matthieu BRAULT
** Last update Fri Oct  7 14:12:21 2016 Matthieu BRAULT
*/

#include <unistd.h>

int	my_putstr(char *str)
{
  int	s;

  s = 0;
  while (str[s] != '\0')
    {
      my_putchar(str[s]);
      s = s + 1;
    }
  return (0);
}
