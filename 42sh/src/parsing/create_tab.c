/*
** create_tab.c for create_tab in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue May  2 21:18:53 2017 alexandre
** Last update Sun May 21 20:58:45 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

static char	*parsing_loop_next(char *str, char *new, int *nb,
				   const int len)
{
  int		num;
  char		ch;

  num = 0;
  ch = ' ';
  if (str == NULL || *nb > my_strlen(str))
    return (NULL);
  if (str[*nb] == ' ')
    nb = nb + 1;
  if (str[*nb] == '"' || str[*nb] == 39)
    {
      ch = str[*nb];
      *nb = *nb + 1;
    }
  while (str[*nb] != '\0' && str[*nb] != ch && num != len)
    {
      new[num] = str[*nb];
      *nb = *nb + 1;
      num = num + 1;
    }
  if (str[*nb] != '\0' && (ch == '"' || ch == 39))
    *nb = *nb + 1;
  new[num] = '\0';
  return (new);
}

char		**parsing_cmd_loop(char *str, const int size)
{
  char		**new;
  int		pos;
  int		nb;
  int		len;

  pos = 0;
  nb = 0;
  if ((new = malloc(sizeof(char *) * size)) == NULL)
    return (NULL);
  while (str != NULL && str[nb] != '\0')
    {
      len = len_cmd(str, nb);
      if ((new[pos] = malloc(sizeof(char) * (len + 1))) == NULL)
	return (NULL);
      if ((new[pos] = parsing_loop_next(str, new[pos], &nb, len)) == NULL)
	return (NULL);
      if (str[nb] == ' ')
	nb = nb + 1;
      if (pos == size - 1)
	break ;
      pos = pos + 1;
    }
  new[pos] = NULL;
  return (new);
}

char	**create_tab(char *str, t_alias ***alias)
{
 char	**tab;
 int	size;

 if ((tab = parsing_cmd_loop(str, count_cmd(str) + 2)) == NULL
     || (tab = remove_spaces(tab)) == NULL
     || show_alias(tab, *alias) != SUCCESS
     || (tab = remove_cmd(tab, ALIAS)) == NULL
     || (tab = my_unalias(tab, alias)) == NULL)
   {
     free(str);
     return (NULL);
   }
 if (*alias != NULL && verif_alias(str, *alias) == SUCCESS
     && ((size = new_size(tab, *alias)) == ERROR
	 || (tab = replace_alias_by_cmd(tab, *alias, size)) == NULL))
   {
     free(str);
     return (NULL);
   }
 free(str);
 if ((tab = replace_exit(tab)) == NULL
     || (tab = parth_sep(tab)) == NULL)
   return (NULL);
 return (tab);
}
