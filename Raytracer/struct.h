/*
** struct.h for  in /home/b00bix/raytracer1
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Tue Feb 28 18:52:44 2017 Matthieu BRAULT
** Last update Thu Mar 16 18:08:57 2017 Matthieu BRAULT
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

typedef struct		s_my_framebuffer
{
  sfUint8	*pixels;
  int		width;
  int		height;
  sfVector3f	eye_pos;
  sfVector2i	pos;
}			t_my_framebuffer;

typedef struct		s_sf_function
{
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
  sfEvent		event;
}			t_sf_function;

typedef struct		s_form
{
  float		cone;
  float		cylinder;
  float		sphere;
  float		plane;
  sfVector3f	light_vector;
  sfVector3f	normal_cone;
  sfVector3f	normal_cylinder;
  sfVector3f	normal_sphere;
  sfVector3f	normal_plane;
}			t_form;

#endif /* !STRUCT_H_ */
