/*
** get_float.c for lib in /home/benjamin/Dropbox/raytracer2/lib/lib_benjaminsolca/my_printf/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Sun May 28 22:10:29 2017 Benjamin
** Last update Sun May 28 22:57:16 2017 Benjamin
*/

#include <stdlib.h>
#include "my_prtf.h"
#include "bs.h"

static int     sizeint(int i)
{
  int   j;

  j = 0;
  if (i == 0)
    return (1);
  else
    {
      while (i > 0)
    {
      i = i / 10;
      j = j + 1;
    }
    }
  return (j);
}

static char    *int_str(int nbr)
{
  int   size;
  char  *str;
  int   i;
  int   ret;

  i = - 1;
  size = sizeint(nbr);
  ret = size - 1;
  if ((str = malloc(sizeof(char) * size + 1)) == NULL)
    return (NULL);
  while (++i < size)
    {
      str[ret] = (nbr % 10) + '0';
      ret = ret - 1;
      nbr = nbr / 10;
    }
  str[size] = '\0';
  return (str);
}

static char *get_coma(float nbr)
{
  char *str;
  int   i;

  i = -1;
  str = my_strdup("000");
  while (str[++i] != '\0')
    {
      str[i] = ((int)(nbr * 10) % 10) + '0';
      nbr = nbr * 10.0;
    }
  return (str);
}

char    *float_str(float nbr)
{
  int   ipart;
  float fpart;
  char  *first;
  char  *last;

  ipart = (int)nbr;
  fpart = nbr - (float)ipart;
  first = int_str(ipart);
  last = get_coma(fpart);
  return (my_strcat(first, my_strcat(".", last)));
}
