/*
** error.c for error in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue May  2 19:57:31 2017 alexandre
** Last update Sun May 21 20:56:56 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include "mysh.h"

int	put_error_fil(char *str)
{
  my_puterror(str, SUCCESS);
  my_puterror(NO_FILE, 1);
  return (1);
}

int	put_error_permission(char *str)
{
  my_puterror(str, SUCCESS);
  my_puterror(NO_PERMISSION, 1);
  return (1);
}
