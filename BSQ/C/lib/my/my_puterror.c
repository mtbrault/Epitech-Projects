/*
** my_puterror.c for  in /home/b00bix/delivery/CProgElem/CPE_2016_BSQ/lib/my
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Thu Dec  8 17:09:26 2016 Matthieu BRAULT
** Last update Thu Dec  8 17:10:11 2016 Matthieu BRAULT
*/

#include <unistd.h>

void	my_puterror(char *str)
{
  write(2, str, my_strlen(str));
}
