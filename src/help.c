/*
** help.c for help.c in /home/david/Dropbox/raytracer2/src
** 
** Made by David
** Login   <david.goerig@epitech.eu>
** 
** Started on  Fri May 26 13:18:15 2017 David
** Last update Sat May 27 15:42:37 2017 David
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "bs.h"

void	help()
{
  int   fd;
  char  buff[1];
  char  *buffer;
  int   size;

  size = 0;
  if ((fd = open(".help", O_RDONLY)) == -1)
    {
      my_putstr("Problem with the help manual\n");
      return ;
    }
  while (read(fd, buff, 1) > 0)
    ++size;
  close(fd);
  if ((buffer = malloc(sizeof(char) * (size + 1))) == NULL)
    return ;
  if ((fd = open(".help", O_RDONLY)) == -1)
    return ;
  if (read(fd, buffer, size) == -1)
    return ;
  buffer[size] = '\0';
  close(fd);
  my_putstr(buffer);
  free(buffer);
  return ;
}

int	check_arg(int ac, char **av)
{
  int	i;

  i = 1;
  if (ac < 2)
    return (0);
  while (av[i] != NULL)
    {
      if (my_strncmp(av[i], "-help", 5) == 0)
	{
	  help();
	  return (-1);
	}
      ++i;
    }
  return (0);
}
