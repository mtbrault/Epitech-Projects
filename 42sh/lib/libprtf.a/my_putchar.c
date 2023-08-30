/*
** my_putchar.c for my_putchar in /home/kiwiv2/epitech/LIBS/lib_printf
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue Feb  7 15:35:27 2017 alexandre
** Last update Tue Feb  7 15:35:55 2017 alexandre
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
