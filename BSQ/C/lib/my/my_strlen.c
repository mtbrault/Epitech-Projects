/*
** my_strlen.c for  in /home/b00bix/delivery/CPool_Day04
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Fri Oct  7 08:16:04 2016 Matthieu BRAULT
** Last update Tue Oct 11 19:31:09 2016 Matthieu BRAULT
*/

#include <unistd.h>

int	my_strlen(char *str)
{
  int   s;

  s = 0;
  while (str[s] != '\0')
    {
      s = s + 1;
    }
  return (s);
}
