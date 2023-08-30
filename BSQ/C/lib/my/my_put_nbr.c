/*
** my_put_nbr.c for  in /home/b00bix/delivery/CPool_Day07/lib/my
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Wed Oct 12 12:46:40 2016 Matthieu BRAULT
** Last update Tue Dec 13 18:28:13 2016 Matthieu BRAULT
*/

#include <unistd.h>

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  if (nb < 10)
    my_putchar('0' + nb);
  else
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
}
