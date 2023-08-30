/*
** my_putstr.c for  in /home/b00bix/delivery/CPool_Day04
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Thu Oct  6 21:33:46 2016 Matthieu BRAULT
** Last update Sun May 21 20:28:11 2017 Capitaine CASSE
*/

#include <unistd.h>
#include "my.h"

void	my_putstr(char *str)
{
  if (str != NULL)
    write(1, str, my_strlen(str));
}
