/*
** clear_window.c for  in /home/b00bix/raytracer1
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Thu Mar 16 13:38:19 2017 Matthieu BRAULT
** Last update Thu Mar 16 18:20:44 2017 Matthieu BRAULT
*/

#include <raytracer1.h>

void	clear_window(t_my_framebuffer *buffer)
{
  int	x;
  int	y;

  x = 0;
  while (x <= buffer->height)
    {
      y = 0;
      while (y <= buffer->width)
	{
	  my_put_pixel(buffer, y, x, sfBlack);
	  y = y + 1;
	}
      x = x + 1;
    }
}

void	my_translate2(t_my_framebuffer *buff, t_sf_function *sf, t_form *form)
{
  if (sfKeyboard_isKeyPressed(sfKeyRight))
    {
      buff->eye_pos = translate(buff->eye_pos, ((sfVector3f) {0, -100, 0}));
      clear_window(buff);
      my_calculate(buff, form);
      sfTexture_updateFromPixels(sf->texture, buff->pixels, buff->width,
				 buff->height, 0, 0);
    }
  if (sfKeyboard_isKeyPressed(sfKeyLeft))
    {
      buff->eye_pos = translate(buff->eye_pos, ((sfVector3f) {0, 100, 0}));
      clear_window(buff);
      my_calculate(buff, form);
      sfTexture_updateFromPixels(sf->texture, buff->pixels, buff->width,
				 buff->height, 0, 0);
    }
  if (sfKeyboard_isKeyPressed(sfKeyUp))
    {
      buff->eye_pos = translate(buff->eye_pos, ((sfVector3f) {100, 0, 0}));
      clear_window(buff);
      my_calculate(buff, form);
      sfTexture_updateFromPixels(sf->texture, buff->pixels, buff->width,
				 buff->height, 0, 0);
    }
}
void	my_translate(t_my_framebuffer *buff, t_sf_function *sf, t_form *form)
{
  if (sfKeyboard_isKeyPressed(sfKeyDown))
    {
      buff->eye_pos = translate(buff->eye_pos, ((sfVector3f) {-100, 0, 0}));
      clear_window(buff);
      my_calculate(buff, form);
      sfTexture_updateFromPixels(sf->texture, buff->pixels, buff->width,
				 buff->height, 0, 0);
    }
  if (sfKeyboard_isKeyPressed(sfKeySpace))
    {
      buff->eye_pos = translate(buff->eye_pos, ((sfVector3f) {0, 0, 100}));
      clear_window(buff);
      my_calculate(buff, form);
      sfTexture_updateFromPixels(sf->texture, buff->pixels, buff->width,
				 buff->height, 0, 0);
    }
  if (sfKeyboard_isKeyPressed(sfKeyLControl))
    {
      buff->eye_pos = translate(buff->eye_pos, ((sfVector3f) {0, 0, -100}));
      clear_window(buff);
      my_calculate(buff, form);
      sfTexture_updateFromPixels(sf->texture, buff->pixels, buff->width,
				 buff->height, 0, 0);
    }
  my_translate2(buff, sf, form);
}
