/*
** is_str_num.c for mylib in /home/benjamin/Dropbox/dante/lib/lib_benjaminsolca/my/is_it/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Tue Apr 25 10:06:03 2017 Benjamin
** Last update Thu May  4 10:25:45 2017 Benjamin
*/

#include "bs.h"

int	is_str_num(char *str)
{
  int	i;
  int	comas;

  i = -1;
  comas = 0;
  if (str[my_strlen(str) - 1] == ',' ||
      str[my_strlen(str) - 1] == '.')
    return (2);
  if (str[0] == '-')
    i++;
  while (str[++i] != '\0')
    {
      if (str[i] == ',' || str[i] == '.')
	comas++;
      if (is_num(str[i]) != 1 || comas > 1)
	return (1);
    }
  return (0);
}
