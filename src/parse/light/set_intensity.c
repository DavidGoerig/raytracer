/*
** set_intensity.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/light/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon May  1 14:46:03 2017 Benjamin
** Last update Thu May 25 14:42:30 2017 Benjamin
*/

#include "parse.h"
#include "bs.h"

int	set_light_intensity(t_light *light, char **tab, int nb_line)
{
  if (tab && cnt_line_tab(tab) > 1 && !is_str_num(tab[1]) &&
      my_getnbr(tab[1]) >= 0 && my_getnbr(tab[1]) <= MAX_INTENS)
    {
      light->parse.intensity = 0;
      light->intensity = my_getnbr(tab[1]);
      return (0);
    }
  light->parse.intensity = nb_line;
  return (1);
}
