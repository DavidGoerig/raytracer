/*
** apply_rot_translate.c for rt2 in /home/Realague/Delivery/B_MUL/raytracer2/src/parse/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Sat May  6 14:31:57 2017 Julien Delane
** Last update Thu May 18 16:48:04 2017 Julien Delane
*/

#include "parse.h"
#include "rt.h"

void	apply_rot_translate(t_scene *scene)
{
  t_obj	*obj;

  obj = scene->obj;
  while (obj)
    {
      rotate(&obj->quadra, obj->rot);
      translate(&obj->quadra, obj->pos);
      obj = obj->next;
    }
}
