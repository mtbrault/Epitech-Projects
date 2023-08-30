/*
** separate.c for PSU_2016_42sh in /home/antoine.casse/Desktop/42
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Thu May 18 14:51:47 2017 Capitaine CASSE
** Last update Sun May 21 21:00:54 2017 Matthieu BRAULT
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "mysh.h"

t_sep   g_separs[TAB_P] =
  {
    {";", &semi_colon},
    {"|", &pipe_it},
    {">", &dir_to},
    {">>", &dir_to_append},
    {"<", &dir_from},
    {"<<", &dir_from_tmp},
    {"&&", &andand},
    {"||", &oror},
    {"&", &jobs_control},
  };

int		find_next(char **arr, int *i)
{
  int		nb;

  nb = 10;
  while (arr[*i] != NULL)
    {
      nb = 0;
      while (nb < TAB_P)
	{
	  if (!my_strcmp(arr[*i], g_separs[nb].cmd))
	    return (nb);
	  nb += 1;
	}
      *i += 1;
    }
  return (nb);
}

static t_cmd	*build_list(char **arr, int f, t_cmd *list)
{
  int		i[2];
  t_cmd		*pars;

  i[0] = 0;
  i[1] = i[0];
  pars = NULL;
  while (arr[i[0]] != NULL)
    {
      f = find_next(arr, i + 1);
      if (pars == NULL)
	{
	  if ((list = malloc(sizeof(t_cmd))) == NULL)
	    return (NULL);
	  pars = list;
	}
      else if ((pars->next = malloc(sizeof(t_cmd))) != NULL)
	pars = pars->next;
      else
	return (NULL);
      pars->cmd = arr + i[0];
      pars->mode = f;
      pars->next = NULL;
      i[0] = arr[i[1]] != NULL ? ++i[1] : i[1];
    }
  return (list);
}

int		separate(char **arr, t_list **env, int *ret)
{
  t_cmd		*list;
  int		give[3];
  t_cmd		*old;

  list = NULL;
  if ((list = build_list(arr, 0, NULL)) == NULL)
    return (1);
  give[0] = -1;
  give[1] = -1;
  while (list != NULL)
    {
      old = list;
      if (list->mode < TAB_P)
 	g_separs[(int)list->mode].p(&list, env, ret);
      else if (list != NULL)
	{
	  give[2] = *ret;
	  input_man(list->cmd, env, give, 1);
	  *ret = give[2];
	}
      list = list->next;
      free(old);
    }
  return (0);
}
