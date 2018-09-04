/*
** output.c for rt in /home/baurens/Work/Tek1/Projects/IGRAPH/raytracer2/src/display/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Wed May 24 20:01:38 2017 Arthur Baurens
** Last update Thu May 25 09:48:42 2017 Julien Delane
*/

#include <unistd.h>
#include "rt.h"

void		take_screenshot(t_prog *prog)
{
  export_bmp(prog->pix, prog->h, prog->w);
  write(1, "Screenshot saved in 'screenshot' directory\n", 43);
}
