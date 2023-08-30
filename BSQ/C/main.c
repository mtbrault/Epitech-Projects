/*
** main.c for  in /home/b00bix/delivery/CProgElem/CPE_2016_BSQ
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Mon Dec 12 15:01:27 2016 Matthieu BRAULT
** Last update Sun Dec 18 16:47:02 2016 Matthieu BRAULT
*/

#include "bsq.h"

char	*read_file(char *file)
{
  int		fd;
  int		size;
  char		*buff;
  struct stat	*sb;

  if ((sb = malloc(sizeof(*sb))) == NULL)
    exit(84);
  stat(file, sb);
  if ((sb->st_mode & S_IFMT) != S_IFREG)
    exit(84);
  if ((fd = open(file, O_RDONLY)) == -1)
    exit(84);
  if ((size = sb->st_size) == 0)
    exit(84);
  if ((buff = malloc(sizeof(char) * size + 1)) == NULL)
    exit(84);
  if (read(fd, buff, size) == -1)
    exit(84);
  buff[size] = '\0';
  free(sb);
  close(fd);
  return (buff);
}

void	free_malloc(t_tab *tab, char *buff)
{
  int	s;

  s = 0;
  free(buff);
  while (s < tab->line)
    {
      free(tab->char_map[s]);
      s = s + 1;
    }
  free(tab->char_map);
  s = 0;
  while (s < tab->line)
    {
      free(tab->int_map[s]);
      s = s + 1;
    }
  free(tab->int_map);
  free(tab);
}

int	main(int ac, char **av)
{
  char	*buff;
  t_tab	*tab;

  if (ac != 2)
    return (84);
  if ((tab = malloc(sizeof(*tab))) == NULL)
    return (84);
  buff = read_file(av[1]);
  error_handling(buff);
  tab->line = get_line(buff);
  tab->width = get_width(buff);
  fill_char_tab(buff, tab);
  fill_int_tab(buff, tab);
  my_algo(tab);
  special_case(tab, buff);
  display_result(tab);
  free_malloc(tab, buff);
  return (0);
}
