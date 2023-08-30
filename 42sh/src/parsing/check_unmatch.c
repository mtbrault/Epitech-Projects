/*
** check_unmatch.c for check_unmatch in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Sat May 20 16:36:54 2017 alexandre
** Last update Sun May 21 20:58:24 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

static char	match_this_ch(const char ch)
{
  char		*inv_match;
  char		*to_match;
  int		nb;

  nb = 0;
  inv_match = INV_MATCH;
  to_match = TO_MATCH;
  while (to_match != NULL && to_match[nb] != '\0' && to_match[nb] != ch)
    nb = nb + 1;
  if (to_match[nb] != '\0' || ch == '"')
    return (SUCCESS);
  nb = 0;
  while (inv_match != NULL && inv_match[nb] && inv_match[nb] != ch)
    nb = nb + 1;
  if (nb != 0)
    return (SUCCESS);
  return (FAIL);
}

static char	to_match_it(const char ch, char *str, int *nb)
{
  if (str == NULL || *nb > my_strlen(str))
    return (FAIL);
  if (str[*nb] != '\0')
    *nb = *nb + 1;
  while (str[*nb] != '\0' && str[*nb] != ch)
    *nb = *nb + 1;
  if (str[*nb] == '\0')
    {
      my_printf("%s '%c'.\n", UNMATCH, ch);
      free(str);
      return (FAIL);
    }
  return (SUCCESS);
}

static char	inv_match_it(const char ch, char *str, int nb)
{
  if (str == NULL || nb > my_strlen(str))
    return (FAIL);
  if (str[nb] != '\0' && nb - 1 >= 0)
    nb = nb - 1;
  while (nb != 0 && str[nb] != ch)
    nb = nb - 1;
  if (nb == 0)
    {
      my_printf("%s '%c'.\n", UNMATCH, ch);
      free(str);
      return (FAIL);
    }
  return (SUCCESS);
}

char	check_unmatch(char *str)
{
  int	nb;
  char	ch;

  nb = 0;
  while (str != NULL && str[nb] != '\0')
    {
      ch = str[nb];
      if (match_this_ch(ch) == SUCCESS)
	{
	  if ((ch == '"' || ch == 39) && to_match_it(ch, str, &nb) == FAIL)
	    return (FAIL);
	  if (ch == '[' && to_match_it(ch + 2, str, &nb) == FAIL)
	    return (FAIL);
	  else if (ch == '(' && to_match_it(ch + 1, str, &nb) == FAIL)
	    return (FAIL);
	  if (ch == ')' && inv_match_it(ch - 1, str, nb) == FAIL)
	    return (FAIL);
	  else if (ch == ']' && inv_match_it(ch - 2, str, nb) == FAIL)
	    return (FAIL);
	}
      if (str[nb] != '\0')
	nb = nb + 1;
    }
  return (SUCCESS);
}
