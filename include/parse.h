/*
** parse.h for rt2 in /home/benjamin/Dropbox/raytracer2/include/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon Apr 17 11:22:42 2017 Benjamin
** Last update Sun May 28 19:28:32 2017 Benjamin
*/

#ifndef PARSE_H_
# define PARSE_H_

# include "libgraph.h"

# define MAX_MAX	1000000
# define MAX_POS	MAX_MAX
# define MAX_INTENS	MAX_MAX
# define MAX_SHINE	MAX_MAX
# define MAX_QUAD	MAX_MAX
# define MAX_ROT	MAX_MAX

# define C_YELLOW	"\e[93m"
# define C_CYAN		"\e[36;1m"
# define C_RED		"\e[31;1m"
# define C_END		"\x1b[0m"

# define EX_LINE C_CYAN "Line (%d)(%s) " C_YELLOW
# define EX_NAME EX_LINE "Choose an Alphanumeric Name: " C_END
# define EX_POS EX_LINE "Choose X Y Z positions between -%d and %d: " C_END
# define EX_INTENS EX_LINE "Choose an intensity between 0 and %d: " C_END
# define EX_COLOR EX_LINE "Choose R G B value between 0 and 255: " C_END
# define EX_TRANS EX_LINE "Choose transparency value between 0 and 1: " C_END
# define EX_REFLECT EX_LINE "Choose reflect value between 0 and 1: " C_END
# define EX_REFRACT EX_LINE "Choose refract value between 0 and 5: " C_END
# define EX_SHINE EX_LINE "Choose shine value between 1 and %d: " C_END
# define EX_TEXTURE EX_LINE "Enter a .bmp path: " C_END
# define EX_MAT EX_LINE "Type a meterial name: " C_END
# define EX_ROT EX_LINE "Choose 3 rotation values between -%d and %d: " C_END
# define QUAD_TXT "Choose 10 values for quadratics between -%d and %d: "
# define MAP_TXT "Choose [plane], [sphere] or [cylinder] for mapping: "
# define EX_QUAD EX_LINE QUAD_TXT C_END
# define EX_MAPPING EX_LINE MAP_TXT C_END

typedef struct		s_texture
{
  int			height;
  int			width;
  sfColor		**pixels;
}			t_texture;

typedef struct		s_parse
{
  int			opt;
  int			line;
}			t_parse;

typedef struct
{
  double		x;
  double		y;
  double		z;
}			t_vec3f;

typedef struct		s_mat t_mat;
typedef struct		s_obj t_obj;
typedef struct		s_light t_light;

typedef struct		s_quadra
{
  double		a;
  double		b;
  double		c;
  double		d;
  double		e;
  double		f;
  double		g;
  double		h;
  double		i;
  double		j;
}			t_quadra;

typedef struct		s_parse_mat
{
  int			name;
  int			transparency;
  int			reflect;
  int			refract;
  int			shine;
  int			texture;
}			t_parse_mat;

struct			s_mat
{
  char			*name;
  float			transparency;
  float			reflect;
  float			refract;
  unsigned int		shine;
  t_texture		*texture;
  int			tex_coef;
  t_parse_mat		parse;
  t_mat			*next;
  t_mat			*prev;
};

typedef enum		e_mapping
{
  M_PLANE,
  M_SPHERE,
  M_CYLINDER,
  M_NONE
}			t_mapping;

typedef struct		s_parse_obj
{
  int			name;
  int			mat;
  int			quad;
  int			color;
  int			pos;
  int			rot;
  int			mapping;
}			t_parse_obj;

struct 			s_obj
{
  char			*name;
  char			*mat_name;
  struct s_mat		*mat;
  t_quadra		quadra;
  sfColor		color;
  t_vec3f		pos;
  t_vec3f		rot;
  t_parse_obj		parse;
  t_mapping		mapping;
  t_obj			*next;
  t_obj			*prev;
};

typedef struct		s_parse_light
{
  int			name;
  int			pos;
  int			intensity;
  int			color;
}			t_parse_light;

struct			s_light
{
  char			*name;
  t_vec3f		pos;
  unsigned int		intensity;
  sfColor		color;
  t_parse_light		parse;
  t_light		*next;
  t_light		*prev;
};

typedef struct		s_option
{
  int			shadow;
  int			ssaa;
  int			reflect;
  t_vec3f		ambient;
}			t_option;

typedef struct		s_scene
{
  t_light		*light;
  t_obj			*obj;
  t_mat			*mat;
  int			nb_obj;
  int			nb_light;
  t_option		*option;
}			t_scene;

# pragma pack(1)

typedef struct		s_bmp_info
{
  int			size_info;
  int			width;
  int			height;
  short			nbplans;
  unsigned short	bpp;
  int			compression;
  int			sizeim;
  int			hres;
  int			vres;
  int			cpalette;
  int			cipalette;
}			t_bmp_info;

typedef struct		s_header_bmp
{
  char			magic[2];
  int			size;
  int			ident;
  int			offset;
  t_bmp_info		info;
}			t_header_bmp;

/*
** FUNCTIONS
*/

void			apply_rot_translate(t_scene *scene);
int			export_bmp(sfUint8 *pixels, int height, int width);
t_texture		*loader_bmp(char *file_name);

void	apply_rot_translate(t_scene *);

void	print_scene(t_scene *tmp);

int	create_light(char *name, t_light **, t_parse *);
int	create_mat(char *name, t_mat **, t_parse *);
int	create_obj(char *name, t_obj **, t_parse *);
int	same_light_name(t_light *light, char *name);
int	same_mat_name(t_mat *mat, char *name);
int	same_obj_name(t_obj *obj, char *name);
int	parse_file(int ac, char **av, t_parse *, t_scene *);
int	parse_what_to_do(char **, t_parse *, t_scene *);

int	set_light(char **, char *name, t_light *, t_parse *);
int	set_light_color(t_light *, char **, int);
int	set_light_intensity(t_light *, char **, int);
int	set_light_pos(t_light *, char **, int);

int	set_mat(char **, char *name, t_mat *, t_parse *);
int	set_mat_transparency(t_mat *, char **, int);
int	set_mat_reflect(t_mat *, char **, int);
int	set_mat_refract(t_mat *, char **, int);
int	set_mat_shine(t_mat *, char **, int);
int	set_mat_texture(t_mat *, char **, int);
int	set_mat_tex_coef(t_mat *, char **, int);

int	set_obj(char **, char *name, t_obj *, t_parse *);
int	set_obj_color(t_obj *, char **, int);
int	set_obj_mat(t_obj *, char **, int);
int	set_obj_pos(t_obj *, char **, int);
int	set_obj_quad(t_obj *, char **, int);
int	set_obj_rot(t_obj *, char **, int);
int	set_obj_mapping(t_obj *, char **, int);

int	check_parse(char **, t_scene *);
int	check_light(t_light *);
int	check_mat(t_mat *);
int	check_obj(t_obj *, t_mat *);

void	fix_mat_transparency(t_mat *);
void	fix_mat_texture(t_mat *);
void	fix_mat_reflect(t_mat *);
void	fix_mat_refract(t_mat *);
void	fix_mat_shine(t_mat *);

int	fix_obj_mat(t_obj *, t_mat *);
void	fix_obj_quad(t_obj *);
void	fix_obj_color(t_obj *);
void	fix_obj_pos(t_obj *);
void	fix_obj_rot(t_obj *);
void	fix_obj_mapping(t_obj *);

#endif /* !PARSE_H_ */
