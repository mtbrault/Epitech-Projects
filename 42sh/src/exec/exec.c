/*
** exec.c for PSU_2016_42sh in /home/antoine.casse/Desktop/PSU_2016_42sh/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Wed Apr 12 16:46:37 2017 Capitaine CASSE
** Last update Sun May 21 20:55:34 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include "mysh.h"

void	fd_management_two(int *fd, int mode)
{
  static int	stdout;

  if (fd != NULL)
    {
      if (mode && fd[1] != -1)
	{
	  stdout = dup(1);
	  dup2(fd[1], 1);
	}
      else if (!mode && fd[1] != -1)
	{
	  close(fd[1]);
	  dup2(stdout, 1);
	}
    }
}

static void	fd_management_one(int *fd, int mode)
{
  if (fd != NULL)
    {
      if (mode && fd[0] != -1)
	dup2(fd[0], 0);
      if (mode && fd[1] != -1)
	dup2(fd[1], 1);
      if (!mode && fd[1] != -1)
	close(fd[1]);
      if (!mode && fd[0] != -1)
	close(fd[0]);
    }
}

int	check_exec(int *st)
{
  if (st[2] == 8)
    st[2] = my_puterror(DIVZERO, 136);
  else if (st[2] == 11)
    st[2] = my_puterror(SEGFAULT, 139);
  else if (st[2] == 136)
    st[2] = my_puterror(DIVZERO_CORE, 136);
  else if (st[2] == 139)
    st[2] = my_puterror(SEGFAULT_CORE, 139);
  else if (st[2] != 0)
    st[2] = 1;
  return (SUCCESS);
}

static int	check_repo(char *str)
{
  struct stat	*sb;
  int		test;

  if ((sb = malloc(sizeof(*sb))) == NULL)
    return (1);
  if (stat(str, sb) != -1)
    {
      if ((sb->st_mode & S_IFMT) == S_IFDIR)
	{
	  my_puterror(str, 1);
	  free(sb);
	  return (my_puterror(NO_PERMISSION, 1));
	}
    }
  if ((test = access(str, F_OK | X_OK)) == -1)
    {
      free(sb);
      return (0);
    }
  free(sb);
  return (0);
}

int	exec_prog(char *path, char **arg, t_list **env, int *fd)
{
  char	**tab;

  if (path == NULL || arg == NULL || env == NULL || fd == NULL
      || (tab = get_env_table(env)) == NULL
      || (fd[2] = check_repo(path)) == 1)
    exit(1);
  fd_management_one(fd, 1);
  if (execve(path, arg, tab) < SUCCESS)
    {
      dprintf(2, "%s%s", arg[0], EXEC_ERR);
      exit(1);
    }
  fd_management_one(fd, 0);
  exit(SUCCESS);
  free_tab(tab);
  return (check_exec(fd));
}
