/*
** my_power_rec.c for my_lib in /home/benjamin/Dropbox/func/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Sun Apr  2 19:38:04 2017 Benjamin
** Last update Sat May 20 16:29:43 2017 Julien Delane
*/

#include "bs.h"

int	my_power_rec(int nb, int p)
{
  int	res;

  if (p == 0)
    return (1);
  else if (p < 0)
    return (0);
  else if (p > 1)
    {
      res = my_power_rec(nb, p - 1) * nb;
      if (res < 0)
	return (0);
      else
	return (res);
    }
  else
    return (nb);
}
