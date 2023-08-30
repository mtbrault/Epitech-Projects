/*
** my_alias.c for my_alias in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Mon Apr 24 20:03:06 2017 alexandre
** Last update Sun May 21 20:52:08 2017 Matthieu BRAULT
*/

#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

static char	alias_exist(char *str, const int pos, t_alias ***alias)
{
  int		nb;

  nb = 0;
  if (str == NULL || pos > my_strlen(str) || alias == NULL)
    return (ERROR);
  while (*alias != NULL && (*alias)[nb] != NULL)
    {
      if (my_strncmp(&str[pos], (*alias)[nb]->name,
		     my_strlen((*alias)[nb]->name)) == SUCCESS)
	{
	  free((*alias)[nb]);
	  if (((*alias)[nb] = add_alias(str, pos)) != NULL)
	    return (SUCCESS);
	}
      nb = nb + 1;
    }
  return (FAIL);
}

static char	create_alias(char *str, const int pos, t_alias ***alias)
{
  int		nb;
  char		ret;

  nb = pos;
  if (str == NULL || pos > my_strlen(str) || alias == NULL)
    return (ERROR);
  while (str[nb] != '\0' && str[nb] != ' ')
    nb = nb + 1;
  if (str[nb] != ' ')
    return (FAIL);
  nb = nb + 1;
  if (*alias != NULL)
    if ((ret = alias_exist(str, nb, alias)) == ERROR || ret == SUCCESS)
      return (ret);
  if ((*alias = my_add_alias(str, nb, *alias)) == NULL)
    return (FAIL);
  return (SUCCESS);
}

char	*my_alias(char *str, t_alias ***alias)
{
  int	nb;

  nb = 0;
  while (str != NULL && str[nb] != '\0')
    {
      if (my_strncmp(ALIAS, &str[nb], my_strlen(ALIAS)) == SUCCESS
	  && create_alias(str, nb, alias) == ERROR)
	return (NULL);
      while (str[nb] != '\0' && str[nb] != ' ')
	nb = nb + 1;
      if (str[nb] == ' ')
	nb = nb + 1;
    }
  return (str);
}
