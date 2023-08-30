/*
** my_putchar.c for  in /home/b00bix/delivery/For the librabry
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Tue Oct 11 17:58:15 2016 Matthieu BRAULT
** Last update Tue Oct 11 17:59:13 2016 Matthieu BRAULT
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
