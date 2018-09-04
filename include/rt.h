/*
** rt.h for rt in /home/baurens/Work/Tek1/Projects/IGRAPH/raytracer2/include/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Sun Mar 26 16:51:01 2017 Arthur Baurens
** Last update Sun May 28 19:47:30 2017 Julien Delane
*/

#ifndef RT_H_
# define RT_H_

# include <pthread.h>
# include "libgraph.h"
# include "parse.h"

# define FOV 70.0
# define FOV_F(x, y)((x) / (2 * tan(TO_RAD(y) / 2)))
# define UNUSED(x) ((void)(x))
# define H_SPLIT 2
# define W_SPLIT 4
# define MOUSE_SENSI 0.2f
# define M_DEBUG 1 << 0
# define M_PAUSE 1 << 0
# define RENDER_RES (t_vec2i){1, 1}
# define DEBUG_RES (t_vec2i){4, 4}
# define EMBIENT (t_vec3f){0, 0, 0}

typedef struct
{
  double	x;
  double	y;
}		t_vec2f;

typedef struct		s_result
{
  t_vec3f		specular;
  t_vec3f		normal;
  t_vec3f		intersect;
  t_vec3f		dir_vector;
  t_vec3f		camera;
  t_obj			*obj;
  sfColor		color;
  double		dist;
  int			i;
}			t_result;

typedef struct		s_option_func
{
  char			*str;
  int			size;
  void			(*func)(struct s_scene *, char *);
}			t_option_func;

typedef struct
{
  int			id;
  int			speed;
  int			progress;
  char			loop;
  sfColor		color;
  t_prog		*prog;
  t_vec2i		start;
  t_vec2i		cur;
  t_vec2i		end;
  pthread_t		thread;
  pthread_mutex_t	end_mut;
}			t_thread;

typedef enum	e_render_mode
{
  R_DEBUG,
  R_CLASIC
}		t_render_mode;

typedef struct
{
  t_scene		*scene;
  t_vec3f		pos;
  t_vec3f		rot;
  t_vec3f		old_rot;
  t_render_mode		old_render;
  t_render_mode		render_mode;
  int			counter;
  unsigned int		modes;
  pthread_mutex_t	start_mutex;
  pthread_mutex_t	render_mutex;
  t_thread		threads[W_SPLIT * H_SPLIT];
}			t_rt;

/*
** math_utils.c
*/
t_vec3f		*negate_vec(t_vec3f *v);
float		dot(t_vec3f v1, t_vec3f v2);
float		clamp(float min, float val, float max);
t_vec3f		my_reflect(t_vec3f *dir, t_vec3f normal);

/*
** true_light.c
*/
void		apply_lights_effects(t_rt *rt, t_result *res);

/*
** threading.c
*/
void		*thread(void *var);
void		*refresh_thread(void *data);

/*
** multithreading.c
*/
void		thread_screen(t_prog *prog);

/*
** color.c
*/
sfColor		color_rgba(char r, char g, char b, char a);

/*
** raytracing_core.c
*/
void		get_pixel_color(t_prog *prog, t_vec2i pos);
t_result	collide(t_rt *, t_vec3f *, t_vec3f *, t_result *);

/*
** options.c
*/
void		set_paused(t_prog *prog, char b);
char		pause_handeling(t_prog *prog);

/*
** inputs.c
*/
int		is_same_pos(t_prog *prog, t_rt *rt);
void		reset_trigers(t_prog *prog);
void		controls(t_prog *prog);

/*
** output
*/
void		take_screenshot(t_prog *prog);

/*
** effects
*/
void		reflection(t_rt *rt, t_result *res);

/*
** quadra
*/
t_vec3f		calc_dir_vector(t_vec2i screen_size, t_vec2i screen_pos);
double		intersect(t_quadra quad, t_vec3f dir, t_vec3f eye);
void		rotate(t_quadra *quad, t_vec3f rotation);
void		translate(t_quadra *quad, t_vec3f tr);
void		fill_result(t_rt *rt, t_result *res, t_vec3f dir_vector);
t_vec3f		calc_normal_vector(t_quadra quad, t_vec3f point);
void		apply_rot_translate(t_scene *scene);

/*
** rotate.c
*/
t_vec3f		v_rotate_x(t_vec3f to_rotate, float x);
t_vec3f		v_rotate_y(t_vec3f to_rotate, float y);
t_vec3f		v_rotate_z(t_vec3f to_rotate, float z);
t_vec3f		rotate_xyz(t_vec3f to_rotate, t_vec3f angles);
t_vec3f		rotate_zyx(t_vec3f to_rotate, t_vec3f angles);

/*
** free
*/
void		free_scene(t_scene *scene);

/*
** rand.c
*/
int		my_rand();
t_vec3f		vec3_random();

/*
** utils.c
*/
void		add(int *i, sfColor color, double coef);
void		init_int(int *color, int size);
void		add_int(int *a, int *b);
void		remove_int(int *a, int b);

/*
** vector.c
*/
float		norme(t_vec3f *v);
t_vec3f		get_pos_res(t_vec3f eye_pos, float distance,
			    t_vec3f dir_vector);
t_vec3f		*v_add(t_vec3f *v1, t_vec3f *v2, double fact);
t_vec3f		*normalize(t_vec3f *vector);
t_vec3f		reflect_vector(t_vec3f v, t_vec3f n);
t_vec3f		get_dir_vector(t_vec3f a, t_vec3f b, int i);

/*
** shadow
*/
int		check_in_front(t_scene *scene, t_vec3f dir, t_vec3f camera);

/*
** light
*/
void		add_direct_light(t_scene *scene, t_result *res,
				 t_rt *rt, t_vec3f dir_vector);
void		direct_light(t_rt *rt, t_result *res,
			     t_light *light, t_vec3f);
void		reflection(t_rt *rt, t_result *res);
void		refraction(t_rt *rt, t_result *res);

/*
** ssaa
*/
sfColor		super_sampling(t_scene *scene, t_rt *rt,
			       t_vec2i screen_size,
			       t_vec2i screen_pos_base);

/*
** parse_option
*/
int	parse_option(t_scene *scene, char **av, int i);
void	parse_ambient(t_scene *scene, char *str);
int	list_to_tab(t_scene *scene);
void	parse_ssaa(t_scene *scene, char *str);
void	parse_reflect(t_scene *scene, char *str);
void	parse_shadow(t_scene *scene, char *str);

/*
** texturing.c
*/
sfColor	get_object_color(t_rt *rt, t_result *res);

#endif /* !RT_H_ */
