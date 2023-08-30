/*
** unsetenv.c for  in /home/george_t/rendu/PSU/PSU_2016_42sh/src
** 
** Made by Tom GEORGES
** Login   <george_t@epitech.net>
** 
** Started on  Wed Apr 12 15:32:12 2017 Tom GEORGES
** Last update Sun May 21 21:13:51 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

static void	my_delenv(char **commande, t_list **env, int i)
{
  t_list	*env_cpy;
  t_list	*tmp;

  env_cpy = *env;
  tmp = env_cpy;
  if (commande != NULL && i < my_tablen(commande) && env != NULL)
    {
      while (env_cpy != NULL && my_strcmp(env_cpy->name,
					  commande[i]))
	env_cpy = env_cpy->next;
      if (env_cpy == *env)
	*env = (*env)->next;
      else if (env_cpy != NULL)
	{
	  while (tmp->next != env_cpy)
	    tmp = tmp->next;
	  tmp->next = env_cpy->next;
	  my_free_env(env_cpy);
	}
    }
}

int	my_unsetenv(char **commande, t_list **env, int *fd)
{
  int	nb;

  nb = 1;
  fd = fd;
  if (*env == NULL || env[0] == NULL)
    return (0);
  if (commande == NULL || env == NULL || fd == NULL)
    return (SUCCESS);
  if (!commande[1])
    return (my_puterror(TOO_FEW, 1));
  while (commande[nb] != NULL)
    {
      my_delenv(commande, env, nb);
      nb = nb + 1;
    }
  return (SUCCESS);
}
