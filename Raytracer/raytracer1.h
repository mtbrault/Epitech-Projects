/*
** raytracer1.h for  in /home/b00bix/delivery/Semester2/Infographie/raytracer1
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Tue Feb  7 13:39:46 2017 Matthieu BRAULT
** Last update Thu Mar 16 18:44:57 2017 Matthieu BRAULT
*/

#ifndef RAYTRACER1_H_
# define RAYTRACER1_H_

#include <SFML/Graphics.h>
#include "struct.h"

sfVector3f	calc_dir_vector(float dist_to_plane, sfVector2i screen_size, sfVector2i screen_pos);
void		my_translate(t_my_framebuffer *buffer, t_sf_function *sf, t_form *form);
sfVector3f	translate(sfVector3f to_translate, sfVector3f translations);
sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles);
sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles);

/*  ********************  **
**     Normal Vector      **
**  ********************  **
*/

sfVector3f	get_normal_sphere(sfVector3f intersection_point);
sfVector3f	get_normal_plane(int upward);
sfVector3f	get_normal_cylinder(sfVector3f intersection_point);
sfVector3f	get_normal_cone(sfVector3f intersection_point, float semiangle);

/*  ********************  **
**       Intersection     **
**  ********************  **
*/

float		intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector);
float		result(sfVector3f abc, float delta);
float		intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector, float radius);
float		intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector, float radius);
float		intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector, float semiangle);

/*  ********************  **
**      Light             **
**  ********************  **
*/

float		get_light_coef(sfVector3f light_vector, sfVector3f normal_vector);
void		my_put_pixel(t_my_framebuffer *framebuffer, int x, int y, sfColor color);
void		my_calculate(t_my_framebuffer *buffer, t_form *form);
void		my_cone(t_form *form, t_my_framebuffer *buff, sfVector2i pos, sfVector3f l);
void		my_sphere(t_form *form, t_my_framebuffer *buff, sfVector2i pos, sfVector3f l);
void		my_cylinder(t_form *f, t_my_framebuffer *buff, sfVector2i pos, sfVector3f l);
void		my_plane(t_form *form, t_my_framebuffer *buff, sfVector2i pos, sfVector3f l);

#endif /* !RAYTRACER1_H_ */
