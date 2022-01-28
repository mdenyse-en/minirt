/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:55:26 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/15 22:08:40 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_BONUS_H
# define SCENE_BONUS_H

# include "../../libft/libft.h"

typedef struct s_img
{
	void	*img;
	int		w;
	int		h;
	int		*data;
	int		bpp;
	int		size_l;
	int		end;
}	t_img;

typedef struct s_cam_vars
{
	double	c_width;
	double	c_height;
	double	pixel_value;
	double	cosX;
	double	sinX;
	double	cosY;
	double	sinY;
}	t_cam_vars;

typedef struct s_dot
{
	double	x;
	double	y;
	double	z;
}	t_dot;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_angers
{
	double	sinX;
	double	cosX;
	double	sinY;
	double	cosY;
}	t_angers;

typedef struct s_am_light
{
	double	ratio;
	t_rgb	color;
}	t_am_light;

typedef struct s_camera
{
	t_dot		center;
	t_dot		v;
	t_dot		r_vec;
	t_dot		h_vec;
	t_cam_vars	cam_v;
	double		fov;
}	t_camera;

typedef struct s_light
{
	t_dot	center;
	double	ratio;
	t_rgb	color;
}	t_light;

typedef struct s_sphere
{
	t_dot	center;
	double	diameter;
	t_rgb	color;
	t_img	txtr;
	t_img	txtr_n;
	t_img	txtr_h;
}	t_sphere;

typedef struct s_plane
{
	t_dot	center;
	t_dot	vector;
	t_dot	v_y;
	t_dot	v_x;
	t_rgb	color;
	t_img	txtr;
	t_img	txtr_n;
	t_img	txtr_h;
}	t_plane;

typedef struct s_cylinder
{
	t_dot	center;
	t_dot	v;
	t_dot	v_x;
	t_dot	v_z;
	double	dmt;
	double	height;
	t_rgb	color;
	t_img	txtr;
	t_img	txtr_n;
	t_img	txtr_h;
}	t_cylinder;

typedef struct s_cone
{
	t_dot	center;
	t_dot	v;
	t_dot	v_x;
	t_dot	v_z;
	double	dmt;
	double	height;
	t_rgb	color;
	t_img	txtr;
	t_img	txtr_n;
	t_img	txtr_h;
}	t_cone;

typedef struct s_scene
{
	t_list		*am_light;
	t_list		*camera;
	t_list		*l_lights;
	t_list		*l_spheres;
	t_list		*l_planes;
	t_list		*l_cylinders;
	t_list		*l_cones;
}	t_scene;

#endif