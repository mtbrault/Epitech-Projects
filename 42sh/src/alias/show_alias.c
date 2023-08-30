/*
** show_alias.c for show_alias in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Fri May 19 21:31:19 2017 alexandre
** Last update Sun May 21 20:52:29 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

static void	show_it(t_alias **alias)
{
  int		nb;

  nb = 0;
  while (alias != NULL && alias[nb] != NULL)
    {
      my_printf("%s\t(%s)\n", alias[nb]->name, alias[nb]->command);
      nb = nb + 1;
    }
}

char	show_alias(char **tab, t_alias **alias)
{
  int	nb;

  nb = 0;
  while (tab != NULL && tab[nb] != NULL)
    {
      if (my_strcmp(tab[nb], ALIAS) == SUCCESS && tab[nb + 1] == NULL)
	show_it(alias);
      if (my_strcmp(tab[nb], ALIAS) == SUCCESS && tab[nb + 1] != NULL
	  && is_a_separator(tab[nb + 1][0]) == SUCCESS)
	show_it(alias);
      nb = nb + 1;
    }
  return (SUCCESS);
}
