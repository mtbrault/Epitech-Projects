/*
** parth_sep.c for parth_sep in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue May 16 14:35:52 2017 alexandre
** Last update Sun May 21 20:59:35 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

static char	verif_sep_order(char **tab, const char ch)
{
  int		nb;

  nb = 0;
  while (tab != NULL && tab[nb] != NULL)
    {
      if (is_a_separator(tab[nb][0]) == SUCCESS && tab[nb + 1] != NULL
	  && is_a_separator(tab[nb + 1][0]) == SUCCESS
	  && my_sep_is(tab[nb][0]) == ch
	  && my_strcmp(tab[nb], tab[nb + 1]) == SUCCESS)
	return (FAIL);
      nb = nb + 1;
    }
  return (SUCCESS);
}

static char	**remove_useless_sep(char **tab, const int size, const char ch)
{
  char		**new;
  int		num;
  int		nb;

  num = 0;
  nb = 0;
  if (tab == NULL || (new = malloc(sizeof(char *) * size)) == NULL)
    return (NULL);
  while (tab[nb] != NULL)
    {
      if ((new[num] = my_strdup(tab[nb])) == NULL)
	return (NULL);
      while (tab[nb] != NULL
             && is_a_separator(tab[nb][0]) == SUCCESS
             && tab[nb + 1] != NULL
             && is_a_separator(tab[nb + 1][0]) == SUCCESS
	     && my_strcmp(tab[nb], tab[nb + 1]) == SUCCESS
	     && my_sep_is(tab[nb][0]) == ch)
	nb = nb + 1;
      num = num + 1;
      if (tab[nb] != NULL)
	nb = nb + 1;
    }
  new[num] = NULL;
  return (new);
}

char	**parth_sep(char **tab)
{
  char	**new;
  int	size;

  new = NULL;
  if (verif_sep_order(tab, ';') == SUCCESS)
    return (tab);
  size = new_size_sep(tab) + 1;
  if ((new = remove_useless_sep(tab, size, ';')) == NULL)
    return (tab);
  free_tab(tab);
  return (new);
}
