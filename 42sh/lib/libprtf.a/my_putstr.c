/*
** my_putstr.c for my_putstr in /home/kiwiv2/epitech/LIBS/lib_printf
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue Feb  7 15:37:07 2017 alexandre
** Last update Tue Feb  7 15:37:42 2017 alexandre
*/

#include "my.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
