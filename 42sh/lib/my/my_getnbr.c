/*
** my_getnbr.c for  in /home/b00bix/delivery/CPool_Day04
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Tue Oct 11 09:06:47 2016 Matthieu BRAULT
** Last update Wed Mar  1 14:45:04 2017 Matthieu BRAULT
*/

#include <unistd.h>

int	my_atoi(char *str)
{
  int   signe;
  int   result;
  int   x;

  signe = 1;
  result = 0;
  x = 0;
  while (str[x] == '-' || str[x] == '+')
    {
      if (str[x++] == '-')
	signe = - signe;
    }
  while (str[x] != '\0' && str[x] >= '0' && str[x] <= '9')
    {
      if (result > 214748364)
	return (0);
      if (result == 21478364 && str[x] > 7 && signe == 1)
	return (0);
      if (result == 21478364 && str[x] > 8 && signe == -1)
	return (0);
      result = result * 10 + str[x++] - 48;
    }
  if (signe == -1)
    result = - result;
  return (result);
}
