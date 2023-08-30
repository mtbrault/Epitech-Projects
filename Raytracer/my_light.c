/*
** my_light.c for  in /home/b00bix/raytracer1
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Thu Mar 16 18:04:57 2017 Matthieu BRAULT
** Last update Thu Mar 16 18:36:42 2017 Matthieu BRAULT
*/

#include <SFML/Graphics.h>
#include "raytracer1.h"

sfVector3f	get_light_vector(sfVector3f light, sfVector3f point)
{
  sfVector3f	vector;

  vector.x = point.x - light.x;
  vector.y = point.y - light.y;
  vector.z = point.z - light.z;
  return (vector);
}

void	my_cone(t_form *form, t_my_framebuffer *buff, sfVector2i pos,
		sfVector3f light_point)
{
  sfVector3f	intersect_point;
  float		light_coef;

  intersect_point = ((sfVector3f) {pos.x, pos.y, form->cone});
  form->light_vector = get_light_vector(light_point, intersect_point);
  light_coef = get_light_coef(form->light_vector, form->normal_cone);
  buff->pixels[(buff->width * pos.x + pos.y) * 4] = sfRed.r * light_coef;
  buff->pixels[(buff->width * pos.x + pos.y) * 4 + 1] = sfRed.g * light_coef;
  buff->pixels[(buff->width * pos.x + pos.y) * 4 + 2] = sfRed.b * light_coef;
  buff->pixels[(buff->width * pos.x + pos.y) * 4 + 3] = sfRed.a * light_coef;
}

void	my_sphere(t_form *form, t_my_framebuffer *buff, sfVector2i pos,
		sfVector3f light_point)
{
  sfVector3f	intersect_point;
  float		light_coef;

  intersect_point = ((sfVector3f) {pos.x, pos.y, form->sphere});
  form->normal_sphere = get_normal_sphere((sfVector3f)
					  {pos.y, pos.x, form->sphere});
  form->light_vector = get_light_vector(light_point, intersect_point);
  light_coef = get_light_coef(form->light_vector, form->normal_sphere);
  buff->pixels[(buff->width * pos.x + pos.y) * 4] = sfGreen.r * light_coef;
  buff->pixels[(buff->width * pos.x + pos.y) * 4 + 1] = sfGreen.g * light_coef;
  buff->pixels[(buff->width * pos.x + pos.y) * 4 + 2] = sfGreen.b * light_coef;
  buff->pixels[(buff->width * pos.x + pos.y) * 4 + 3] = sfGreen.a * light_coef;
}

void	my_cylinder(t_form *form, t_my_framebuffer *buff, sfVector2i pos,
		sfVector3f light_point)
{
  sfVector3f	intersect_point;
  float		light_coef;

  intersect_point = ((sfVector3f) {pos.x, pos.y, form->sphere});
  form->normal_cylinder = get_normal_cylinder((sfVector3f)
					      {pos.y, pos.x, form->cylinder});
  form->light_vector = get_light_vector(light_point, intersect_point);
  light_coef = get_light_coef(form->light_vector, form->normal_cylinder);
  buff->pixels[(buff->width * pos.x + pos.y) * 4] = sfYellow.r * light_coef;
  buff->pixels[(buff->width * pos.x + pos.y) * 4 + 1] = sfYellow.g * light_coef;
  buff->pixels[(buff->width * pos.x + pos.y) * 4 + 2] = sfYellow.b * light_coef;
  buff->pixels[(buff->width * pos.x + pos.y) * 4 + 3] = sfYellow.a * light_coef;
}

void	my_plane(t_form *form, t_my_framebuffer *buff, sfVector2i pos,
		sfVector3f light_point)
{
  sfVector3f	intersect_point;
  float		light_coef;

  intersect_point = ((sfVector3f) {pos.x, pos.y, form->plane});
  form->normal_plane = get_normal_plane(0);
  form->light_vector = get_light_vector(light_point, intersect_point);
  light_coef = get_light_coef(form->light_vector, form->normal_plane);
  buff->pixels[(buff->width * pos.x + pos.y) * 4] = sfBlue.r * light_coef;
  buff->pixels[(buff->width * pos.x + pos.y) * 4 + 1] = sfBlue.g * light_coef;
  buff->pixels[(buff->width * pos.x + pos.y) * 4 + 2] = sfBlue.b * light_coef;
  buff->pixels[(buff->width * pos.x + pos.y) * 4 + 3] = sfBlue.a * light_coef;
}
