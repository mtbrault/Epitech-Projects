/*
** my_path.c for  in /home/b00bix/PSU_2016_42sh/src
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Wed Apr 12 16:56:59 2017 Matthieu BRAULT
** Last update Sun May 21 20:56:17 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"

static char	*cat_cmd(char *path, char *str)
{
  char	*cmd;

  if ((cmd = my_strdup(path)) == NULL
      || (cmd = my_strcat(cmd, "/")) == NULL
      || (cmd = my_strcat(cmd, str)) == NULL)
    return (NULL);
  return (cmd);
}

static char	**find_path(t_list **env)
{
  char		**path;
  t_list	*list;

  list = *env;
  while (list != NULL && my_strcmp(list->name, PATH) != SUCCESS)
    list = list->next;
  if (list == NULL
      || (path = my_str_to_wordtab(list->val, ':')) == NULL)
    return (NULL);
  return (path);
}

void	free_some(char *cmd, char **path)
{
  free(cmd);
  free_tab(path);
}

int	my_path(char **argument, t_list **env, int *fd)
{
  char		**path;
  char		*cmd;
  int		nb;

  nb = 0;
  if ((path = find_path(env)) == NULL)
    return (SUCCESS);
  while (path != NULL && path[nb] != NULL && path[nb][0] != '\0')
    {
      if ((cmd = cat_cmd(path[nb], argument[0])) == NULL)
	return (SUCCESS);
      if (access(cmd, F_OK | X_OK) != FAIL)
	{
	  free_tab(path);
	  return (exec_prog(cmd, argument, env, fd));
	}
      else if (access(cmd, F_OK | !X_OK) == SUCCESS)
	{
	  free_some(cmd, path);
	  return (put_error_permission(argument[0]));
	}
      nb = nb + 1;
      free(cmd);
    }
  return (1);
}
