/*
** libgraph.h for libgraph in /home/baurens/Work/Tek1/Projects/IGRAPH/wireframe/lib_graph/include/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Mon Nov 21 17:23:41 2016 Arthur Baurens
** Last update Wed May 24 16:34:15 2017 Arthur Baurens
*/

#ifndef LIBGRAPH_H_
# define LIBGRAPH_H_
# include <SFML/Graphics/RenderWindow.h>
# include <SFML/Graphics/Texture.h>
# include <SFML/Graphics/Sprite.h>
# include <math.h>

# define IMG_ONLY 0
# define RESIZABLE 1
# define CLOSABLE 1
# define TO_RAD(x) (M_PI * (x) / 180)
# define TO_DEG(x) (180 * (x) / M_PI)
# define ABS(x) (((x) < 0) ? (-x) : (x))

struct	s_prog;

typedef struct s_prog t_prog;

typedef struct
{
  int		x;
  int		y;
}		t_vec2i;

typedef union
{
  char		rgba[4];
  int		hex;
}		t_color;

struct			s_prog
{
  int			w;
  int			h;
  const char		*name;
  sfRenderWindow	*wind;
  sfSprite		*sprite;
  sfTexture		*tex;
  sfUint8		*pix;
  sfEvent		event;
  char			*triggers;
  void			*data;
  void			(*pre_fct)(t_prog *);
  void			(*loop_fct)(t_prog *);
  void			(*event_fct)(t_prog *);
};

typedef struct	s_my_framebuffer
{
  sfUint8	*pixels;
  int		width;
  int		height;
}		t_my_framebuffer;

void	set_color(sfColor *color, unsigned int argb);

int	new_window(const char *, int , int, t_prog *);
void	clear_screen(t_prog *, sfColor);
void	refresh_window(t_prog *prog);
void	start_loop(t_prog *prog);

void	set_pre(t_prog *, void (*func)(t_prog *));
void	set_loop(t_prog *, void (*func)(t_prog *));
void	set_event(t_prog *, void (*func)(t_prog *));
void	set_all_func(t_prog *, void (*pre)(t_prog *),
		     void (*loop)(t_prog *),
		     void (*event)(t_prog *));

void	place_pixel(t_prog *prog, int x, int y, sfColor color);
void	my_draw_square(t_prog *, t_vec2i, t_vec2i, sfColor);

#endif /* !LIBGRAPH_H_ */
