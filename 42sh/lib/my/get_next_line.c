/*
** get_next_line.c for get_next_line in /home/kiwiv2/epitech/PSU/minishell1/tools
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Thu Jan 19 00:36:32 2017 alexandre
** Last update Sat Apr 22 20:14:34 2017 alexandre
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*my_gnlcat(char *line, char *buff)
{
  char	*newline;
  long	len;
  long	nb;

  len = 0;
  nb = 0;
  if ((newline = malloc(sizeof(char) * (my_strlen(line)
					+ my_strlen(buff) + 1))) == NULL)
    return (NULL);
  while (line != NULL && line[len] != '\0')
    {
      newline[len] = line[len];
      len = len + 1;
    }
  while (buff != NULL && buff[nb] != '\0')
    {
      newline[len + nb] = buff[nb];
      nb = nb + 1;
    }
  newline[len + nb] = '\0';
  free(line);
  return (newline);
}

char	*my_last(char *line, int nb)
{
  char	*new;
  long	count;

  count = 0;
  while (line != NULL && line[count] != '\0' && line[count] != '\n')
    count = count + 1;
  if (line == NULL ||
      (new = malloc(sizeof(char) * (my_strlen(line) + 1))) == NULL)
    return (NULL);
  if (line[count] == '\n')
    count = count + 1;
  while (line[count] != '\0')
    {
      new[nb] = line[count++];
      nb = nb + 1;
    }
  new[nb] = '\0';
  free(line);
  if (my_strlen(new) == 1)
    {
      free(new);
      return (NULL);
    }
  return (new);
}

char		*my_read(const int fd, long get)
{
  long		nb;
  char		buff[READ_SIZE + 1];
  static char	*line;

  if (line != NULL)
    {
      if ((line = my_last(line, 0)) == NULL)
	return (NULL);
    }
  while ((get = read(fd, buff, READ_SIZE)) > 0)
    {
      nb = 0;
      buff[get] = '\0';
      if ((line = my_gnlcat(line, buff)) == NULL)
	return (NULL);
      while (line != NULL && line[nb] != '\0' && line[nb] != '\n')
	nb = nb + 1;
      if (line[nb] == '\n')
	return (line);
    }
  return (line);
}

char	*my_line(char *str)
{
  char	*new;
  long	nb;

  nb = 0;
  while (str != NULL && str[nb] != '\0' && str[nb] != '\n')
    nb = nb + 1;
  if ((new = malloc(sizeof(char) * (nb + 1))) == NULL)
    return (NULL);
  nb = 0;
  if (str == NULL || str[nb] == '\0')
    return (NULL);
  while (str[nb] != '\0' && str[nb] != '\n')
    {
      new[nb] = str[nb];
      nb = nb + 1;
    }
  new[nb] = '\0';
  return (new);
}

char	*get_next_line(const int fd)
{
  char	buff[READ_SIZE + 1];
  char	*tmp;
  long	get;

  get = 0;
  if (buff == NULL)
    return (NULL);
  if (fd == -1 || READ_SIZE <= 0)
    return (NULL);
  if ((tmp = my_read(fd, get)) == NULL)
    return (NULL);
  if ((tmp = my_line(tmp)) == NULL)
    return (NULL);
  return (tmp);
}
