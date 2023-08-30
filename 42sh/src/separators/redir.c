/*
** redir.c for PSU_2016_42sh in /home/antoine.casse/Desktop/42/PSU_2016_42sh/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Fri May 19 19:09:39 2017 Capitaine CASSE
** Last update Sun May 21 21:00:28 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "mysh.h"

static char	dir_loop(char **tab, const int *pipefd, const int e)
{
  char		*gnl;

  gnl = NULL;
  while ((gnl = get_next_line(0)) != NULL &&
	 my_strcmp(gnl, tab[e + 1]))
    {
      write(1, "> ", 2);
      write(pipefd[1], gnl, my_strlen(gnl));
      free(gnl);
      write(pipefd[1], "\n", 1);
    }
  return (0);
}

int	dir_from_tmp(t_cmd **act, t_list **env, int *ret)
{
  int	pipefd[2];
  int	give[3];
  char	*tmp;
  int	e;

  e = 0;
  if (pipe(pipefd) < 0)
    return (1);
  find_next((*act)->cmd, &e);
  tmp = (*act)->cmd[e];
  (*act)->cmd[e] = NULL;
  write(1, "> ", 2);
  dir_loop((*act)->cmd, pipefd, e);
  close(pipefd[1]);
  give[0] = pipefd[0];
  give[1] = -1;
  input_man((*act)->cmd, env, give, 1);
  *ret = give[2];
  (*act)->cmd[e] = tmp;
  *act = (*act)->next;
  return (0);
}

int	dir_from(t_cmd **act, t_list **env, int *ret)
{
  int	give[3];
  int	fd;
  int	e;
  char	*tmp;

  e = 0;
  find_next((*act)->cmd, &e);
  tmp = (*act)->cmd[e];
  (*act)->cmd[e] = NULL;
  if ((fd = open((*act)->cmd[e + 1], O_RDONLY)) < 0)
    {
      *ret = 1;
      return (1);
    }
  give[0] = fd;
  give[1] = -1;
  give[2] = *ret;
  input_man((*act)->cmd, env, give, 1);
  *ret = give[2];
  (*act)->cmd[e] = tmp;
  *act = (*act)->next;
  close(fd);
  return (0);
}

int	dir_to_append(t_cmd **act, t_list **env, int *ret)
{
  int	e;
  int	fd;
  int	give[3];
  char	*tmp;

  e = 0;
  find_next((*act)->cmd, &e);
  tmp = (*act)->cmd[e];
  (*act)->cmd[e] = NULL;
  give[0] = -1;
  if ((fd = open((*act)->cmd[e + 1], O_WRONLY | O_CREAT | O_APPEND, RIGHTS))
      < 0)
    {
      *ret = 1;
      return (1);
    }
  give[1] = fd;
  input_man((*act)->cmd, env, give, 1);
  *ret = give[2];
  (*act)->cmd[e] = tmp;
  close(fd);
  *act = (*act)->next;
  return (0);
}

int	dir_to(t_cmd **act, t_list **env, int *ret)
{
  int	e;
  int	fd;
  int	give[3];
  char	*tmp;

  e = 0;
  find_next((*act)->cmd, &e);
  tmp = (*act)->cmd[e];
  (*act)->cmd[e] = NULL;
  give[0] = -1;
  if ((fd = open((*act)->cmd[e + 1], O_WRONLY | O_CREAT | O_TRUNC, RIGHTS))
      < 0)
    {
      *ret = 1;
      return (1);
    }
  give[1] = fd;
  input_man((*act)->cmd, env, give, 1);
  (*act)->cmd[e] = tmp;
  *ret = give[2];
  close(fd);
  *act = (*act)->next;
  return (0);
}
