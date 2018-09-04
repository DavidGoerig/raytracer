/*
** option_function.c for rt2 in /home/Realague/Delivery/B_MUL/raytracer2/src/parse/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Fri May 12 15:18:48 2017 Julien Delane
** Last update Wed May 24 16:53:50 2017 Julien Delane
*/

#include "bs.h"
#include "rt.h"

void	parse_ambient(t_scene *scene, char *str)
{
  char	**tab;

  tab = my_str_to_wordtab(str, ",:;");
  scene->option->ambient.x = (float)my_getnbr(tab[0]) / 256.0;
  scene->option->ambient.y = (float)my_getnbr(tab[1]) / 256.0;
  scene->option->ambient.z = (float)my_getnbr(tab[2]) / 256.0;
  my_free_tab(tab);
}

void	parse_ssaa(t_scene *scene, char *str)
{
  scene->option->ssaa = my_getnbr(str);
}

void	parse_reflect(t_scene *scene, char *str)
{
  scene->option->reflect = my_getnbr(str);
}

void	parse_shadow(t_scene *scene, char *str)
{
  scene->option->shadow = my_getnbr(str);
}
