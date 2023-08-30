/*
** my_epurstr.c for epurstr in /home/kiwiv2/epitech/CPE/CPE_SEM2/CPE_2016_corewar/asm/lib
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Mon Mar  6 01:53:49 2017 alexandre
** Last update Sun May 21 20:58:11 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

static int	verif_endline(char *str, int nb)
{
  int		count;
  int		get;

  get = nb;
  count = 0;
  if (str == NULL || str[get] == '\0')
    return (0);
  while (str[get] != '\0' && (str[get] == ' ' ||
			      str[get] == '\t'))
    {
      get = get + 1;
      count = count + 1;
    }
  if (str[get] != '\0')
    return (0);
  return (count);
}

static char	*epur_spaces(char *str, int *nb, char *new, int *get)
{
  int		count;

  if ((count = verif_endline(str, *nb)) == 0)
    new[*get] = ' ';
  else
    {
      *nb = *nb + count;
      return (new);
    }
  while (str[*nb] != '\0' && (str[*nb] == '\t' ||
			      str[*nb] == ' '))
    *nb = *nb + 1;
  *get = *get + 1;
  return (new);
}

char	*my_epurstr(char *str, int nb)
{
  char	*new;
  int	get;

  get = 0;
  if (str == NULL || nb != 0 ||
      (new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[nb] != '\0' && (str[nb] == ' ' || str[nb] == '\t'))
    nb = nb + 1;
  if (str[nb] == '\0')
    return ("\0");
  while (str[nb] != '\0')
    {
      if (str[nb] == ' ' || str[nb] == '\t')
	new = epur_spaces(str, &nb, new, &get);
      else
	{
	  new[get] = str[nb];
	  nb = nb + 1;
	  get = get + 1;
	}
    }
  new[get] = '\0';
  free(str);
  return (new);
}
