/*
** my_strlen2.c for  in /home/b00bix/delivery/CProgElem/CPE_2016_BSQ/lib/my
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Thu Dec  8 17:10:22 2016 Matthieu BRAULT
** Last update Thu Dec  8 17:11:04 2016 Matthieu BRAULT
*/

int	my_strlen2(char *str)
{
  int	s;

  s = 0;
  while (str[s] != '\n')
    s = s + 1;
  return (s);
}
