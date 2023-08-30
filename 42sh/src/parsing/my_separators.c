/*
** my_separators.c for my_separators in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue May  2 16:29:32 2017 alexandre
** Last update Sun May 21 20:58:54 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

static char	put_sep(char **tmp, char *str, int *num, int *nb)
{
  char		ch;

  ch = str[*nb];
  if (*tmp == NULL || str == NULL)
    return (FAIL);
  (*tmp)[*num] = ' ';
  *num = *num + 1;
  (*tmp)[*num] = ch;
  *num = *num + 1;
  if ((str[*nb + 1] == ch && (ch == '|' || ch == '&' ||
			      ch == '<' || ch == '>' || ch == '!'))
      || (ch == '\\'))
    {
      (*tmp)[(*num)++] = ch;
      *nb = *nb + 1;
    }
  else if (ch == '!' || ch == '$')
    put_histo(tmp, str, num, nb);
  if (str[*nb] != '\0')
    {
      *nb = *nb + 1;
      (*tmp)[*num] = ' ';
    }
  *num = *num + 1;
  return (SUCCESS);
}

static char	*put_space(char *str, char *tmp, char *sep)
{
  int		nb;
  int		i;
  int		num;

  nb = 0;
  num = 0;
  if (str == NULL || tmp == NULL || sep == NULL)
    return (NULL);
  while (str[nb] != '\0')
    {
      i = 0;
      while (sep[i] != '\0' && sep[i] != str[nb])
	i = i + 1;
      if (str[nb] != sep[i])
	put_space_next(str, tmp, &nb, &num);
      else
	put_sep(&tmp, str, &num, &nb);
    }
  return (tmp);
}

static char	*alloc_clear(char *str, const int count)
{
  char		*tmp;
  int		nb;
  int		total;

  nb = 0;
  total = my_strlen(str) + count + 1;
  if ((tmp = malloc(sizeof(char) * total)) == NULL)
    return (NULL);
  while (nb != total)
    {
      tmp[nb] = '\0';
      nb = nb + 1;
    }
  return (tmp);
}

static char	*create_space(char *str, char *sep)
{
  char		*tmp;
  int		nb;
  int		i;
  int		count;

  nb = 0;
  count = 0;
  tmp = NULL;
  if (str == NULL || sep == NULL)
    return (NULL);
  while (str != NULL && str[nb] != '\0')
    {
      i = 0;
      while (sep != NULL && sep[i] != '\0')
	{
	  if (str[nb] == sep[i])
	    count = count + 2;
	  i = i + 1;
	}
      nb = nb + 1;
    }
  if ((tmp = alloc_clear(str, count)) == NULL)
    return (NULL);
  return (tmp);
}

char	*my_separators(char *str)
{
  char	*sep;
  char	*tmp;

  tmp = NULL;
  sep = TO_SEPARATE;
  if (str == NULL || str[0] == '\0')
    return (str);
  else if ((tmp = create_space(str, sep)) == NULL
	   || (tmp = put_space(str, tmp, sep)) == NULL
	   || (tmp = my_epurstr(tmp, 0)) == NULL)
    {
      free(str);
      return (NULL);
    }
  free(str);
  return (tmp);
}
