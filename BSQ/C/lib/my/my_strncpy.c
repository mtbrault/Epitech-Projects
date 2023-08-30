/*
** my_strncpy.c for  in /home/b00bix/delivery/CPool_Day06
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Mon Oct 10 13:29:11 2016 Matthieu BRAULT
** Last update Tue Oct 11 19:30:47 2016 Matthieu BRAULT
*/

#include <unistd.h>
#include <string.h>

char	*my_strncpy(char *dest, char *src, int n)
{
  int	a;

  a = 0;
  if (n > my_strlen(src))
    {
      while (src[a] != '\0')
	{
	  dest[a] = src[a];
	  a = a + 1;
	}
      dest[a] = src[a];
    }
  else
    {
      while (a < n)
	{
	  dest[a] = src[a];
	  a = a + 1;
	}
      dest[a] = src[a];
    }
  return (dest);
}
