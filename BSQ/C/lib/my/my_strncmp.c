/*
** my_strncmp.c for  in /home/b00bix/delivery/CPool_Day06
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Mon Oct 10 21:39:37 2016 Matthieu BRAULT
** Last update Tue Oct 11 16:17:39 2016 Matthieu BRAULT
*/

#include <unistd.h>
#include <string.h>

char	my_strncmp(char *s1, char *s2, int n)
{
  int	a;
  int	b;

  a = my_strlen(s1);
  b = my_strlen(s2);;
  if (n >= a && n >= b)
    {
      my_putchar('0');
    }
  else if (n < a && n > b)
    {
      my_putchar('1');
    }
  else
    {
      my_putchar('-');
      my_putchar('1');
    }
}
