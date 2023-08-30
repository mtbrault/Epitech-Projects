/*
** remove_cmd.c for remove_cmd in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Thu May 18 22:13:22 2017 alexandre
** Last update Sun May 21 20:59:41 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

static char	check_cmd_to_remove(char **tab, char *to_remove)
{
  int		nb;

  nb = 0;
  if (tab == NULL || to_remove == NULL)
    return (FAIL);
  while (tab[nb] != NULL)
    {
      if (my_strcmp(tab[nb], to_remove) == SUCCESS)
	return (SUCCESS);
      nb = nb + 1;
    }
  return (FAIL);
}

static int	size_without_cmd(char **tab, char *to_remove)
{
  int		size;
  int		nb;

  nb = 0;
  size = 0;
  if (tab == NULL || to_remove == NULL)
    return (size);
  while (tab[nb] != NULL)
    {
      if (my_strcmp(tab[nb], to_remove) == SUCCESS)
	{
	  while (tab[nb] != NULL && is_a_separator(tab[nb][0]) != SUCCESS)
	    nb = nb + 1;
	}
      size = size + 1;
      if (tab[nb] != NULL)
	nb = nb + 1;
    }
  return (size);
}

static char	remove_the_cmd_next(char **tab, char ***new, int *num, int *nb)
{
  if (tab == NULL || num == NULL || nb == NULL || *nb > my_tablen(tab))
    return (ERROR);
  if (((*new)[*num] = my_strdup(";")) == NULL)
    return (ERROR);
  *num = *num + 1;
  while (tab[*nb] != NULL && is_a_separator(tab[*nb][0]) != SUCCESS)
    *nb = *nb + 1;
  return (SUCCESS);
}

static char	**remove_the_cmd(char **tab, char *to_remove, const int size)
{
  char		**new;
  int		nb;
  int		num;

  nb = 0;
  num = 0;
  if (tab == NULL || to_remove == NULL || size <= 0
      || (new = malloc(sizeof(char *) * size)) == NULL)
    return (NULL);
  while (tab[nb] != NULL)
    {
      if (my_strcmp(tab[nb], to_remove) != SUCCESS)
	{
	  if ((new[num] = my_strdup(tab[nb])) == NULL)
            return (NULL);
          num = num + 1;
	}
      else if (remove_the_cmd_next(tab, &new, &num, &nb) == ERROR)
	return (NULL);
      if (tab[nb] != NULL)
	nb = nb + 1;
    }
  new[num] = NULL;
  return (new);
}

char	**remove_cmd(char **tab, char *to_remove)
{
  char	**new;
  int	size;

  if (check_cmd_to_remove(tab, to_remove) == FAIL)
    return (tab);
  size = size_without_cmd(tab, to_remove) + 1;
  if ((new = remove_the_cmd(tab, to_remove, size)) == NULL)
    {
      free_tab(tab);
      return (NULL);
    }
  free_tab(tab);
  return (new);
}
