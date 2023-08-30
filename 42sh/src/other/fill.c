/*
** fill.c for  in /home/BlackBIrdz/PSU_2016_42sh/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Wed Apr 12 20:06:17 2017 LAABID Zakaria
** Last update Sun May 21 20:57:03 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

int		list_elem_add(t_list **list, char *name, char *value)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (FAIL);
  elem->name = name;
  elem->val = value;
  elem->next = *list;
  *list = elem;
  (*list)->next = NULL;
  return (SUCCESS);
}

int	strlen_env(char *name)
{
  int	nb;

  nb = 0;
  if (name == NULL)
    return (FAIL);
  while (name[nb] != '\0' && name[nb] != '=')
    nb++;
  if (name[nb] == '\0')
    return (FAIL);
  return (nb);
}

char	*copy_var(char *env, char *str, int mode)
{
  int	nb;

  nb = 0;
  if (mode == 1)
    {
      while (env != NULL && env[nb] != '\0' && env[nb] != '=')
	{
	  str[nb] = env[nb];
	  nb = nb + 1;
	}
    }
  else
    {
      while (env != NULL && env[nb] != '\0' && env[nb] != '=')
	nb++;
      nb++;
      while (env != NULL && env[nb] != '\0')
	{
	  str[nb] = env[nb];
	  nb = nb + 1;
	}
    }
  str[nb] = '\0';
  return (str);
}

t_list		*list_fill(char **env)
{
  t_size	pos;
  t_list	*start;
  t_list	*pars;

  pos.y = 1;
  if ((start = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  pars = start;
  while (env != NULL && env[pos.y] != NULL && !(pos.x = 0))
    {
      while (env[pos.y][pos.x] != '\0' && env[pos.y][pos.x] != '=')
	pos.x += 1;
      env[pos.y][pos.x] = 0;
      if ((pars->name = my_strdup(env[pos.y])) == NULL
	  || (pars->val = my_strdup(env[pos.y] + pos.x + 1)) == NULL)
	return (NULL);
      if (env[1 + pos.y++] != NULL)
        {
          if ((pars->next = malloc(sizeof(t_list))) == NULL)
            return (NULL);
          pars = pars->next;
        }
    }
  pars->next = NULL;
  return (start);
}
