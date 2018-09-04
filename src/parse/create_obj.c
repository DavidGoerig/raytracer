/*
** create_obj.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon Apr 17 17:01:21 2017 Benjamin
** Last update Sun May 28 19:00:37 2017 Julien Delane
*/

#include <stdlib.h>
#include "my_prtf.h"
#include "parse.h"
#include "bs.h"

static void	set_parse(t_obj *obj)
{
  obj->parse.mat = -1;
  obj->parse.quad = -1;
  obj->parse.color = -1;
  obj->parse.pos = -1;
  obj->parse.rot = -1;
  obj->parse.mapping = -1;
}

static t_obj	*create_new_obj(t_obj *obj, char *name, t_parse *parse)
{
  t_obj		*tmp;
  t_obj		*new;

  if (!(new = malloc(sizeof(t_obj))))
    return (NULL);
  my_memset(new, 0, sizeof(t_obj));
  obj = (obj) ? obj : new;
  tmp = obj;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = (tmp == new) ? 0 : new;
  new->prev = (tmp == new) ? 0 : tmp;
  new->name = my_strdup(name);
  if (is_str_anum(name))
    new->parse.name = parse->line;
  else
    new->parse.name = 0;
  set_parse(new);
  new->mapping = M_NONE;
  return (obj);
}

int		same_obj_name(t_obj *obj, char *name)
{
  t_obj		*tmp;

  tmp = obj;
  if (!tmp)
    return (0);
  while (tmp->prev)
    tmp = tmp->prev;
  while (tmp)
    {
      if (my_strcmp(tmp->name, name) == 0)
	{
	  my_printf("%s is seen two time.\n", name);
	  return (1);
	}
      tmp = tmp->next;
    }
  return (0);
}

int	create_obj(char *name, t_obj **obj, t_parse *parse)
{
  if (same_obj_name(*obj, name))
    return (-1);
  if (!(*obj = create_new_obj(*obj, name, parse)))
    return (-1);
  return (0);
}
