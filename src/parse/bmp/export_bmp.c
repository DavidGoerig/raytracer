/*
** export_bmp.c for rt2 in /home/Realague/Delivery/B_MUL/raytracer2/src/parse/bmp/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Wed May 24 08:58:29 2017 Julien Delane
** Last update Sun May 28 19:26:23 2017 Benjamin
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "parse.h"
#include "bs.h"

static const char	g_corrpitch[] =
{
  0, 3, 2, 1
};

int		create_header(int height, int width, int fd, int pitch)
{
  t_header_bmp	header;

  header.magic[0] = 'B';
  header.magic[1] = 'M';
  header.offset = sizeof(t_header_bmp);
  header.info.size_info = sizeof(t_bmp_info);
  header.info.bpp = 24;
  header.info.width = width;
  header.info.height = height;
  header.info.nbplans = 1;
  header.info.compression = 0;
  header.info.hres = 0;
  header.info.vres = 0;
  header.info.cpalette = 0;
  header.info.cipalette = 0;
  header.ident = 0;
  header.info.sizeim = 3 * height * width + height * pitch;
  header.size = header.info.sizeim + header.offset;
  if ((write(fd, &header, sizeof(t_header_bmp))) == -1)
    return (84);
  return (0);
}

int		export_pixels(sfUint8 *pixels, int height, int width, int fd)
{
  int		i;
  int		o;
  int		pitch;
  unsigned char	color[3];
  int		pos;

  i = -1;
  pitch = g_corrpitch[(3 * width) % 4];
  while (++i != height)
    {
      o = -1;
      while (++o != width)
	{
	  pos = 4 * ((height - (i + 1)) * width + o);
	  color[2] = pixels[pos];
	  color[1] = pixels[pos + 1];
	  color[0] = pixels[pos + 2];
	  if (write(fd, color, 3) == -1)
	    return (84);
	}
      if (write(fd, &i, pitch) == -1)
	return (84);
    }
  return (0);
}

int		export_bmp(sfUint8 *pixels, int height, int width)
{
  int		fd;
  int		pitch;
  time_t	date;
  char		*temp;
  char		*name;

  pitch = g_corrpitch[(3 * width) % 4];
  date = time(NULL);
  mkdir("screenshots", 0755);
  if ((temp = my_concat("./screenshots/", ctime(&date))) == NULL)
    return (84);
  if ((name = my_concat(temp, ".bmp")) == NULL)
    return (84);
  free(temp);
  if ((fd = open(name, O_WRONLY | O_CREAT, 0644)) == -1)
    return (84);
  if (create_header(height, width, fd, pitch) == 84)
    return (84);
  if ((export_pixels(pixels, height, width, fd)) == 84)
    return (84);
  close(fd);
  free(name);
  return (0);
}
