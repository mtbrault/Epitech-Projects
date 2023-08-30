/*
** my_cd2.c for  in /home/b00bix/PSU_2016_minishell2
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Thu Apr  6 16:09:46 2017 Matthieu BRAULT
** Last update Sun May 21 20:53:16 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "mysh.h"

char		*my_oldpwd(t_list **env)
{
  t_list	*list;

  list = *env;
  while (list != NULL && my_strcmp(list->name, PWD) != 0)
    list = list->next;
  if (list == NULL)
    return (NULL);
  return (list->val);
}

void		my_change_pwd(t_list **env)
{
  t_list	*list;

  list = *env;
  while (list != NULL && my_strcmp(list->name, OLDPWD) != 0)
    list = list->next;
  if (list != NULL)
    {
      free(list->val);
      list->val = my_oldpwd(env);
    }
  list = *env;
  while (list != NULL && my_strcmp(list->name, PWD) != 0)
    list = list->next;
  if (list != NULL)
    {
      list->val = NULL;
      list->val = getcwd(list->val, 0);
    }
}
