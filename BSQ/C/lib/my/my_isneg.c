/*
** my_isneg.c for  in /home/b00bix/delivery/CPool_Day03
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Wed Oct  5 15:47:22 2016 Matthieu BRAULT
** Last update Thu Oct  6 09:09:55 2016 Matthieu BRAULT
*/

#include <unistd.h>

int	my_isneg(int n)
{
  char	positif;
  char	negatif;

  negatif = 'N';
  positif = 'P';
  if (n < 0)
    {
      my_putchar(negatif);
    }
  else
    {
      my_putchar(positif);
    }
}
