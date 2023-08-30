/*
** my_strstr.c for  in /home/b00bix/delivery/CPool_Day06
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Tue Oct 11 09:52:52 2016 Matthieu BRAULT
** Last update Tue Oct 11 19:30:00 2016 Matthieu BRAULT
*/

#include <unistd.h>

char	*my_strstr(char *str, char *to_find)
{
  int	a;

  if (str[0] != '\0')
    {
      a = 0;
      while (to_find[a] != '\0')
	{
	  if (to_find[a] != str[a])
	    {
	      return (my_strstr (str + 1, to_find));
	    }
	  a = a + 1;
	}
      return (str);
    }
  else
    {
      return (0);
    }
}
