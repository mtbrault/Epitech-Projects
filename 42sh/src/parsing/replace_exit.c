/*
** replace_exit.c for replace_exit in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Wed May 10 12:35:31 2017 alexandre
** Last update Sun May 21 20:59:53 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

static char	verif_exit(char **tab)
{
  int		nb;

  nb = 0;
  while (tab != NULL && tab[nb] != NULL)
    {
      if (my_strcmp(tab[nb], EXIT_S) == SUCCESS)
	return (SUCCESS);
      nb = nb + 1;
    }
  return (FAIL);
}

static char	**replace_this_exit(char **tab, const int size,
				    int nb, int cmd)
{
  char		**new;

  if ((new = malloc(sizeof(char *) * size)) == NULL)
    return (NULL);
  while (tab != NULL && tab[nb] != NULL)
    {
      if (my_strcmp(tab[nb], EXIT_S) == SUCCESS ||
	  (tab[nb + 1] != NULL && my_strcmp(tab[nb + 1], EXIT_S) == SUCCESS))
	{
	  nb = nb + 1;
	  while (tab[nb] != NULL && is_a_separator(tab[nb][0]) != SUCCESS)
	    nb = nb + 1;
	  if (tab[nb] != NULL && (tab[nb] = my_strdup(";")) == NULL)
	    return (NULL);
	}
      if (tab[nb] == NULL)
	break ;
      if ((new[cmd] = my_strdup(tab[nb])) == NULL)
	return (NULL);
      cmd = cmd + 1;
      nb = nb + 1;
    }
  new[cmd] = NULL;
  return (new);
}

static char	*exit_arg(char **tab)
{
  int		nb;
  char		*arg;

  nb = 0;
  arg = NULL;
  while (tab != NULL && tab[nb] != NULL)
    {
      if (my_strcmp(tab[nb], EXIT_S) == SUCCESS)
	{
	  if (tab[nb + 1] != NULL && is_a_separator(tab[nb + 1][0]) != SUCCESS
	      && tab[nb + 2] != NULL && tab[nb + 2][0] == ';')
	    {
	      if ((arg = my_strdup(tab[nb + 1])) == NULL)
		return (NULL);
	    }
	  else if (tab[nb + 1] != NULL
		   && is_a_separator(tab[nb + 1][0]) != SUCCESS
		   && tab[nb + 2] != NULL && tab[nb + 2][0] == '|')
	    if ((arg = my_strdup("1")) == NULL)
	      return (NULL);
	}
      nb = nb + 1;
    }
  return (arg);
}

char	**replace_exit(char **tab)
{
  int	nb;
  int	size;
  char	**new;
  char	*arg;

  nb = 0;
  if (verif_exit(tab) == FAIL || my_tablen(tab) == 1 || my_tablen(tab) == 2)
    return (tab);
  arg = exit_arg(tab);
  size = new_size_with_exit(tab) + 2;
  if ((new = replace_this_exit(tab, size, 0, 0)) == NULL)
    return (NULL);
  while (new[nb] != NULL && (nb = nb + 1));
  if ((new[nb] = my_strdup(";")) == NULL
      || (new[nb + 1] = my_strdup(EXIT_S)) == NULL)
    return (NULL);
  if (arg != NULL)
    {
      new[nb + 2] = arg;
      new[nb + 3] = NULL;
    }
  else
    new[nb + 2] = NULL;
  free_tab(tab);
  return (new);
}
