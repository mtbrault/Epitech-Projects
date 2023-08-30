/*
** loop.c for PSU_2016_42sh in /home/antoine.casse/Desktop/PSU_2016_42sh/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Wed Apr 12 19:43:48 2017 Capitaine CASSE
** Last update Sun May 21 20:56:26 2017 Matthieu BRAULT
*/

#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

static char	*g_prompt = PROMPT;

void	ctr_c()
{
  my_putstr(CTR_C);
  my_putstr(g_prompt);
}

static char	loop_next(char **tab, t_list **list, int *ret, t_history *hist)
{
  if (tab == NULL || ret == NULL
      || (tab = globing(tab)) == NULL
      || (tab = remove_cmd(tab, SET)) == NULL)
    return (ERROR);
  g_prompt = hist->set_prompt;
  if (verif_pos_sep(tab) == SUCCESS)
    separate(tab, list, ret);
  free_tab(tab);
  return (SUCCESS);
}

int		loop(t_list *list, int *ret, t_alias **alias)
{
  char		*str;
  char		**tab;
  t_history	*history;

  my_putstr(PROMPT);
  if ((history = init_history()) == NULL)
    return (ERROR);
  while ((str = get_next_line(0)) != NULL)
    {
      if ((str = my_epurstr(str, 0)) == NULL
	  || (str = my_separators(str)) == NULL)
	return (ERROR);
      else if (str != NULL && str[0] != '\0' && check_unmatch(str) == SUCCESS)
	{
	  if ((str = my_alias(str, &alias)) == NULL
	      || (tab = create_tab(str, &alias)) == NULL
	      || loop_next(tab, &list, ret, history) == ERROR)
	    return (ERROR);
	}
      my_putstr(history->set_prompt);
    }
  return (SUCCESS);
}
