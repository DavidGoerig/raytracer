/*
** texturing.c for rt in /home/baurens/Work/Tek1/Projects/IGRAPH/raytracer2/src/display/effects/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri May 26 09:59:41 2017 Arthur Baurens
** Last update Sun May 28 21:37:29 2017 Arthur Baurens
*/

#include "rt.h"

static sfColor	plane_mapping(t_result *res)
{
  t_vec2i	uv;
  t_vec3f	pos;
  t_texture	*tex;

  pos = res->intersect;
  tex = res->obj->mat->texture;
  pos = v_rotate_x(pos, -TO_RAD(res->obj->rot.x));
  pos = v_rotate_y(pos, -TO_RAD(res->obj->rot.y));
  pos = v_rotate_z(pos, TO_RAD(res->obj->rot.z));
  uv.x = (int)(pos.x * res->obj->mat->tex_coef) % tex->height;
  uv.y = (int)(pos.y * res->obj->mat->tex_coef) % tex->width;
  if (uv.x < 0)
    uv.x = tex->height + uv.x;
  if (uv.y > 0)
    uv.y = tex->width - uv.y;
  return (tex->pixels[ABS(uv.x)][ABS(uv.y)]);
}

static sfColor	sphere_mapping(t_result *res)
{
  float		c;
  t_vec2i	uv;
  t_vec3f	pos;
  t_texture	*tex;

  pos = res->intersect;
  pos.x -= res->obj->pos.x;
  pos.y -= res->obj->pos.y;
  pos.z -= res->obj->pos.z;
  tex = res->obj->mat->texture;
  pos = v_rotate_x(pos, -TO_RAD(res->obj->rot.x));
  pos = v_rotate_y(pos, -TO_RAD(res->obj->rot.y));
  pos = v_rotate_z(pos, TO_RAD(res->obj->rot.z));
  normalize(&pos);
  c = ((float)res->obj->mat->tex_coef);
  uv.y = ((0.5 - atan2(pos.x, pos.y) / (2 * M_PI)) * ((float)tex->width * c));
  uv.x = ((0.5 + asin(pos.z) / M_PI) * ((float)tex->height * c));
  return (tex->pixels[uv.x % tex->height][uv.y % tex->width]);
}

static sfColor	cylinder_mapping(t_result *res)
{
  float		c;
  t_vec2f	uv;
  t_vec3f	nor;
  t_vec3f	pos;
  t_texture	*tex;

  pos = res->intersect;
  nor = res->intersect;
  tex = res->obj->mat->texture;
  v_add(&nor, &res->obj->pos, -1);
  nor = v_rotate_x(nor, -TO_RAD(res->obj->rot.x));
  nor = v_rotate_y(nor, -TO_RAD(res->obj->rot.y));
  nor = v_rotate_z(nor, TO_RAD(res->obj->rot.z));
  pos = nor;
  normalize(&nor);
  c = ((float)res->obj->mat->tex_coef);
  uv.x = ((0.5 - atan2(nor.x, nor.y) / (2 * M_PI))) * ((float)tex->width * c);
  uv.y = pos.z / M_PI;
  uv.y -= floor(uv.y);
  if (uv.y < 0)
    uv.y = 1 - uv.y;
  uv.y *= ((float)tex->height * c);
  return (tex->pixels[(int)uv.y % tex->height][(int)uv.x % tex->width]);
}

sfColor		get_object_color(t_rt *rt, t_result *res)
{
  t_vec3f	f;
  sfColor	tex;
  sfColor	col;
  sfColor	(*func[3])(t_result *);

  col = sfWhite;
  tex = res->obj->color;
  func[0] = plane_mapping;
  func[1] = sphere_mapping;
  func[2] = cylinder_mapping;
  if (rt->render_mode != R_DEBUG &&
      res->obj->mat->texture != NULL && res->obj->mapping != M_NONE)
    {
      col = res->obj->color;
      tex = func[res->obj->mapping](res);
    }
  f.x = ((float)col.r / 255.0);
  f.y = ((float)col.g / 255.0);
  f.z = ((float)col.b / 255.0);
  tex.r = ((float)tex.r * f.x);
  tex.g = ((float)tex.g * f.y);
  tex.b = ((float)tex.b * f.z);
  return (tex);
}
