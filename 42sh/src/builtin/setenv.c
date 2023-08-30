/*
** setenv.c for  in /home/b00bix/PSU_2016_42sh/src
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Wed Apr 12 20:03:28 2017 Matthieu BRAULT
** Last update Sun May 21 20:54:13 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

static int	my_check_alphanum(char *str)
{
  int		nb;

  nb = 0;
  while (str != NULL && str[nb] != '\0')
    {
      if (str[nb] < '0' || (str[nb] > '9' && str[nb] < 'A')
	  || (str[nb] > 'Z' && str[nb] < 'a') || str[nb] > 'z')
	return (my_puterror(ALPHA, 1));
      nb = nb + 1;
    }
  return (SUCCESS);
}

static void	modif_env(char **argument, t_list **env)
{
  t_list	*list;

  list = *env;
  while (list != NULL && my_strcmp(list->name, argument[1]) != 0)
    list = list->next;
  if (list != NULL && (list->name = my_strdup(argument[1])) != NULL)
    {
      if (argument[2] != NULL)
	list->val = my_strdup(argument[2]);
      else
	list->val = NULL;
    }
}

static void	setenv_next(char **argument, t_list **env)
{
  t_list	*list;

  list = *env;
  while (list != NULL && my_strcmp(list->name, argument[1]) != SUCCESS)
    list = list->next;
  if (list == NULL)
    {
      list = *env;
      while (list->next != NULL)
	list = list->next;
      if ((list->next = malloc(sizeof(t_list))) != NULL &&
	  (list->next->name = my_strdup(argument[1])) != NULL)
	{
	  list = list->next;
	  if (argument[2] == NULL)
	    list->val = NULL;
	  else if (argument[2] != NULL)
	    list->val = my_strdup(argument[2]);
	  list->next = NULL;
	}
    }
  else
    modif_env(argument, env);
}

static void	create_env(char **argument, t_list **env)
{
  t_list	*list;

  if ((list = malloc(sizeof(t_list))) != NULL)
    {
      list->next = NULL;
      if ((list->name = my_strdup(argument[1])) != NULL)
	{
	  if (argument[2] == NULL)
	    list->val = NULL;
	  else
	    list->val = my_strdup(argument[2]);
	  *env = list;
	}
    }
}

int	my_setenv(char **argument, t_list **env, int *fd)
{
  int	nb;

  nb = 0;
  while (argument != NULL && argument[nb] != NULL)
    nb = nb + 1;
  if (nb > 3)
    return (fd[2] = my_puterror(MANY_ARG, 1));
  else if (argument[1] == NULL)
    return (my_env(argument, env, fd));
  if (my_check_alphanum(argument[1]) == 1)
    return (fd[2] = 1);
  if (*env == NULL)
    create_env(argument, env);
  else
    setenv_next(argument, env);
  return (0);
}
