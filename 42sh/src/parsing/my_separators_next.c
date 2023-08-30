/*
** my_separators_next.c for my_separators_next in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Thu May 18 22:34:23 2017 alexandre
** Last update Sun May 21 20:59:10 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

char	is_a_separator(const char ch)
{
  char	*new;
  int	nb;

  nb = 0;
  new = SEPARATORS;
  while (new[nb] != '\0')
    {
      if (ch == new[nb])
        return (SUCCESS);
      nb = nb + 1;
    }
  return (FAIL);
}

void	put_histo(char **tmp, char *str, int *num, int *nb)
{
  int	i;
  char	*sep;

  sep = TO_SEPARATE;
  if (str[*nb] == '!' || str[*nb] == '$')
    *nb = *nb + 1;
  while (str[*nb] != '\0' && str[*nb] != ' ')
    {
      i = 0;
      while (sep[i] != '\0' && str[*nb] != sep[i])
        i = i + 1;
      if (str[*nb] == sep[i])
        {
          if (*nb > 0)
            *nb = *nb - 1;
          break ;
        }
      (*tmp)[*num] = str[*nb];
      *num = *num + 1;
      *nb = *nb + 1;
    }
}

char	put_space_next(char *str, char *tmp, int *nb, int *num)
{
  char	ch;

  ch = str[*nb];
  if (str == NULL && tmp == NULL && nb == NULL && num == NULL)
    return (FAIL);
  if (str[*nb] == '"' || str[*nb] == 39)
    {
      tmp[*num] = str[*nb];
      *nb = *nb + 1;
      *num = *num + 1;
      while (str[*nb] != '\0' && str[*nb] != ch)
	{
	  tmp[*num] = str[*nb];
	  *num = *num + 1;
	  *nb = *nb + 1;
	}
    }
  else
    {
      tmp[*num] = str[*nb];
      *num = *num + 1;
      *nb = *nb + 1;
    }
  return (SUCCESS);
}
