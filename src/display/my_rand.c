/*
** my_rand.c for rt2 in /home/Realague/Delivery/B_MUL/raytracer2/src/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Fri May 12 18:34:59 2017 Julien Delane
** Last update Wed May 24 17:23:08 2017 Julien Delane
*/

#include "rt.h"

int			my_rand()
{
  static unsigned int	random = 8;
  static int		i = 0;
  unsigned int		a;
  unsigned int		b;
  unsigned int		m;

  if (i == 0)
    {
      random = time(NULL);
      i = 1;
    }
  b = 0;
  a = 16807;
  m = 0x7FFFFFFF;
  random = (a * random + b) % m;
  return (random);
}

t_vec3f		vec3_random()
{
  t_vec3f	r;

  r.x = ((float)my_rand() / (float)(0x7FFFFFFF)) * 1.0 - 0.5;
  r.y = ((float)my_rand() / (float)(0x7FFFFFFF)) * 1.0 - 0.5;
  r.z = ((float)my_rand() / (float)(0x7FFFFFFF)) * 1.0 - 0.5;
  return (r);
}
