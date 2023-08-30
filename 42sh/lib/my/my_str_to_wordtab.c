/*
** my_str_to_wordtab.c for  in /home/b00bix/delivery/PSU_2016_minishell1
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Tue Jan 17 15:33:47 2017 Matthieu BRAULT
** Last update Sun May 21 20:29:22 2017 Capitaine CASSE
*/

#include <stdlib.h>

static char	**size_str_tab(char *str, char **tab,
			       const int len, const char c)
{
  int	i;
  int	k;
  int	j;

  i = 0;
  j = 0;
  while (i < len)
    {
      k = 0;
      while (str[j] != c && str[j] != '\0')
	{
	  j = j + 1;
	  k = k + 1;
	}
      while (str[j] == c && str[j] != '\0')
	j = j + 1;
      if ((tab[i] = malloc(sizeof(char) * (k + 1))) == NULL)
	return (NULL);
      i = i + 1;
    }
  return (tab);
}

static char	**cpy_cara_str_tab(char *str, char **tab,
				   const int len, const char c)
{
  int	i;
  int	j;
  int	k;

  j = 0;
  i = 0;
  while (i < len)
    {
      k = 0;
      while ((str[j] == c) && (str[j] != '\0'))
        j = j + 1;
      while ((str[j] != c && str[j] != '\0'))
	{
	  tab[i][k] = str[j];
	  k = k + 1;
	  j = j + 1;
	}
      if ((str[j] == c) && (str[j] != '\0'))
	tab[i][k] = '\0';
      i = i + 1;
    }
  while (tab[i - 1][0] == '\0')
    i = i - 1;
  tab[i] = NULL;
  return (tab);
}

char	**my_str_to_wordtab(char *str, const char c)
{
  char	**tab;
  int	i;
  int	len;

  len = 1;
  i = 1;
  if (str == NULL)
    return (NULL);
  while (str[i])
    {
      if (str[i] != c && str[i - 1] == c && str[i] != '\0')
	len = len + 1;
      i = i + 1;
    }
  if ((tab = malloc(sizeof(char *) * (len + 1))) == NULL)
    return (NULL);
  if ((tab = size_str_tab(str, tab, len, c)) == NULL)
    return (NULL);
  tab = cpy_cara_str_tab(str, tab, len, c);
  return (tab);
}
