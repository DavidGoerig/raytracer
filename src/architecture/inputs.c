/*
** inputs.c for rt in /home/baurens/Work/Tek1/Projects/IGRAPH/raytracer2/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri Mar 31 14:50:43 2017 Arthur Baurens
** Last update Sun May 28 19:22:06 2017 Benjamin
*/

#include <math.h>
#include "libgraph.h"
#include "rt.h"

int		is_same_pos(t_prog *prog, t_rt *rt)
{
  sfVector2i	m_pos;
  int		v;

  m_pos.x = prog->w / 2;
  m_pos.y = prog->h / 2;
  if (rt->render_mode == R_CLASIC)
    return (1);
  if (!(rt->modes & M_PAUSE) &&
      (rt->old_rot.x != rt->rot.x ||
       rt->old_rot.y != rt->rot.y ||
       rt->old_rot.z != rt->rot.z))
    return (0);
  v = sfKeyboard_isKeyPressed(sfKeyZ) - sfKeyboard_isKeyPressed(sfKeyS)
    + sfKeyboard_isKeyPressed(sfKeyD) - sfKeyboard_isKeyPressed(sfKeyQ)
    + sfKeyboard_isKeyPressed(sfKeySpace)
    - sfKeyboard_isKeyPressed(sfKeyLShift);
  if (v || m_pos.x != prog->w / 2 || m_pos.y != prog->h / 2)
    return (0);
  return (1);
}

void	reset_trigers(t_prog *prog)
{
  if (!sfMouse_isButtonPressed(0))
    prog->triggers[0] = 0;
  if (!sfKeyboard_isKeyPressed(sfKeyReturn))
    prog->triggers[1] = 0;
  if (!sfKeyboard_isKeyPressed(sfKeyC))
    prog->triggers[2] = 0;
}

static void	keyboard_control(t_prog *prog, t_rt *rt)
{
  t_vec3f	fwd;
  t_vec3f	right;

  (void)prog;
  fwd.z = 0;
  fwd.x = cos(TO_RAD(-rt->rot.y));
  fwd.y = sin(TO_RAD(-rt->rot.y));
  right.z = 0;
  right.x = cos(TO_RAD(-rt->rot.y + 90));
  right.y = sin(TO_RAD(-rt->rot.y + 90));
  if (sfKeyboard_isKeyPressed(sfKeyZ))
    v_add(&rt->pos, &fwd, 1);
  if (sfKeyboard_isKeyPressed(sfKeyS))
    v_add(&rt->pos, &fwd, -1);
  if (sfKeyboard_isKeyPressed(sfKeyD))
    v_add(&rt->pos, &right, -1);
  if (sfKeyboard_isKeyPressed(sfKeyQ))
    v_add(&rt->pos, &right, 1);
  if (sfKeyboard_isKeyPressed(sfKeySpace))
    rt->pos.z += 1;
  if (sfKeyboard_isKeyPressed(sfKeyLShift))
    rt->pos.z -= 1;
}

static void	keyboard_triggered_inputs(t_prog *prog, t_rt *rt)
{
  sfVector2i	center;

  center.x = prog->w / 2;
  center.y = prog->h / 2;
  if (sfKeyboard_isKeyPressed(sfKeyReturn) && !prog->triggers[1])
    {
      prog->triggers[1] = 1;
      rt->render_mode = !rt->render_mode;
      sfMouse_setPositionRenderWindow(center, prog->wind);
    }
  if (sfKeyboard_isKeyPressed(sfKeyC) && !prog->triggers[2])
    {
      prog->triggers[2] = 1;
      take_screenshot(prog);
    }
}

void		controls(t_prog *prog)
{
  sfVector2i	center;
  sfVector2i	m_pos;
  t_vec2f	tmp;
  t_rt		*rt;

  center.x = prog->w / 2;
  center.y = prog->h / 2;
  rt = (t_rt *)prog->data;
  keyboard_triggered_inputs(prog, rt);
  if ((rt->modes & M_PAUSE) != 1)
    sfRenderWindow_setMouseCursorVisible(prog->wind, rt->render_mode);
  if (rt->render_mode == R_CLASIC)
    return ;
  m_pos = sfMouse_getPositionRenderWindow(prog->wind);
  tmp.x = ((double)(m_pos.x - center.x) * MOUSE_SENSI);
  tmp.y = ((double)(m_pos.y - center.y) * MOUSE_SENSI);
  rt->rot.y = ((360 + (int)((double)rt->rot.y + tmp.x)) % 360);
  rt->rot.x = (int)((double)rt->rot.x + tmp.y);
  sfMouse_setPositionRenderWindow(center, prog->wind);
  keyboard_control(prog, rt);
}
