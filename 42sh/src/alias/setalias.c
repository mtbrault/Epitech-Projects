/*
** setalias.c for setalias in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Sat May 20 19:13:59 2017 alexandre
** Last update Sun May 21 20:52:23 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

static char	*tab_to_str_with_sep(char **tab, char *sep)
{
  char		*new;
  int		nb;

  nb = 0;
  new = NULL;
  while (tab != NULL && tab[nb] != NULL)
    {
      if ((new = my_strcat(new, tab[nb])) == NULL)
	return (NULL);
      if (tab[nb + 1] != NULL && (new = my_strcat(new, sep)) == NULL)
	return (NULL);
      nb = nb + 1;
    }
  return (new);
}

char	setalias(char **tab, t_alias ***alias)
{
  char	*str;

  if (tab == NULL || (str = tab_to_str_with_sep(tab, " ")) == NULL)
    return (ERROR);
  if (my_alias(str, alias) == NULL)
    return (ERROR);
  free(str);
  return (SUCCESS);
}
