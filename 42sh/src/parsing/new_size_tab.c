/*
** new_size_tab.c for new_size_tab in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue May  9 17:57:22 2017 alexandre
** Last update Sun May 21 20:59:29 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

int	new_size(char **tab, t_alias **alias)
{
  int	nb;
  int	count;
  int	ind;
  char	**name;

  nb = 0;
  count = my_tablen(tab) + 1;
  while (tab != NULL && tab[nb] != NULL)
    {
      ind = 0;
      while (alias != NULL && alias[ind] != NULL)
	{
          if ((name = my_str_to_wordtab(alias[ind]->name, ' ')) == NULL)
            return (ERROR);
          if (my_tabncmp(&tab[nb], name, my_tablen(name)) == SUCCESS)
            count = count + count_cmd(alias[ind]->command) + 2;
          free_tab(name);
          ind = ind + 1;
        }
      nb = nb + 1;
    }
  return (count);
}

int    	new_size_with_exit(char **tab)
{
  int  	nb;
  int  	count;
  int  	remov;
  int  	ind;

  nb = 0;
  remov = 0;
  ind = 0;
  count = my_tablen(tab);
  while (tab != NULL && tab[nb] != NULL)
    {
      if (my_strcmp(tab[nb], EXIT_S) == SUCCESS)
        {
          if (ind != 0)
            {
              if (tab[nb + 1] != NULL &&
                  is_a_separator(tab[nb + 1][0]) == SUCCESS)
                remov = remov + 1;
              remov = remov + 1;
            }
          ind = ind + 1;
        }
      nb = nb + 1;
    }
  return (count - remov);
}

int	new_size_sep(char **tab)
{
  int	nb;
  int	count;

  nb = 0;
  count = 0;
  while (tab != NULL && tab[nb] != NULL)
    {
      while (tab[nb] != NULL
	     && is_a_separator(tab[nb][0]) == SUCCESS
	     && tab[nb + 1] != NULL
	     && is_a_separator(tab[nb + 1][0]) == SUCCESS
	     && my_strcmp(tab[nb], tab[nb + 1]) == SUCCESS
	     && my_sep_is(tab[nb][0]) == ';')
	nb = nb + 1;
      count = count + 1;
      if (tab[nb] != NULL)
	nb = nb + 1;
    }
  return (count);
}

int	new_size_spaces(char **tab)
{
  int	nb;
  int	count;

  nb = 0;
  count = 0;
  while (tab != NULL && tab[nb] != NULL)
    {
      if (tab[nb][0] == -62)
	{
	  nb = nb + 1;
	  continue ;
	}
      count = count + 1;
      nb = nb + 1;
    }
  return (count);
}
