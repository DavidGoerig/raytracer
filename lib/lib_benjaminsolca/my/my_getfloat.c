/*
** my_get_float.c for bs in /home/benjamin/Dropbox/raytracer2/lib/lib_benjaminsolca/my/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Thu May  4 10:27:10 2017 Benjamin
** Last update Fri May  5 09:25:28 2017 Benjamin
*/

#include <math.h>
#include "bs.h"

static int      count_size_nbr(int nbr)
{
  int           count;

  count = 0;
  if (nbr == 0)
    return (-1);
  while (nbr > 0)
    {
      ++count;
      nbr /= 10;
    }
  return (-count);
}

static int	is_there_a_coma(char *str)
{
  int		i;
  int		count;

  count = 0;
  i = -1;
  while (str[++i] != '\0')
    if (str[i] == '.' || str[i] == ',')
      ++count;
  if (count == 0)
    return (0);
  if (count >= 2)
    return (-1);
  return (1);
}

float	my_getfloat(char *str)
{
  char  **tab;
  int	nbr;
  int   coma;
  float c;

  if (is_there_a_coma(str) == 0)
    return (my_getnbr(str));
  tab = my_str_to_wordtab(str, ".,");
  if (cnt_line_tab(tab) == 1)
    return (my_getnbr(tab[0]));
  if (cnt_line_tab(tab) > 2)
    return (42.42);
  nbr = my_getnbr(tab[0]);
  coma = my_getnbr(tab[1]);
  c = coma * pow(10, count_size_nbr(coma));
  return (nbr + c);
}
