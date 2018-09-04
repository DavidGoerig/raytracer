/*
** list_to_tab.c for rt2 in /home/Realague/Delivery/B_MUL/raytracer2/src/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Mon May  1 21:28:02 2017 Julien Delane
** Last update Sun May 28 18:59:10 2017 Julien Delane
*/

#include <stdlib.h>
#include "rt.h"
#include "bs.h"

static t_light	*table_light(t_scene *scene, t_light *light)
{
  int		nb;
  t_light	*new;
  t_light	*tmp;

  nb = 0;
  tmp = light;
  while (tmp)
    {
      ++nb;
      tmp = tmp->next;
    }
  scene->nb_light = nb;
  if ((new = malloc(sizeof(t_light) * nb)) == NULL)
    return (NULL);
  nb = -1;
  while (++nb != scene->nb_light)
    {
      new[nb] = *light;
      tmp = light;
      light = light->next;
      free(tmp);
    }
  return (new);
}

static t_mat	*find_mat(char *str, t_scene *scene)
{
  t_mat		*mat;

  mat = scene->mat;
  while (mat)
    {
      if (my_strcmp(str, mat->name) == 0)
	return (mat);
      mat = mat->next;
    }
  return (NULL);
}

static t_obj	*table_obj(t_scene *scene, t_obj *obj)
{
  int		nb;
  t_obj		*new;
  t_obj		*tmp;

  nb = 0;
  tmp = obj;
  while (tmp)
    {
      ++nb;
      tmp = tmp->next;
    }
  scene->nb_obj = nb;
  if ((new = malloc(sizeof(t_obj) * nb)) == NULL)
    return (NULL);
  nb = -1;
  while (++nb != scene->nb_obj)
    {
      new[nb] = *obj;
      new[nb].mat = find_mat(obj->mat_name, scene);
      tmp = obj;
      obj = obj->next;
      free(tmp);
    }
  return (new);
}

int	list_to_tab(t_scene *scene)
{
  if ((scene->light = table_light(scene, scene->light)) == NULL)
    return (-1);
  else if ((scene->obj = table_obj(scene, scene->obj)) == NULL)
    return (-1);
  return (0);
}
