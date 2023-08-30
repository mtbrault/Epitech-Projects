/*
** my_strcpy.c for  in /home/b00bix/delivery/CPool_Day06
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Mon Oct 10 09:15:04 2016 Matthieu BRAULT
** Last update Tue Oct 11 16:23:57 2016 Matthieu BRAULT
*/

#include <unistd.h>

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = src[i];
  return (dest);
}
