/*
** my_arrdup.c for my_arrdup in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/lib/my
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Wed May  3 18:51:57 2017 alexandre
** Last update Mon May  8 18:31:58 2017 alexandre
*/

#include <stdlib.h>
#include "my.h"

static int	my_arrlen(char **tab)
{
  int		nb;

  nb = 0;
  while (tab != NULL && tab[nb] != NULL)
    nb = nb + 1;
  return (nb);
}

char	**my_arrdup(char **arr)
{
  char	**new;
  int	nb;

  nb = 0;
  if ((new = malloc(sizeof(char *) * (my_arrlen(arr) + 1))) == NULL)
    return (NULL);
  while (arr != NULL && arr[nb] != NULL)
    {
      new[nb] = my_strdup(arr[nb]);
      nb = nb + 1;
    }
  new[nb] = NULL;
  return (new);
}
