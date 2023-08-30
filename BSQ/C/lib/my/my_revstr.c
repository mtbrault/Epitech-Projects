/*
** my_revstr.c for  in /home/b00bix/delivery/CPool_Day06
**
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
**
** Started on  Mon Oct 10 16:34:40 2016 Matthieu BRAULT
** Last update Tue Oct 11 16:16:06 2016 Matthieu BRAULT
*/

#include <unistd.h>
#include <string.h>

char	*my_revstr(char *str)
{
  char	a;
  int	b;
  int	c;

  b = my_strlen(str) - 1;
  c = 0;
  while (c < b)
    {
      a = str[b];
      str[b] = str[c];
      str[c] = a;
      b = b - 1;
      c = c + 1;
    }
  return (str);
}
