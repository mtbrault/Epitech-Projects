/*
** my_strcat.c for  in /home/b00bix/delivery/CPool_Day07
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Tue Oct 11 10:39:59 2016 Matthieu BRAULT
** Last update Tue May  2 19:35:28 2017 alexandre
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  char	*new;
  int	nb;
  int	num;

  nb = 0;
  num = 0;
  if ((new = malloc(sizeof(char) *
		    (my_strlen(dest) + my_strlen(src) + 1))) == NULL)
    return (NULL);
  while (dest != NULL && dest[nb] != '\0')
    {
      new[nb] = dest[nb];
      nb = nb + 1;
    }
  while (src != NULL && src[num] != '\0')
    {
      new[nb + num] = src[num];
      num = num + 1;
    }
  new[nb + num] = '\0';
  free(dest);
  return (new);
}
