/*
** remove_spaces.c for remove_spaces in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue May 16 16:33:20 2017 alexandre
** Last update Sun May 21 20:59:47 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

static char	check_spaces(char **tab)
{
  int		nb;

  nb = 0;
  while (tab != NULL && tab[nb] != NULL)
    {
      if (tab[nb][0] == SPACES_T)
	return (SUCCESS);
      nb = nb + 1;
    }
  return (FAIL);
}

char	**my_new_tab(char **tab, const int size)
{
  char	**new;
  int	nb;
  int	cmd;

  cmd = 0;
  nb = 0;
  if ((new = malloc(sizeof(char *) * (size))) == NULL)
    return (NULL);
  while (tab != NULL && tab[nb] != NULL)
    {
      if (tab[nb][0] == SPACES_T)
	{
	  nb = nb + 1;
	  continue ;
	}
      if ((new[cmd] = my_strdup(tab[nb])) == NULL)
	return (NULL);
      cmd = cmd + 1;
      nb = nb + 1;
    }
  new[cmd] = NULL;
  return (new);
}

char	**remove_spaces(char **tab)
{
  char	**new;
  int	size;

  new = NULL;
  if (check_spaces(tab) == FAIL)
    return (tab);
  size = new_size_spaces(tab) + 1;
  if ((new = my_new_tab(tab, size)) == NULL)
    return (tab);
  free_tab(tab);
  return (new);
}
