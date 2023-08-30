/*
** dump_history.c for dump_history in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Sat May 20 15:06:13 2017 alexandre
** Last update Sun May 21 20:54:20 2017 Matthieu BRAULT
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

static char	dump_hist()
{
  int		fd;
  int		nb;
  char		*str;

  nb = 0;
  if ((fd = open(HISTORY, O_RDONLY)) == FAIL)
    return (1);
  while ((str = get_next_line(fd)) != NULL)
    {
      nb = nb + 1;
      my_printf("  %d\t%s\n", nb, str);
      free(str);
    }
  close(fd);
  return (SUCCESS);
}

static char	dump_this_history(const int nb, char **tab)
{
  int		len;
  int		ind;

  ind = 0;
  if (tab == NULL)
    return (1);
  len = my_tablen(tab) - 1 - nb;
  while (tab[len] != NULL && len > -1 && ind < nb)
    {
      my_printf("  %d\t%s\n", len, tab[len]);
      ind = ind + 1;
      len = len + 1;
    }
  if (nb == 0)
    my_printf("  %d\t%s\n", len, tab[len]);
  free_tab(tab);
  return (SUCCESS);
}

static char	dump_part(const int nb)
{
  char		**tab;
  char		*str;
  int		fd;

  tab = NULL;
  if (nb < 0)
    return (my_puterror(HISTORY_US, 1));
  else if ((fd = open(HISTORY, O_RDONLY)) == FAIL)
    return (1);
  while ((str = get_next_line(fd)) != NULL)
    {
      if ((tab = my_tabcat(tab, str)) == NULL)
	{
	  close(fd);
	  return (1);
	}
      free(str);
    }
  close(fd);
  if (dump_this_history(nb, tab) == 1)
    return (1);
  return (SUCCESS);
}

int	history(char **arg, t_list **env, int *fd)
{
  int	len;

  env = env;
  fd = fd;
  len = my_tablen(arg);
  if (arg == NULL || env == NULL || fd == NULL)
    return (1);
  if (len > 3)
    {
      fd[2] = 1;
      return (my_puterror(HISTORY_TM, 0));
    }
  if (len == 1)
    {
      if (dump_hist() == 1)
	fd[2] = 1;
    }
  else if (len == 2 || len == 3)
    {
      if (check_is_num(arg[1]) == FAIL)
	my_puterror(HISTORY_BADN, 0);
      else if (dump_part(my_atoi(arg[1])) == 1)
	fd[2] = 1;
    }
  return (SUCCESS);
}
