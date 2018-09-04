/*
** create_mat.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon Apr 17 16:58:45 2017 Benjamin
** Last update Sun May 28 18:41:19 2017 Julien Delane
*/

#include <stdlib.h>
#include "my_prtf.h"
#include "parse.h"
#include "bs.h"

static void	set_parse(t_mat *mat)
{
  mat->parse.transparency = -1;
  mat->parse.reflect = -1;
  mat->parse.refract = -1;
  mat->parse.shine = -1;
  mat->parse.texture = 0;
  mat->tex_coef = 1;
}

static t_mat	*create_new_mat(t_mat *mat, char *name, t_parse *parse)
{
  t_mat		*tmp;
  t_mat		*new;

  if (!(new = malloc(sizeof(t_mat))))
    return (NULL);
  my_memset(new, 0, sizeof(t_mat));
  mat = (mat) ? mat : new;
  tmp = mat;
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
  return (mat);
}

int		same_mat_name(t_mat *mat, char *name)
{
  t_mat		*tmp;

  tmp = mat;
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

int	create_mat(char *name, t_mat **mat, t_parse *parse)
{
  if (same_mat_name(*mat, name))
    return (-1);
  if (!(*mat = create_new_mat(*mat, name, parse)))
    return (-1);
  return (0);
}
