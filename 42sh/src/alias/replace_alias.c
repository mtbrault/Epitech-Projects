/*
** replace_alias.c for replace_alias in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Mon May  8 17:27:26 2017 alexandre
** Last update Sun May 21 20:52:17 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

char	verif_alias(char *str, t_alias **alias)
{
  int	nb;
  int	ind;

  nb = 0;
  if (str == NULL || alias == NULL)
    return (FAIL);
  while (str[nb] != '\0')
    {
      ind = 0;
      while (alias != NULL && alias[ind] != NULL)
	{
	  if (my_strncmp(alias[ind]->name, &str[nb],
			 my_strlen(alias[ind]->name)) == SUCCESS)
	    return (SUCCESS);
	  ind = ind + 1;
	}
      while (str[nb] != '\0' && str[nb] != ' ')
	nb = nb + 1;
      if (str[nb] == ' ')
	nb = nb + 1;
    }
  return (FAIL);
}

static int	my_alias_is(char **tab, t_alias **alias)
{
  int		ind;
  char		**name;

  ind = 0;
  if (tab == NULL || alias == NULL)
    return (FAIL);
  while (alias != NULL && alias[ind] != NULL)
    {
      if ((name = my_str_to_wordtab(alias[ind]->name, ' ')) == NULL)
	return (FAIL);
      if (my_tabncmp(tab, name, my_tablen(name)) == SUCCESS)
	{
	  free_tab(name);
	  if (alias[ind] == NULL)
	    return (FAIL);
	  return (ind);
	}
      free_tab(name);
      ind = ind + 1;
    }
  return (FAIL);
}

static char	**replace_it(char **new, char *command,
			     const int size, int *num)
{
  char		**my_cmd;
  int		nb;

  nb = 0;
  if (new == NULL || command == NULL || num == NULL || *num > size ||
      (my_cmd = my_str_to_wordtab(command, ' ')) == NULL)
    return (NULL);
  while (my_cmd[nb] != NULL)
    {
      if ((new[*num] = my_strdup(my_cmd[nb])) == NULL)
	return (NULL);
      nb = nb + 1;
      *num = *num + 1;
    }
  new[*num] = NULL;
  free_tab(my_cmd);
  return (new);
}
char	**replace_alias_by_cmd(char **tab, t_alias **alias, const int len)
{
  char	**new;
  int	nb;
  int	num;
  int	ind;

  nb = 0;
  num = 0;
  if (tab == NULL || len <= 0 || (new = malloc(sizeof(char *) * len)) == NULL)
    return (NULL);
  while (tab[nb] != NULL)
    {
      if ((ind = my_alias_is(&tab[nb], alias)) == FAIL)
	{
	  if ((new[num] = my_strdup(tab[nb])) == NULL)
	    return (NULL);
	  num = num + 1;
	}
      else if ((new = replace_it(new, alias[ind]->command, len, &num)) == NULL)
	return (NULL);
      nb = nb + 1;
    }
  new[num] = NULL;
  free_tab(tab);
  return (new);
}
