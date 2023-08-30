/*
** bsq.h for  in /home/b00bix/delivery/CProgElem/CPE_2016_BSQ/include
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Thu Dec  8 14:33:27 2016 Matthieu BRAULT
** Last update Sat Dec 17 00:01:47 2016 Matthieu BRAULT
*/

#ifndef BSQ_H_
# define BSQ_H_

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

typedef struct		s_tab
{
  char	**char_map;
  int	**int_map;
  int	line;
  int	width;
}			t_tab;

void	my_putchar(char c);
void	check_first_line(char *str);
void	free_malloc(t_tab *tab, char *buff);
int	check_if_empty(char *str);
int	special_case(t_tab *t, char *str);
int	my_put_nbr(int nb);
int	find_higher(t_tab *tab);
void	display_result(t_tab *tab);
int	get_width(char *str);
void	put_x(t_tab *tab, int x, int y, int size);
void	create_char_tab(char *str, t_tab *map);
int	my_min(t_tab *tab, int s, int x);
void	my_algo(t_tab *tab);
void	create_int_tab(char *str, t_tab *map);
void	fill_char_tab(char *str, t_tab *tab);
void	fill_int_tab(char *str, t_tab *tab);
void	show_map(t_tab *lst);
void	my_puterror(char *str);
int	get_line(char *str);
void	error_handling(char *str);
int	my_strlen2(char *str);
int	my_atoi(char *str);
void	check_character(char *buff);
void	check_line(char *str);
void	read_line(char *file);

#endif /* !BSQ_H_ */
