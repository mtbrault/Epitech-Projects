/*
** my_put_pixel.c for  in /home/b00bix/delivery/Semester2/Infographie/raytracer1/autograder
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Tue Feb  7 13:42:03 2017 Matthieu BRAULT
** Last update Tue Feb  7 13:44:36 2017 Matthieu BRAULT
*/

#include "raytracer1.h"

void	my_put_pixel(t_my_framebuffer *framebuffer, int x, int y, sfColor color)
{
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 0] = color.r;
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
}
