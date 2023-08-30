/*
** my_swap.c for  in /home/b00bix/delivery/CPool_Day04
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Thu Oct  6 20:16:47 2016 Matthieu BRAULT
** Last update Fri Oct  7 14:11:40 2016 Matthieu BRAULT
*/

#include <unistd.h>

int	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}
