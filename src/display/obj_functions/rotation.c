/*
** rotation.c for raytracer2 in /home/Realague/Delivery/B_MUL/raytracer2/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Wed Apr 26 10:21:45 2017 Julien Delane
** Last update Sun May 28 18:57:16 2017 Julien Delane
*/

#include <math.h>
#include "rt.h"

static void		rotate_x(t_quadra *quad, double x)
{
  t_quadra		old;

  if (x)
    {
      old = *quad;
      quad->c = old.c * cos(x) * cos(x) + old.d * sin(x) * cos(x)
	  + old.b * sin(x) * sin(x);
      quad->b = old.c * sin(x) *sin(x) + old.b * cos(x) * cos(x)
	  - old.d * sin(x) * cos(x);
      quad->d = -2 * old.c * cos(x) * sin(x) + 2 * old.b * cos(x) * sin(x)
	  - old.d * sin(x) * sin(x);
      quad->e = old.e * cos(x) - old.f * sin(x);
      quad->f = old.e * sin(x) + old.f * cos(x);
      quad->h = 2 * old.d * cos(x) * cos(x) + old.h * cos(x) + old.i * sin(x);
      quad->i = -old.h * sin(x) + old.i * cos(x);
    }
}

static void		rotate_y(t_quadra *quad, double y)
{
  t_quadra		old;

  if (y)
    {
      old = *quad;
      quad->a = quad->a * ((1.0 + cos(2.0 * y)) / 2.0) + quad->b *
	((1.0 - cos(2.0 * y)) / 2.0) - quad->e * cos(y) * sin(y);
      quad->b = old.a * ((1.0 - cos(2.0 * y)) / 2.0) + quad->b *
	((1.0 + cos(2.0 * y)) / 2.0) + quad->e * cos(y) * sin(y);
      quad->d = quad->d * cos(y) + quad->f * sin(y);
      quad->e = 2.0 * old.a * cos(y) * sin(y) - 2.0 * old.b *
	cos(y) * sin(y) + quad->e * ((1.0 + cos(2.0 * y)) / 2.0) -
	quad->e * ((1.0 - cos(2.0 * y)) / 2.0);
      quad->f = -old.d * sin(y) + quad->f * cos(y);
    }
}

static void		rotate_z(t_quadra *quad, double z)
{
  t_quadra		old;

  if (z)
    {
      old = *quad;
      quad->a = quad->a * ((1.0 + cos(2.0 * z)) / 2.0) + quad->c *
	((1.0 - cos(2.0 * z)) / 2.0) + quad->f * sin(z) * cos(z);
      quad->c = old.a * ((1.0 - cos(2.0 * z)) / 2.0) + quad->c *
	((1.0 + cos(2.0 * z)) / 2.0) - quad->f * sin(z) * cos(z);
      quad->f = 2.0 * (old.a - old.c) * sin(z) * cos(z) + quad->f *
	(((1.0 + cos(2.0 * z)) / 2.0) - ((1.0 - cos(2.0 * z)) / 2.0));
      quad->d = quad->d * cos(z) - quad->e * sin(z);
      quad->e = old.d * sin(z) + quad->e * cos(z);
      quad->g = quad->g * cos(z) + quad->h * sin(z);
      quad->h = -old.g * sin(z) + quad->h * cos(z);
    }
}

void	rotate(t_quadra *quad, t_vec3f rotation)
{
  rotate_z(quad, TO_RAD(-rotation.z));
  rotate_y(quad, TO_RAD(-rotation.y));
  rotate_x(quad, TO_RAD(-rotation.x));
}
