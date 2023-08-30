/*
** cone.c for  in /home/b00bix/raytracer1/src
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Sun Feb 26 15:44:24 2017 Matthieu BRAULT
** Last update Sat Mar 18 00:21:48 2017 Matthieu BRAULT
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "raytracer1.h"

float		intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector,
			       float semiangle)
{
  sfVector3f	abc;
  float		angle;
  float		powtan;
  float		delta;

  if (semiangle <= 0 || semiangle >= 90)
    return (-1.0f);
  angle = (M_PI / 2.0) - (semiangle * M_PI / 180);
  if ((powtan = pow(tan(angle), 2.0)) == 0)
    return (-1.0f);
  abc.x = pow(dir_vector.x, 2.0) + pow(dir_vector.y, 2.0)
    - (pow(dir_vector.z, 2.0) / powtan);
  abc.y = (2.0 * eye_pos.x * dir_vector.x) + (2.0 * eye_pos.y * dir_vector.y)
    - (2.0 * eye_pos.z * dir_vector.z / powtan);
  abc.z = pow(eye_pos.x, 2.0) + pow(eye_pos.y, 2.0) -
    pow(eye_pos.z, 2.0) / powtan;
  if (abc.x == 0 && abc.y == 0 && abc.z == 0)
    return (-1.0f);
  if (abc.x == 0)
    return (-1.0f);
  delta = pow(abc.y, 2.0) - 4 * abc.x * abc.z;
  return (result(abc, delta));
}

sfVector3f	get_normal_cone(sfVector3f intersection_point, float semiangle)
{
  sfVector3f	cone;

  semiangle = (M_PI / 2.0) - (semiangle * M_PI / 180);
  cone.x = intersection_point.x;
  cone.y = intersection_point.y;
  cone.z = intersection_point.z * -semiangle;
  return (cone);
}
