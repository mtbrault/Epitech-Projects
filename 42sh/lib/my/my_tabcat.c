/*
** my_tabcat.c for my_tabcat in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/lib/my
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Wed May 17 16:19:28 2017 alexandre
** Last update Sun May 21 19:26:56 2017 alexandre
*/

#include <stdlib.h>
#include "my.h"

char	**my_tabcat(char **tab, char *str)
{
  char	**new;
  int	nb;

  nb = 0;
  if ((new = malloc(sizeof(char *) * (my_tablen(tab) + 2))) == NULL)
    return (NULL);
  while (tab != NULL && tab[nb] != NULL)
    {
      if (tab[nb][0] != '\0')
	if ((new[nb] = my_strdup(tab[nb])) == NULL)
	  return (NULL);
      free(tab[nb]);
      nb = nb + 1;
    }
  free(tab);
  if ((new[nb] = my_strdup(str)) == NULL)
    new[nb] = NULL;
  new[nb + 1] = NULL;
  return (new);
}
