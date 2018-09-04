/*
** color.c for rt in /home/baurens/Work/Tek1/Projects/IGRAPH/raytracer2/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu Mar 30 17:38:38 2017 Arthur Baurens
** Last update Sun May 28 19:47:39 2017 Julien Delane
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "rt.h"

sfColor		color_rgba(char r, char g, char b, char a)
{
  sfColor	ret;

  ret.r = r;
  ret.g = g;
  ret.b = b;
  ret.a = a;
  return (ret);
}
