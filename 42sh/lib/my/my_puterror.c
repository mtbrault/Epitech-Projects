/*
** my_puterror.c for  in /home/b00bix/lib_my/lib/my
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Mon Dec 19 11:06:56 2016 Matthieu BRAULT
** Last update Mon Apr  3 10:26:55 2017 Matthieu BRAULT
*/

#include <unistd.h>
#include "my.h"

int	my_puterror(char *str, int x)
{
  write(2, str, my_strlen(str));
  return (x);
}
