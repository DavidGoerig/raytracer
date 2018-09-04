/*
** parse.c for raytracer2 in /home/benjamin/Dropbox/raytracer2
**
** Made by
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon Apr 17 11:14:00 2017
** Last update Mon Apr 17 11:25:31 2017 Benjamin
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "parse.h"
#include "bs.h"
#include "gnl.h"
#include "my_prtf.h"

static int	check_empty_line(char *str)
{
  int		i;
  int		count;

  i = -1;
  count = 0;
  while (str[++i])
    {
      if (str[i] != ' ' && str[i] != '\t')
	{
	  count++;
	}
    }
  return (count);
}

static char	**get_gnl(int fd, t_parse *parse)
{
  char		**tab;
  char		*gnl;
  char		*str;
  int		b;

  tab = NULL;
  gnl = NULL;
  str = NULL;
  b = 0;
  while ((gnl = get_next_line(fd)) && !check_empty_line(gnl))
    {
      parse->line++;
      b = 1;
      free(gnl);
    }
  if (b == 0)
    parse->line++;
  if (gnl)
    {
      str = my_epur_str(gnl);
      tab = my_str_to_wordtab(str, " :;");
      free(str);
    }
  return (tab);
}

int	parse_file(int ac, char **av, t_parse *parse, t_scene *scene)
{
  int	fd;
  int	ret;
  char	**tab;

  parse->opt = 0;
  parse->line = -1;
  my_memset(scene, 0, sizeof(t_scene));
  if (ac < 2)
    return ((my_printf("Use: ./raytracer [file]\n") == 0 ? 0 : 0));
  if ((fd = open(av[1], O_RDONLY)) == -1)
    return (84);
  while ((tab = get_gnl(fd, parse)))
    {
      ret = parse_what_to_do(tab, parse, scene);
      if (ret)
	return (ret);
      my_free_tab(tab);
    }
  if (close(fd))
    return (84);
  print_scene(scene);
  apply_rot_translate(scene);
  return (check_parse(tab, scene));
}
