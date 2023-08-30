/*
** free.c for 42sh in /home/antoine.casse/Desktop/PSU_2016_42sh/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sat Apr 22 17:49:53 2017 Capitaine CASSE
** Last update Sun May 21 20:57:10 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

void	free_tab(char **tab)
{
  int	nb;

  nb = 0;
  while (tab != NULL && tab[nb] != NULL)
    {
      free(tab[nb]);
      nb += 1;
    }
  free(tab);
}

void		free_env(t_list *env)
{
  t_list	*tmp;

  while (env != NULL)
    {
      tmp = env;
      env = env->next;
      if (tmp->name != NULL)
	free(tmp->name);
      if (tmp->val != NULL)
	free(tmp->val);
      free(tmp);
    }
}

void		free_list(t_list *list)
{
  t_list	*tmp;

  if (list != NULL)
    {
      list = list->next;
      while (list != NULL)
	{
	  free(list->name);
	  free(list->val);
	  tmp = list;
	  list = list->next;
	  free(tmp);
	}
    }
}

void	my_free_env(t_list *env)
{
  if (env->name != NULL)
    free(env->name);
  if (env->val != NULL)
    free(env->val);
  if (env != NULL)
    free(env);
}

void	free_alias(t_alias *alias)
{
  free(alias->name);
  free(alias->command);
  free(alias);
}
