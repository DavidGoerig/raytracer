/*
** light.c for rt2 in /home/benjamin/Dropbox/raytracer2/src/parse/check/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Wed May 24 09:50:57 2017 Benjamin
** Last update Thu May 25 16:39:41 2017 Benjamin
*/

#include <stdlib.h>
#include "my_prtf.h"
#include "parse.h"
#include "gnl.h"
#include "bs.h"

static void	fix_light_name(t_light *light)
{
  char		*str;

  str = NULL;
  while (light->parse.name)
    {
      my_printf(EX_NAME, light->parse.name, light->name);
      str = get_next_line(0);
      if (!is_str_anum(str))
	{
	  if (light->name)
	    free (light->name);
	  light->name = my_strdup(str);
	  light->parse.name = 0;
	}
      free(str);
    }
}

static void	fix_light_pos(t_light *light)
{
  char		**tab;
  char		*str;

  str = NULL;
  while (light->parse.pos)
    {
      my_printf(EX_POS, light->parse.pos, light->name, MAX_POS, MAX_POS);
      str = get_next_line(0);
      str = (char *)multi_fruit((long)my_strcat("X ", str), 1, str);
      tab = my_str_to_wordtab(str, " ");
      set_light_pos(light, tab, light->parse.pos);
      free(str);
      my_free_tab(tab);
    }
}

static void	fix_light_intens(t_light *light)
{
  char		**tab;
  char		*str;

  str = NULL;
  while (light->parse.intensity)
    {
      my_printf(EX_INTENS, light->parse.intensity, light->name, MAX_POS);
      str = get_next_line(0);
      str = (char *)multi_fruit((long)my_strcat("X ", str), 1, str);
      tab = my_str_to_wordtab(str, " ");
      set_light_intensity(light, tab, light->parse.intensity);
      free(str);
      my_free_tab(tab);
    }
}

static void	fix_light_color(t_light *light)
{
  char		**tab;
  char		*str;

  str = NULL;
  while (light->parse.color)
    {
      my_printf(EX_COLOR, light->parse.color, light->name);
      str = get_next_line(0);
      str = (char *)multi_fruit((long)my_strcat("X ", str), 1, str);
      tab = my_str_to_wordtab(str, " ");
      set_light_color(light, tab, light->parse.color);
      free(str);
      my_free_tab(tab);
    }
}

int	check_light(t_light *light)
{
  while (light)
    {
      light->parse.name ? fix_light_name(light) : 0;
      light->parse.pos ? fix_light_pos(light) : 0;
      light->parse.intensity ? fix_light_intens(light) : 0;
      light->parse.color ? fix_light_color(light) : 0;
      light = light->next;
    }
  return (0);
}
