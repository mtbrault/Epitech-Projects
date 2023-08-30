/*
** translate.c for  in /home/b00bix/raytracer1/src
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Sun Feb 26 15:37:47 2017 Matthieu BRAULT
** Last update Mon Mar  6 12:06:33 2017 Matthieu BRAULT
*/

#include <SFML/Graphics.h>
#include "raytracer1.h"

sfVector3f	translate(sfVector3f to_translate, sfVector3f translations)
{
  sfVector3f	trans;

  trans.x = translations.x + to_translate.x;
  trans.y = translations.y + to_translate.y;
  trans.z = translations.z + to_translate.z;
  return (trans);
}
