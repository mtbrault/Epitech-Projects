/*
** my_put_nbr.c for my_put_nbr in /home/kiwiv2/epitech/LIBS/lib_printf
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue Feb  7 15:33:07 2017 alexandre
** Last update Tue Feb  7 15:35:14 2017 alexandre
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  int	get;

  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  if (nb >= 0 && nb <= 9)
    my_putchar(nb + 48);
  if (nb > 9)
    {
      get = nb % 10;
      my_put_nbr(nb / 10);
      my_putchar(get + 48);
    }
}
