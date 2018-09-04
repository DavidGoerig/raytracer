/*
** create_light.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon Apr 17 17:00:37 2017 Benjamin
** Last update Fri May 26 10:10:35 2017 Benjamin
*/

#include <stdlib.h>
#include "my_prtf.h"
#include "parse.h"
#include "bs.h"

static void	set_parse(t_light *light)
{
  light->parse.pos = -1;
  light->parse.intensity = -1;
  light->parse.color = -1;
}

static t_light	*create_new_light(t_light *light, char *name, t_parse *parse)
{
  t_light	*tmp;
  t_light	*new;

  if (!(new = malloc(sizeof(t_light))))
    return (NULL);
  my_memset(new, 0, sizeof(t_light));
  light = (light) ? light : new;
  tmp = light;
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
  return (light);
}

int		same_light_name(t_light *light, char *name)
{
  t_light	*tmp;

  tmp = light;
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

int	create_light(char *name, t_light **light, t_parse *parse)
{
  if (same_light_name(*light, name))
    return (-1);
  if (!(*light = create_new_light(*light, name, parse)))
    return (-1);
  return (0);
}
