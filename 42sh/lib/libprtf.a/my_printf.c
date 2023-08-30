/*
** my_printf.c for my_printf in /home/kiwiv2/epitech/LIBS/lib_printf
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue Feb  7 15:23:07 2017 alexandre
** Last update Thu Feb 16 22:06:54 2017 alexandre
*/

#include "my.h"

void	my_flags(char c, va_list list)
{
  if (c == 'd' || c == 'i')
    my_put_nbr(va_arg(list, int));
  else if (c == 's')
    my_putstr(va_arg(list, char *));
  else if (c == 'c')
    my_putchar(va_arg(list, int));
  else
    my_putchar(c);
}

int		my_printf(char *str, ...)
{
  va_list	list;
  int		nb;

  nb = 0;
  if (str == NULL)
    return (84);
  va_start(list, str);
  while (str[nb] != '\0')
    {
      if (str[nb] == '%' && str[nb + 1] != ' ' && str[nb + 1] != '\0')
	{
	  nb = nb + 1;
	  my_flags(str[nb], list);
	  nb = nb + 1;
	  if (str[nb] == '\0')
	    return (0);
	}
      my_putchar(str[nb]);
      nb = nb + 1;
    }
  va_end(list);
  return (0);
}
