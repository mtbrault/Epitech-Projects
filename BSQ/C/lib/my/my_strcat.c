/*
** my_strcat.c for  in /home/b00bix/delivery/CPool_Day07
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Tue Oct 11 10:39:59 2016 Matthieu BRAULT
** Last update Wed Oct 12 17:06:19 2016 Matthieu BRAULT
*/

#include <unistd.h>

char	*my_strcat(char *dest, char *src)
{
  int	a;
  int	b;

  a = 0;
  b = my_strlen(dest);
  while (src[a] != '\0')
    {
      dest[b] = src[a];
      a = a + 1;
      b = b + 1;
    }
  dest[b] = '\0';
  return (dest);
}
