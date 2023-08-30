/*
** verif_pos_sep.c for verif_pos_sep in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue May 16 21:40:54 2017 alexandre
** Last update Sun May 21 20:59:59 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

char	my_sep_is(const char ch)
{
  int		nb;
  char		*str;

  nb = 0;
  str = SEPARATORS;
  while (str != NULL && str[nb] != '\0' && str[nb] != ch)
    nb = nb + 1;
  if (str[nb] != '\0')
    return (ch);
  return (';');
}

static char	my_error_sep(const char ch)
{
  if (ch == '|')
    my_putstr(INVALID);
  else if (ch == '>' || ch == '<')
    my_putstr(MISSING);
  return (FAIL);
}

static char	verif_ambiguous(char **tab)
{
  int		nb;

  nb = 0;
  while (tab != NULL && tab[nb] != NULL)
    {
      if (my_sep_is(tab[nb][0]) == '|'
	  && tab[nb + 1] != NULL && tab[nb + 2] != NULL
	  && my_sep_is(tab[nb + 2][0]) == '<')
	{
	  my_putstr(AMBIGUOUS);
	  return (FAIL);
	}
      nb = nb + 1;
    }
  return (SUCCESS);
}

char	verif_pos_sep(char **tab)
{
  int	nb;
  char	ch;

  nb = 0;
  ch = '\0';
  if (verif_ambiguous(tab) == FAIL)
    return (FAIL);
  if (tab == NULL || tab[0] == NULL ||
      (is_a_separator(tab[0][0]) == SUCCESS &&
       (ch = my_sep_is(tab[0][0])) != ';'))
    return (my_error_sep(ch));
  while (tab != NULL && tab[nb] != NULL && tab[nb + 1] != NULL)
    {
      if (is_a_separator(tab[nb][0]) == SUCCESS &&
	  is_a_separator(tab[nb + 1][0]) == SUCCESS &&
	  (ch = my_sep_is(tab[nb][0])) != ';' && ch != '&')
	return (my_error_sep(ch));
      nb = nb + 1;
    }
  if (tab[nb] != NULL && is_a_separator(tab[nb][0]) == SUCCESS &&
      (ch = my_sep_is(tab[nb][0])) != ';' && ch != '&')
    return (my_error_sep(ch));
  return (SUCCESS);
}
