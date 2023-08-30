/*
** my_alias_create.c for my_alias_create in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Wed May  3 20:48:34 2017 alexandre
** Last update Sun May 21 20:52:37 2017 Matthieu BRAULT
*/

#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

static int	alias_len(char *str, const char ch)
{
  int	nb;

  nb = 0;
  while (str != NULL && str[nb] != '\0' && str[nb] != ch)
    nb = nb + 1;
  return (nb);
}

static char	*my_alias_name(char *str, const int pos, const char limit)
{
  char		ch;
  int		nb;
  int		count;
  char		*new;

  nb = pos;
  count = 0;
  if (str == NULL || nb > my_strlen(str))
    return (NULL);
  if (str[nb] == '"')
    {
      ch = '"';
      nb = nb + 1;
    }
  else
    ch = limit;
  if ((new = malloc(sizeof(char) * (alias_len(&str[nb], ch) + 1))) == NULL)
    return (NULL);
  while (str[nb + count] != '\0' && str[nb + count] != ch)
    {
      new[count] = str[nb + count];
      count = count + 1;
    }
  new[count] = '\0';
  return (new);
}

t_alias		*add_alias(char *str, const int pos)
{
  t_alias	*new;
  int		nb;
  char		ch;

  nb = pos;
  if (str == NULL || pos > my_strlen(str))
    return (NULL);
  if ((new = malloc(sizeof(t_alias))) == NULL
      || (new->name = my_alias_name(str, pos, ' ')) == NULL)
    return (NULL);
  if (str[nb] == '"')
    {
      ch = str[nb];
      nb = nb + 1;
    }
  else
    ch = ' ';
  while (str[nb] != '\0' && str[nb] != ch)
    nb = nb + 1;
  if (str[nb] == '"' && str[nb + 1] == ' ')
    nb = nb + 2;
  if ((new->command = my_alias_name(str, nb + 1, ';')) == NULL)
    return (NULL);
  return (new);
}

t_alias		**my_add_alias(char *str, const int pos, t_alias **alias)
{
  t_alias	**new;
  int		nb;

  nb = 0;
  while (alias != NULL && alias[nb] != NULL)
    nb = nb + 1;
  if ((new = malloc(sizeof(t_alias *) * (nb + 3))) == NULL)
    return (NULL);
  nb = 0;
  while (alias != NULL && alias[nb] != NULL)
    {
      if ((new[nb] = malloc(sizeof(t_alias))) == NULL
          || (new[nb]->name = my_strdup(alias[nb]->name)) == NULL
          || (new[nb]->command = my_strdup(alias[nb]->command)) == NULL)
        return (NULL);
      free(alias[nb]->name);
      free(alias[nb]->command);
      free(alias[nb]);
      nb = nb + 1;
    }
  free(alias);
  if ((new[nb] = add_alias(str, pos)) == NULL)
    return (NULL);
  new[nb + 1]  = NULL;
  return (new);
}
