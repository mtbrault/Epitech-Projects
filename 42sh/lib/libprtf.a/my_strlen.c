/*
** my_strlen.c for my_strlen in /home/kiwiv2/epitech/LIBS/lib_printf
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue Feb  7 15:36:09 2017 alexandre
** Last update Wed Apr 12 14:15:06 2017 alexandre
*/

#include <unistd.h>
#include "my.h"

int	my_strlen(char	*str)
{
  int	nb;

  nb = 0;
  while (str != NULL && str[nb] != '\0')
    nb = nb + 1;
  return (nb);
}
