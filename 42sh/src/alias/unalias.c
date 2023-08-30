/*
** unalias.c for unalias in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Fri May 19 13:57:31 2017 alexandre
** Last update Sun May 21 20:52:36 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

static char	check_unalias(char **tab, t_alias **alias)
{
  int		nb;
  int		ind;

  nb = 0;
  while (tab != NULL && tab[nb] != NULL)
    {
      ind = 0;
      if (my_strcmp(tab[nb], UNALIAS) == SUCCESS && tab[nb + 1] != NULL)
	{
	  while (alias != NULL && alias[ind] != NULL
		 && my_strcmp(alias[ind]->name, tab[nb + 1]) != SUCCESS)
	    ind = ind + 1;
	  if (alias[ind] != NULL)
	    return (SUCCESS);
	}
      nb = nb + 1;
    }
  return (FAIL);
}

static int	size_after_unalias(t_alias **alias)
{
  int		nb;

  nb = 0;
  while (alias != NULL && alias[nb] != NULL)
    nb = nb + 1;
  nb = nb + 1;
  return (nb);
}

static int	find_unalias(char **tab, t_alias *alias)
{
  int		nb;

  nb = 0;
  while (tab != NULL && tab[nb] != NULL &&
	 my_strcmp(tab[nb], alias->name) != SUCCESS)
    nb = nb + 1;
  return (nb);
}

static t_alias	**unalias_it(char **tab, t_alias **alias,
			     const int size, int nb)
{
  t_alias	**new;
  int		num;
  int		ind;

  nb = 0;
  num = 0;
  if ((new = malloc(sizeof(*new) * size)) ==  NULL)
    return (NULL);
  while (alias != NULL && alias[nb] != NULL)
    {
      ind = find_unalias(tab, alias[nb]);
      if (my_strcmp(alias[nb]->name, tab[ind]) != SUCCESS)
	{
	  if ((new[num] = malloc(sizeof(t_alias))) == NULL
	      || (new[num]->name = my_strdup(alias[nb]->name)) == NULL
	      || (new[num]->command = my_strdup(alias[nb]->command)) == NULL)
	    return (NULL);
	  num = num + 1;
	}
      free_alias(alias[nb]);
      nb = nb + 1;
    }
  free(alias);
  new[num] = NULL;
  return (new);
}

char	**my_unalias(char **tab, t_alias ***alias)
{
  int	size;

  if (check_unalias(tab, *alias) == FAIL)
    return (tab);
  if ((size = size_after_unalias(*alias)) == 1)
    *alias = NULL;
  else
    *alias = unalias_it(tab, *alias, size, 0);
  if ((tab = remove_cmd(tab, UNALIAS)) == NULL)
    return (NULL);
  return (tab);
}
