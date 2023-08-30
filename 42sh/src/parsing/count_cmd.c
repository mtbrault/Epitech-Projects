/*
** count_cmd.c for count_cmd in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue May  2 22:15:51 2017 alexandre
** Last update Sun May 21 20:58:37 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

static void	count_cmd_next(char *str, const char ch, int *nb, int *count)
{
  if (str != NULL && nb != NULL && count != NULL)
    {
      if (ch != '"' && ch != 39)
	*count = *count + 1;
      else if (ch == '"' || ch == 39)
	{
	  *nb = *nb + 1;
	  while (str[*nb] != '\0' && str[*nb] != ch)
	    *nb = *nb + 1;
	  if (str[*nb] == ch)
	    *count = *count + 1;
	}
    }
}

int	count_cmd(char *str)
{
  int	count;
  int	nb;
  char	ch;

  nb = 0;
  count = 0;
  while (str != NULL && str[nb] != '\0')
    {
      ch = str[nb];
      count_cmd_next(str, ch, &nb, &count);
      if (str[nb] != '\0')
        nb = nb + 1;
    }
  return (count);
}

int	len_cmd(char *str, const int pos)
{
  int	count;
  int	nb;
  char	ch;

  nb = pos;
  count = 0;
  if (str[nb] == '"' || str[nb] == 39)
    {
      count = count + 1;
      ch = str[nb];
      nb = nb + 1;
    }
  else
    ch = ' ';
  while (str[nb] != '\0' && str[nb] != ch)
    {
      nb = nb + 1;
      count = count + 1;
    }
  if (ch == '"' || ch == 39)
    count = count + 3;
  else
    count = count + 2;
  return (count);
}
