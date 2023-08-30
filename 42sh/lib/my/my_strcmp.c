/*
** my_strstr.c for  in /home/b00bix/delivery/CPool_Day06
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Mon Oct 10 20:29:34 2016 Matthieu BRAULT
** Last update Tue May  9 18:32:11 2017 alexandre
*/

#include <unistd.h>
#include <string.h>

int	my_strcmp(char *s1, char *s2)
{
  int	s;

  s = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[s] != '\0' && s2[s] != '\0')
    {
      if (s1[s] != s2[s])
	return (-1);
      s = s + 1;
    }
  if (s1[s] == '\0' && s2[s] != '\0')
    return (-1);
  else if (s2[s] == '\0' && s1[s] != '\0')
    return (-1);
  return (0);
}
