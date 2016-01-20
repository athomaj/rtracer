/*
** init_elems.c for raytracer in /home/archer_j/rendu/tmp/raytracer_tmp/parser
** 
** Made by archer
** Login   <archer_j@epitech.net>
** 
** Started on  Fri May 30 11:15:11 2014 archer
** Last update Sun Jun  8 15:12:05 2014 borel_d
*/

#include	"raytracer.h"

void		init_elems(char **elems)
{
  elems[0] = "orientation";
  elems[1] = "intensity";
  elems[2] = "field";
  elems[3] = "transparency";
  elems[4] = "distortion";
  elems[5] = "brightness";
  elems[6] = "reflexion";
  elems[7] = "pos";
  elems[8] = "rot";
  elems[9] = "limits_inf";
  elems[10] = "limits_sup";
  elems[11] = "color";
}

void		init_coord(t_coord *coord, int x, int y, int z)
{
  coord->x = x;
  coord->y = y;
  coord->z = z;
}

static void	init_coords(t_coord *coords, t_class *tmp)
{
  if (tmp == NULL)
    {
      init_coord(&coords[0], 0, 0, 0);
      init_coord(&coords[1], 0, 0, 0);
      init_coord(&coords[2], 0, 0, 0);
      init_coord(&coords[3], 0, 0, 0);
    }
  else
    {
      coords[0] = tmp->object_elem.pos;
      coords[1] = tmp->object_elem.rot;
      coords[2] = tmp->object_elem.limits_inf;
      coords[3] = tmp->object_elem.limits_sup;
    }
}

void		init_values(double *values, t_coord *coords, t_class *tmp)
{
  int		i;

  if (tmp == NULL)
    {
      i = -1;
      while (++i < 11)
	values[i] = 0;
      values[1] = 100;
      values[2] = 360;
      init_coords(coords, tmp);
      return ;
    }
  values[0] = tmp->spot_elem.orientation;
  values[1] = tmp->spot_elem.intensity;
  values[2] = tmp->spot_elem.radius;
  values[3] = tmp->object_elem.transparency;
  values[4] = tmp->object_elem.distortion;
  values[5] = tmp->object_elem.brightness;
  values[6] = tmp->object_elem.reflexion;
  values[7] = tmp->object_elem.infos;
  values[8] = tmp->object_elem.color.r;
  values[9] = tmp->object_elem.color.g;
  values[10] = tmp->object_elem.color.b;
  init_coords(coords, tmp);
}
