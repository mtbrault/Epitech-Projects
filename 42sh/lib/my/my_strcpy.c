/*
** my_strcpy.c for  in /home/george_t/rendu/POOL/CPool_Day07/lib/my
** 
** Made by Tom GEORGES
** Login   <george_t@epitech.net>
** 
** Started on  Tue Oct 11 11:16:09 2016 Tom GEORGES
** Last update Sun May 21 20:28:41 2017 Capitaine CASSE
*/

#include <stdlib.h>

void	my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  if (src == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
}
