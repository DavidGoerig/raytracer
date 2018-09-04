/*
** is_str_printable.c for bs in /home/benjamin/Dropbox/raytracer2/lib/lib_benjaminsolca/my/is_it/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Thu May  4 09:51:40 2017 Benjamin
** Last update Thu May  4 09:52:07 2017 Benjamin
*/

#include "bs.h"

int	is_str_printable(char *str)
{
  int	i;

  i = -1;
  if (str[0] == '-')
    i++;
  while (str[++i] != '\0')
    {
      if (is_printable(str[i]) != 1)
	return (1);
    }
  return (0);
}
