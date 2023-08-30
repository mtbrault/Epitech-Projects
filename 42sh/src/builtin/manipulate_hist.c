/*
** manipulate_hist.c for manipulate_hist in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Wed May 17 17:06:26 2017 alexandre
** Last update Sun May 21 20:53:45 2017 Matthieu BRAULT
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

t_history	*init_history()
{
  t_history	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->set_hist = 100;
  new->set_save = -1;
  if ((new->set_prompt = my_strdup(PROMPT)) == NULL
      || (new->path = my_strdup(HISTORY)) == NULL)
    return (NULL);
  return (new);
}
