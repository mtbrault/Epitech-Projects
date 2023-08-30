/*
** list_to_table.c for  in /home/b00bix/PSU_2016_42sh/src
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Wed Apr 12 17:51:34 2017 Matthieu BRAULT
** Last update Sun May 21 20:57:17 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

static int	get_list_size(t_list **env)
{
  t_list	*list;
  int		nb;

  nb = 0;
  list = *env;
  while (list != NULL)
    {
      list = list->next;
      nb = nb + 1;
    }
  return (nb);
}

char		**get_env_table(t_list **env)
{
  t_list	*list;
  char		**arr;
  int		max;
  int		nb;

  nb = 0;
  list = *env;
  max = get_list_size(env);
  if ((arr = malloc(sizeof(char *) * (max + 1))) == NULL)
    return (NULL);
  arr[max] = NULL;
  while (list != NULL && nb < max)
    {
      if ((arr[nb] = my_strdup(list->name)) == NULL
	  || (arr[nb] = my_strcat(arr[nb], "=")) == NULL
	  || (arr[nb] = my_strcat(arr[nb], list->val)) == NULL)
	return (NULL);
      nb = nb + 1;
      list = list->next;
    }
  return (arr);
}
