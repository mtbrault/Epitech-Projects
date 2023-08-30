/*
** my_cd.c for  in /home/b00bix/PSU_2016_minishell1
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Fri Jan 20 12:41:52 2017 Matthieu BRAULT
** Last update Sun May 21 20:54:00 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "mysh.h"

static char	*my_cd_back(t_list **env, char *oldpwd)
{
  char		*pwd;
  t_list	*list;

  list = *env;
  while (list != NULL && my_strcmp(list->name, OLDPWD) != 0)
    list = list->next;
  pwd = NULL;
  pwd = getcwd(pwd, 0);
  if (list == NULL)
    chdir(oldpwd);
  else
    chdir(list->val);
  my_change_pwd(env);
  return (pwd);
}

static char	*my_cdd(struct stat *sb, char **argument, t_list **env)
{
  char	*pwd;

  pwd = NULL;
  if ((sb->st_mode & S_IFMT) != S_IFDIR)
    {
      my_puterror(argument[1], 0);
      my_puterror(NOT_A_DIR, 1);
      free(sb);
      return (NULL);
    }
  pwd = getcwd(pwd, 0);
  chdir(argument[1]);
  my_change_pwd(env);
  return (pwd);
}

static void	my_single_cd(t_list **env, char **oldpwd)
{
  t_list	*list;
  char		*pwd;

  pwd = NULL;
  list = *env;
  *oldpwd = getcwd(pwd, 0);
  while (list != NULL && my_strcmp(HOME, list->name) != SUCCESS)
    list = list->next;
  if (list != NULL)
    {
      chdir(list->val);
      my_change_pwd(env);
    }
}

static int	my_cd_error(char **argument, t_list **env, int *fd,
			    char **oldpwd)
{
  int		nb;

  nb = 0;
  if (argument == NULL || env == NULL)
    return (1);
  while (argument[nb] != NULL && argument[nb][0])
    nb = nb + 1;
  if (nb == 1)
    {
      my_single_cd(env, oldpwd);
      return (nb);
    }
  if (nb != 2)
    {
      my_puterror(CD_MANY_ARG, 0);
      return (1);
    }
  else if (my_strcmp(CD, argument[0]) != 0)
    {
      my_puterror(argument[0], 0);
      my_puterror(CMD_NF, 0);
      fd[2] = 1;
      return (1);
    }
  return (SUCCESS);
}

int		my_cd(char **argument, t_list **env, int *fd)
{
  struct stat	*sb;
  static char	*oldpwd;

  if (argument == NULL || env == NULL || fd == NULL)
    return (1);
  if ((sb = malloc(sizeof(*sb))) == NULL)
    exit(84);
  if (my_cd_error(argument, env, fd, &oldpwd) != 1)
    {
      if (my_strcmp("-", argument[1]) == SUCCESS)
	oldpwd = my_cd_back(env, oldpwd);
      else if ((stat(argument[1], sb)) == FAIL)
	return (put_error_fil(argument[1]));
      else
	if ((oldpwd = my_cdd(sb, argument, env)) == NULL)
	  return (fd[2] = 1);
      free(sb);
    }
  else
    {
      free(sb);
      return (fd[2] = 1);
    }
  return (SUCCESS);
}
