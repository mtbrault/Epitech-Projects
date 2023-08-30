/*
** my_tabncmp.c for my_tabncmp in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/lib/my
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Mon May  8 18:02:36 2017 alexandre
** Last update Tue May  9 18:33:49 2017 alexandre
*/

#include <unistd.h>
#include "my.h"

int	my_tabncmp(char **first, char **second, const int max)
{
  int	nb;

  nb = 0;
  if (first == NULL || second == NULL || max > my_tablen(second) || max == 0)
    return (-1);
  while (first[nb] != NULL && second[nb] != NULL && nb != max)
    {
      if (my_strcmp(first[nb], second[nb]) == -1)
	return (-1);
      nb = nb + 1;
    }
  return (0);
}
