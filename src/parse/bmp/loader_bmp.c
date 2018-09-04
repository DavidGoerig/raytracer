/*
** loader_bmp.c for rt2 in /home/Realague/Delivery/B_MUL/raytracer2/src/parse/bmp/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Mon May 22 17:52:58 2017 Julien Delane
** Last update Sun May 28 19:32:24 2017 Benjamin
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "parse.h"
#include "bs.h"

static const char	g_corrpitch[] =
{
  0, 3, 2, 1
};

static const char	*g_magic[] =
{
  "BM",
  NULL
};

int	get_header(t_header_bmp *header, int fd)
{
  int	i;

  i = -1;
  if (read(fd, header, sizeof(t_header_bmp)) != sizeof(t_header_bmp))
    return (84);
  if (header->info.bpp != 24 || header->info.compression != 0)
    return (84);
  if (header->info.cpalette != 0 || header->info.cipalette != 0)
    return (84);
  while (g_magic[++i] && my_strncmp((char *)g_magic[i],
				    header->magic, 2) != 0);
  if (i == 1)
    return (84);
  return (0);
}

void		load_pixel(t_texture *texture, int fd, t_header_bmp *header)
{
  int		i;
  int		o;
  int		pitch;
  int		pos;
  unsigned char	color[3];

  pitch = g_corrpitch[(3 * texture->width) % 4];
  o = -1;
  while (++o != header->info.height)
    {
      i = -1;
      while (++i != header->info.width)
	{
          texture->pixels[o][i].a = 255;
	  read(fd, color, 3);
	  texture->pixels[o][i].r = color[2];
	  texture->pixels[o][i].g = color[1];
	  texture->pixels[o][i].b = color[0];
	}
      read(fd, &pos, pitch);
    }
}

static int	malloc_texture(t_texture *texture)
{
  int		i;

  i = -1;
  if ((texture->pixels = malloc(sizeof(sfColor *) *
				texture->height)) == NULL)
    return (84);
  while (++i != texture->height)
    {
      if ((texture->pixels[i] = malloc(sizeof(sfColor) *
				       texture->width)) == NULL)
	return (84);
    }
  return (0);
}

t_texture		*loader_bmp(char *file_name)
{
  int			fd;
  t_header_bmp		*header;
  t_texture		*texture;

  if ((header = malloc(sizeof(t_header_bmp))) == NULL)
    return (NULL);
  if ((fd = open(file_name, O_RDONLY)) == -1 || get_header(header, fd) == 84)
    return (NULL);
  if ((texture = malloc(sizeof(t_texture))) == NULL)
    return (NULL);
  texture->width = header->info.width;
  texture->height = header->info.height;
  if (malloc_texture(texture) == 84)
    return (NULL);
  load_pixel(texture, fd, header);
  close(fd);
  free(header);
  return (texture);
}
