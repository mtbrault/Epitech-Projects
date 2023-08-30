/*
** calculate.c for  in /home/b00bix/delivery/Semester2/Infographie/raytracer1
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Thu Feb  9 14:51:38 2017 Matthieu BRAULT
** Last update Sat Mar 18 00:28:56 2017 Matthieu BRAULT
*/

#include <SFML/Graphics.h>
#include "struct.h"
#include "raytracer1.h"

void	my_aff(t_form *form, t_my_framebuffer *buffer,
	       sfVector2i pos)
{
  sfVector3f	light_point;

  light_point = ((sfVector3f) {0, -100, 50});
  if (form->plane > 0)
    my_plane(form, buffer, pos, light_point);
  if (form->sphere > 0)
    my_sphere(form, buffer, pos, light_point);
  if (form->cylinder > 0)
    my_cylinder(form, buffer, pos, light_point);
  if (form->cone > 0)
    my_cone(form, buffer, pos, light_point);
}

void	my_calculate(t_my_framebuffer *buffer, t_form *form)
{
  sfVector3f	dir_vector;
  sfVector2i	coord;
  sfVector2i	screen_size;

  buffer->pos.x = 0;
  screen_size = ((sfVector2i) {buffer->width, buffer->height});
  while (buffer->pos.x <= screen_size.y)
    {
      buffer->pos.y = 0;
      while (buffer->pos.y <= screen_size.x)
	{
	  coord = ((sfVector2i) {buffer->pos.y, buffer->pos.x});
	  dir_vector = calc_dir_vector(500, screen_size, coord);
	  form->sphere = intersect_sphere(buffer->eye_pos, dir_vector, 100);
	  form->cylinder = intersect_cylinder(buffer->eye_pos, dir_vector, 50);
	  form->plane = intersect_plane(buffer->eye_pos, dir_vector);
	  form->cone = intersect_cone(buffer->eye_pos, dir_vector, 40);
	  form->normal_cone = get_normal_cone(((sfVector3f)
	    {buffer->pos.y, buffer->pos.x, form->cone}), 40);
	  my_aff(form, buffer, buffer->pos);
	  buffer->pos.y = buffer->pos.y + 1;
	}
      buffer->pos.x = buffer->pos.x + 1;
    }
}
