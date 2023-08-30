/*
** plance.c for  in /home/b00bix/raytracer1/src
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Sun Feb 26 15:41:30 2017 Matthieu BRAULT
** Last update Sun Mar 19 13:13:27 2017 Matthieu BRAULT
*/

#include <SFML/Graphics.h>

float		intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  float	k;

  if (dir_vector.z == 0)
    return (-1.0f);
  k = (float)(-eye_pos.z / dir_vector.z);
  if (k < 0)
    return (-1.0f);
  return (k);
}

sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	plane;

  upward = upward;
  plane.x = 0;
  plane.y = 0;
  plane.z = 100;
  return (plane);
}
