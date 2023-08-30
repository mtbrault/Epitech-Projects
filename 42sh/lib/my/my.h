/*
** my.h for  in /home/george_t/rendu/POOL/CPool_Day07/lib/my
** 
** Made by Tom GEORGES
** Login   <george_t@epitech.net>
** 
** Started on  Tue Oct 11 10:51:46 2016 Tom GEORGES
** Last update Wed May 17 16:20:04 2017 alexandre
*/

#ifndef MY_H_
# define MY_H_

#include <stdarg.h>

int	my_tablen(char **tab);
void	my_putchar(char c);
void	my_putstr(char *str);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int i);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_puterror(char *str, int x);
char	**my_str_to_wordtab(char *str, char sep);
char	*my_strdup(char *src);
int	my_show_wordtab(char **tab);
int	calc(char *str, int i, int num);
int	count_less(char *str, int i);
int	count_digits(char *str, int i);
int	my_is_numalpha(char sep);
char	**cpy_cara_str_tab(char *str, char **tab, int word, char sep);
char	**size_str_tab(char *str, char **tab, int word, char sep);
int	put_hexa(char charac, char *base, int type_base);
int	my_range(va_list ap, char cara);
void	my_chek_format(const char *format, ...);
void	my_putnbr_base(int nbr, char *base);
void	my_put_nbr_ui(unsigned int nb);

#endif /* !MY_H_ */
