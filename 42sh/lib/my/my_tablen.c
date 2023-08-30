/*
** my_tablen.c for my_tablen in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/lib/my
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Mon May  8 18:27:13 2017 alexandre
** Last update Mon May  8 18:30:29 2017 alexandre
*/

#include <unistd.h>

int	my_tablen(char **tab)
{
  int	nb;

  nb = 0;
  while (tab != NULL && tab[nb] != NULL)
    nb = nb + 1;
  return (nb);
}
