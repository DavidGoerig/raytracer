/*
** multi_fruit.c for bs in /home/benjamin/Dropbox/raytracer2/lib/lib_benjaminsolca/my/free_it/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Thu May 25 15:02:04 2017 Benjamin
** Last update Thu May 25 15:09:52 2017 Benjamin
*/

#include <stdarg.h>
#include <stdlib.h>

long int	multi_fruit(long int ret, int nb, ...)
{
  int			i;
  va_list	lst;
  void		*ptr;

  i = -1;
  if (nb == 0)
    return (ret);
  va_start(lst, nb);
  while (++i < nb)
    {
      ptr = va_arg(lst, void *);
      free(ptr);
    }
  va_end(lst);
  return (ret);
}
