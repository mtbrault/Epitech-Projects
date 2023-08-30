/*
** jobs_control.c for  in /home/BlackBIrdz/PSU_2016_42sh/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Tue May 16 17:31:50 2017 LAABID Zakaria
** Last update Sun May 21 20:55:53 2017 Matthieu BRAULT
*/

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "mysh.h"

void	list_sq(t_jobs **head, int index, pid_t pid, enum e_info info)
{
  t_jobs	*tmp;
  t_jobs	*new_elem;

  tmp = *head;
  if ((new_elem = malloc(sizeof(*new_elem))) != NULL)
    {
      new_elem->index = index;
      new_elem->pid = pid;
      new_elem->info = info;
      new_elem->next = NULL;
      if (*head != NULL)
	{
	  new_elem->prev = NULL;
	  *head = new_elem;
	  while (tmp->next != NULL)
	    tmp = tmp->next;
	  tmp->next = new_elem;
	  new_elem->prev = tmp;
	}
    }
}

static t_jobs	*jobs_init(t_cmd **args, t_list **env, int *ret)
{
  t_jobs	*jobs;
  char		*tmp;
  int		give[3];
  int		end;
  pid_t		pid;
  static int	i = 1;

  end = 0;
  find_next((*args)->cmd, &end);
  tmp = (*args)->cmd[end];
  (*args)->cmd[end] = NULL;
  jobs = NULL;
  give[0] = -1;
  give[1] = -1;
  give[2] = *ret;
  pid = input_man((*args)->cmd, env, give, 0);
  list_sq(&jobs, i++, pid, RUNNING);
  *ret = give[2];
  (*args)->cmd[end] = tmp;
  return (jobs);
}

int		jobs_control(t_cmd **args, t_list **env, int *ret)
{
  t_jobs	*jobs;

  jobs = NULL;
  if ((jobs = jobs_init(args, env, ret)) == NULL)
    return (FAIL);
  dprintf(1, "[%d] %d\n", jobs->index, jobs->pid);
  usleep(15000);
  return (SUCCESS);
}
