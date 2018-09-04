/*
** get_next_line.c for get_next_line in /home/prodjia/Dropbox/CPE_2016_getnextline
**
** Made by Benjamin
** Login   <prodjia@epitech.net>
**
** Started on  Mon Jan  2 10:33:24 2017 Benjamin
** Last update Wed May 24 11:11:53 2017 Benjamin
*/

#include <stdlib.h>
#include <unistd.h>
#include "gnl.h"
#include "bs.h"

char	*my_addstring(char *str, char c)
{
  char	*new;
  int	i;
  int	j;

  i = -1;
  j = my_strlen(str);
  if ((new = malloc(sizeof(char) * (j + 2))) == NULL)
    return (NULL);
  while (++i < j)
    new[i] = str[i];
  new[i] = c;
  new[i + 1] = 0;
  free(str);
  return (new);
}

char	*get_next_line(int fd)
{
  char	c;
  char	*str;

  str = NULL;
  c = 0;
  while (fd >= 0 && read(fd, &c, 1) > 0 && (c != '\n' && c!= '\0'))
    str = my_addstring(str, c);
  if (!str && c == '\n')
    str = my_addstring(str, 0);
  return (str);
}
