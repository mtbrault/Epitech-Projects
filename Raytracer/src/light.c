/*
** light.c for  in /home/b00bix/raytracer1/src
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Sun Feb 26 15:46:30 2017 Matthieu BRAULT
** Last update Thu Mar 16 16:31:10 2017 Matthieu BRAULT
*/

#include <math.h>
#include "raytracer1.h"

float	get_light_coef(sfVector3f light_vector, sfVector3f normal_vector)
{
  float	norm_light;
  float	norm_vector;
  float	vector_product;
  float	cosinus;

  norm_light = sqrt(pow(light_vector.x, 2) +
  		    pow(light_vector.y, 2) + pow(light_vector.z, 2));
  norm_vector = sqrt(pow(normal_vector.x, 2) +
  		     pow(normal_vector.y, 2) + pow(normal_vector.z, 2));
  if ((norm_light * norm_vector) == 0)
    return (0);
  vector_product = (light_vector.x * normal_vector.x) +
    (light_vector.y * normal_vector.y) + (light_vector.z * normal_vector.z);
  cosinus = vector_product / (norm_light * norm_vector);
  if (cosinus == -1)
    return (0);
  if (cosinus > 1)
    return (1);
  else if (cosinus < 0)
    return (0);
  else
    return (cosinus);
}
