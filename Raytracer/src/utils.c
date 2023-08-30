/*
** utils.c for  in /home/b00bix/raytracer1/src
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Mon Feb 27 12:46:59 2017 Matthieu BRAULT
** Last update Wed Mar  8 14:57:15 2017 Matthieu BRAULT
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "raytracer1.h"

float	result(sfVector3f abc, float delta)
{
  float	x1;
  float	x2;

  if (delta < 0)
    return (-1.0f);
  else if (delta == 0)
    {
      if ((x1 = (abc.y * -1) / (2.0 * abc.x)) >= 0)
	return (x1);
      else
	return (-1.0f);
    }
  else
    {
      x2 = ((abc.y * -1) - sqrt(delta)) / (2.0 * abc.x);
      x1 = ((abc.y * -1) + sqrt(delta)) / (2.0 * abc.x);
      if (x1 < 0 && x2 < 0)
	return (-1.0f);
      if ((x1 <= x2 && x1 >= 0) || (x1 >= x2 && x2 < 0))
	return (x1);
      else if ((x2 <= x1 && x2 >= 0) || (x2 >= x1 && x1 < 0))
	return (x2);
      else
	return (-1.0f);
    }
}
