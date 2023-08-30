/*
** cylinder.c for  in /home/b00bix/raytracer1/src
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Sun Feb 26 15:42:26 2017 Matthieu BRAULT
** Last update Thu Mar  9 16:45:29 2017 Matthieu BRAULT
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "raytracer1.h"

float		intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector,
				   float radius)
{
  sfVector3f	abc;
  float		delta;

  if (radius <= 0)
    return (-1.0f);
  abc.x = pow(dir_vector.x, 2.0) + pow(dir_vector.y, 2.0);
  abc.y = 2.0 * eye_pos.x * dir_vector.x + 2.0 * eye_pos.y * dir_vector.y;
  abc.z = pow(eye_pos.x, 2.0) + pow(eye_pos.y, 2.0) - pow(radius, 2.0);
  if (abc.x == 0 && abc.y == 0 && abc.z == 0)
    return (-1.0f);
  if (abc.x == 0)
    return (-1.0f);
  delta = pow(abc.y, 2.0) - 4 * abc.x * abc.z;
  return (result(abc, delta));
}

sfVector3f	get_normal_cylinder(sfVector3f intersection_point)
{
  sfVector3f	cylinder;

  cylinder.x = intersection_point.x;
  cylinder.y = intersection_point.y;
  cylinder.z = 0;
  return (cylinder);
}
