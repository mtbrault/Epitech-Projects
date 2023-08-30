/*
** my_strncat.c for  in /home/b00bix/delivery/For the librabry
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Tue Oct 11 18:14:52 2016 Matthieu BRAULT
** Last update Wed Oct 12 17:24:45 2016 Matthieu BRAULT
*/

#include <unistd.h>

char	*my_strncat(char *dest, char*src, int nb)
{
  int	x;
  int	y;

  x = 0;
  y = my_strlen(dest);

  while (src[x] != '\0' && x < nb)
    {
      dest[y] = src[x];
      x = x + 1;
      y = y + 1;
    }
  dest[y] = '\0';
  return (dest);
}
