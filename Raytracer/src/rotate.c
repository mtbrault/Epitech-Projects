/*
** rotate.c for  in /home/b00bix/raytracer1/src
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Sun Feb 26 15:39:23 2017 Matthieu BRAULT
** Last update Thu Mar  9 16:46:22 2017 Matthieu BRAULT
*/

#include <math.h>
#include <SFML/Graphics.h>

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	axe1;
  sfVector3f	axe2;
  sfVector3f	axe3;
  float		angle1;
  float		angle2;
  float		angle3;

  angle1 = angles.x * (M_PI / 180);
  angle2 = angles.y * (M_PI / 180);
  angle3 = angles.z * (M_PI / 180);
  axe1.x = to_rotate.x;
  axe1.y = (to_rotate.y * cos(angle1)) + (to_rotate.z * -sin(angle1));
  axe1.z = (to_rotate.y * sin(angle1)) + (to_rotate.z * cos(angle1));
  axe2.x = (axe1.x * cos(angle2)) + (axe1.z * sin(angle2));
  axe2.y = axe1.y;
  axe2.z = (axe1.x * -sin(angle2)) + (axe1.z * cos(angle2));
  axe3.x = (axe2.x * cos(angle3)) + (axe2.y * -sin(angle3));
  axe3.y = (axe2.x * sin(angle3)) + (axe2.y * cos(angle3));
  axe3.z = axe2.z;
  return (axe3);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	axe1;
  sfVector3f	axe2;
  sfVector3f	axe3;
  float		angle1;
  float		angle2;
  float		angle3;

  angle1 = angles.x * (M_PI / 180);
  angle2 = angles.y * (M_PI / 180);
  angle3 = angles.z * (M_PI / 180);
  axe1.x = (to_rotate.x * cos(angle3)) + (to_rotate.y * -sin(angle3));
  axe1.y = (to_rotate.x * sin(angle3)) + (to_rotate.y * cos(angle3));
  axe1.z = to_rotate.z;
  axe2.x = (axe1.x * cos(angle2)) + (axe1.z * sin(angle2));
  axe2.y = axe1.y;
  axe2.z = (axe1.x * -sin(angle2)) + (axe1.z * cos(angle2));
  axe3.x = axe2.x;
  axe3.y = (axe2.y * cos(angle1)) + (axe2.z * -sin(angle1));
  axe3.z = (axe2.y * sin(angle1)) + (axe2.z * cos(angle1));
  return (axe3);
}
