/*
** globing.c for  in /home/b00bix/PSU_2016_42sh
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Wed May 17 16:01:59 2017 Matthieu BRAULT
** Last update Sun May 21 20:55:40 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include <dirent.h>
#include "mysh.h"

static int	my_special_cmp(char *s1, char *s2)
{
  int		s;
  int		i;

  s = 0;
  i = 0;
  if (my_strlen(s1) == 0)
    return (0);
  while (s1[i] != '\0' && s2[s] != '\0')
    {
      if (s1[i] != s2[s])
	{
	  if (s1[i] != '*')
	    return (1);
	  i = i + 1;
	  while (s2[s] != '\0' && s1[i] != s2[s])
	    s = s + 1;
	}
      if (s2[s] != '\0')
	s = s + 1;
      if (s1[i] != '\0')
	i = i + 1;
    }
  if (s1[i] != s2[s])
    return (1);
  return (0);
}

static char	**my_globbing(char *cmd)
{
  struct dirent	*sd;
  char		**tab;
  DIR		*dir;

  tab = NULL;
  if ((sd = malloc(sizeof(struct dirent))) == NULL
      || (dir = opendir(".")) == NULL)
    return (NULL);
  while ((sd = readdir(dir)) != NULL)
    {
      if (my_special_cmp(cmd, sd->d_name) == 0)
	{
	  if ((tab = my_tabcat(tab, sd->d_name)) == NULL)
	    return (NULL);
	}
    }
  free(sd);
  closedir(dir);
  return (tab);
}

static char	find_globbing(char **tab)
{
  int		nb;
  int		ind;

  nb = 0;
  while (tab != NULL && tab[nb] != NULL)
    {
      ind = 0;
      while (tab[nb][ind] != '\0' && tab[nb][ind] != '*')
	ind = ind + 1;
      if (tab[nb][ind] == '*')
	return (SUCCESS);
      nb = nb + 1;
    }
  return (FAIL);
}

static char	**glob_it(char **tab, char *to_glob)
{
  char		**glob;
  int		nb;

  nb = 0;
  glob = my_globbing(to_glob);
  while (glob != NULL && glob[nb] != NULL)
    {
      if ((tab = my_tabcat(tab, glob[nb])) == NULL)
	return (NULL);
      nb = nb + 1;
    }
  free_tab(glob);
  return (tab);
}

char	**globing(char **tab)
{
  int	nb;
  int	ind;
  char	**new;

  nb = 0;
  new = NULL;
  if (find_globbing(tab) != SUCCESS)
    return (tab);
  while (tab != NULL && tab[nb] != NULL)
    {
      ind = 0;
      while (tab[nb][ind] != '\0' && tab[nb][ind] != '*')
	ind = ind + 1;
      if (tab[nb][ind] == '*' && (new = glob_it(new, tab[nb])) == NULL)
	return (tab);
      else if (tab[nb][ind] != '*' && (new = my_tabcat(new, tab[nb])) == NULL)
	return (tab);
      nb = nb + 1;
    }
  free_tab(tab);
  return (new);
}
