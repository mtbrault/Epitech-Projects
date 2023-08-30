/*
** my_shrc.c for my_shrc in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Sat May 20 17:42:35 2017 alexandre
** Last update Sun May 21 20:56:47 2017 Matthieu BRAULT
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

static char	*my_epurlines(char *str, const char ch)
{
  int		nb;
  int		mod;

  nb = 0;
  mod = 0;
  while (str != NULL && str[nb] != '\0')
    {
      if (str[nb] == ch)
	mod = 1;
      if (mod == 1)
	str[nb] = ' ';
      nb = nb + 1;
    }
  if ((str = my_epurstr(str, 0)) == NULL)
    return (NULL);
  return (str);
}

static char	check_shline(char **tab)
{
  if (tab == NULL
      || (my_strcmp(tab[0], EXPORT) != SUCCESS
	  && my_strcmp(tab[0], ALIAS) != SUCCESS))
    return (ERROR);
  if (my_strcmp(tab[2], "=") != SUCCESS)
    return (ERROR);
  return (SUCCESS);
}

static char	**remove_equal(char **tab)
{
  char		**new;
  int		nb;
  int		num;

  nb = 0;
  num = 0;
  if (tab == NULL || (new = malloc(sizeof(char *) * my_tablen(tab))) == NULL)
    return (NULL);
  while (tab[nb] != NULL)
    {
      if (my_strcmp(tab[nb], "=") != SUCCESS)
	{
	  if ((new[num] = my_strdup(tab[nb])) == NULL)
	    return (NULL);
	  num = num + 1;
	}
      nb = nb + 1;
    }
  new[num] = NULL;
  free_tab(tab);
  return (new);
}

static char	sh_loop_next(char *str, t_list **list, t_alias ***alias)
{
  char		**tab;
  int		tmp;

  tmp = 0;
  if (str != NULL && (tab = parsing_cmd_loop(str, count_cmd(str) + 2)) == NULL)
    return (ERROR);
  free(str);
  if (check_shline(tab) == ERROR)
    {
      free_tab(tab);
      return (ERROR);
    }
  if ((tab = remove_equal(tab)) == NULL)
    return (ERROR);
  else if (my_strcmp(tab[0], EXPORT) == SUCCESS
	   && my_setenv(tab, list, &tmp) == 1)
    return (ERROR);
  else if (my_strcmp(tab[0], ALIAS) == SUCCESS
	   && setalias(tab, alias) == 1)
    return (ERROR);
  free_tab(tab);
  return (SUCCESS);
}

char	my_shrc(t_list **list, t_alias ***alias)
{
  char	*str;
  int	fd;
  int	nb;

  nb = 0;
  if ((fd = open(SHRC, O_RDONLY)) == FAIL)
    return (FAIL);
  while ((str = get_next_line(fd)) != NULL)
    {
      nb = nb + 1;
      if ((str = my_epurlines(str, COMMENT)) == NULL)
	return (ERROR);
      if (str[0] != '\0' && sh_loop_next(str, list, alias) == ERROR)
	{
	  close(fd);
	  my_printf("%s %d %s\n", LINE_ERR, nb, CORRUPTED);
	  free(str);
	  return (ERROR);
	}
    }
  close(fd);
  return (SUCCESS);
}
