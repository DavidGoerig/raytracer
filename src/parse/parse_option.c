/*
** parse_option.c for rt2 in /home/Realague/Delivery/B_MUL/raytracer2/src/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Thu May  4 18:16:45 2017 Julien Delane
** Last update Sun May 28 19:02:53 2017 Julien Delane
*/

#include <unistd.h>
#include <stdlib.h>
#include "bs.h"
#include "rt.h"

static const t_option_func	g_func[] =
  {
    {"-ssaa=", 6, parse_ssaa},
    {"-reflect=", 9, parse_reflect},
    {"-shadow=", 8, parse_shadow},
    {"-ambient=", 9, parse_ambient},
    {NULL, -1, NULL}
  };

static int	is_nbr(char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    {
      if (str[i] > '9' || str[i] < '0')
	return (-1);
    }
  return (0);
}

static int	check_ambient(char *str)
{
  char		**tab;
  int		i;

  i = -1;
  if ((tab = my_str_to_wordtab(str, ",:;")) == NULL)
    return (1);
  while (tab[++i]);
  if (i != 3)
    {
      my_free_tab(tab);
      return (1);
    }
  if (is_nbr(tab[0]) == -1 || is_nbr(tab[1]) == -1 || is_nbr(tab[2]) == -1 ||
      my_getnbr(tab[0]) > 255 || my_getnbr(tab[0]) < 0 ||
      my_getnbr(tab[1]) > 255 || my_getnbr(tab[1]) < 0 ||
      my_getnbr(tab[2]) > 255 || my_getnbr(tab[2]) < 0)
    {
      my_free_tab(tab);
      return (1);
    }
  my_free_tab(tab);
  return (0);
}

static void	fill_option(t_option *option)
{
  option->reflect = 1;
  option->ssaa = 1;
  option->shadow = 1;
  option->ambient.x = .0;
  option->ambient.y = .0;
  option->ambient.z = .0;
}

int		parse_option(t_scene *scene, char **av, int i)
{
  int		o;

  if ((scene->option = malloc(sizeof(t_option))) == NULL)
    return (84);
  fill_option(scene->option);
  while (av[++i])
    {
      if (av[i][0] && av[i][0] == '-')
	{
	  o = -1;
	  while (g_func[++o].str &&
		 my_strncmp(av[i], g_func[o].str, g_func[o].size));
	  if (o == 4 || (is_nbr(&av[i][g_func[o].size]) &&
			 (o == 3 && check_ambient(&av[i][g_func[o].size]))))
	    {
	      write(2, "Error: Wrong argument\n.", 22);
	      return (84);
	    }
	  else
	    g_func[o].func(scene, &av[i][g_func[o].size]);
	}
    }
  if (scene->option->shadow < 1)
    scene->option->shadow = 1;
  return (0);
}
