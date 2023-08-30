/*
** my_strncmp.c for  in /home/b00bix/delivery/CPool_Day06
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Mon Oct 10 21:39:37 2016 Matthieu BRAULT
** Last update Tue Jan 17 15:19:56 2017 Matthieu BRAULT
*/

#include <unistd.h>
#include <string.h>

int	my_strncmp(char *s1, char *s2, int n)
{
  int	s;

  s = 0;
  if (s1 == NULL || s2 == NULL)
    return (1);
  while (s1[s] != '\0' && s2[s] != '\0' && s <= n)
    {
      if (s1[s] != s2[s])
	return (1);
      s = s + 1;
    }
  return (0);
}
