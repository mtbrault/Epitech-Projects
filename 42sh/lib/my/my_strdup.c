/*
** my_strdup.c for  in /home/b00bix/PSU_2016_42sh/lib/my
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Wed Apr 12 20:32:46 2017 Matthieu BRAULT
** Last update Wed Apr 12 21:18:15 2017 Capitaine CASSE
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *str)
{
  int	s;
  char	*new;

  s = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[s] != '\0')
    {
      new[s] = str[s];
      s = s + 1;
    }
  new[s] = '\0';
  return (new);
}
