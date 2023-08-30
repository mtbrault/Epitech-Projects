/*
** env.c for  in /home/george_t/rendu/PSU/PSU_2016_42sh/src
** 
** Made by Tom GEORGES
** Login   <george_t@epitech.net>
** 
** Started on  Wed Apr 12 17:48:25 2017 Tom GEORGES
** Last update Sun May 21 20:53:27 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"

static char	prep_cmd_add(int i, char **cmd, char **new)
{
  if (i > 0)
    {
      new[2] = my_strdup(cmd[1] + i + 1);
      new[3] = NULL;
    }
  else
    return (FAIL);
  return (SUCCESS);
}

static char	**prep_cmd(char **cmd)
{
  int		i;
  int		j;
  char		**new;

  i = 0;
  while (cmd != NULL && cmd[1][i] && cmd[1][i] != '=')
    i += 1;
  j = 0;
  while (cmd[j] != NULL)
    j += 1;
  if ((new = malloc(sizeof(char *) * (cmd[1][i] ? j + 2 : j + 1))) == NULL)
    return (NULL);
  j = 0;
  if (cmd[1][i])
    cmd[1][i] = 0;
  else
    i = -1;
  if ((new[0] = my_strdup(cmd[0])) == NULL ||
      (new[1] = my_strdup(cmd[1])) == NULL ||
      prep_cmd_add(i, cmd, new))
    return (NULL);
  return (new);
}

static char	print_env(t_list *tmp)
{
  while (tmp != NULL)
    {
      if (tmp->name != NULL)
	my_putstr(tmp->name);
      my_putchar('=');
      if (tmp->val != NULL)
	my_putstr(tmp->val);
      my_putchar('\n');
      tmp = tmp->next;
    }
  return (0);
}

int		my_env(char **commande, t_list **env, int *fd)
{
  t_list	*tmp;

  if (commande == NULL)
    return (1);
  tmp = *env;
  if (commande[1] != NULL)
    {
      if ((commande = prep_cmd(commande)) == NULL)
	{
	  free_tab(commande);
	  return (ERROR);
	}
      my_setenv(commande, env, fd);
      free_tab(commande);
    }
  fd_management_two(fd, 1);
  print_env(tmp);
  fd_management_two(fd, 0);
  return (SUCCESS);
}
