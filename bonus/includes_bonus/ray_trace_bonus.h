/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 14:30:09 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/16 15:04:14 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACE_BONUS_H
# define RAY_TRACE_BONUS_H

# include <structs_bonus.h>
# include <vectors_bonus.h>
# include <color_bonus.h>
# include <math.h>

typedef struct s_vars
{
	double	tca;
	double	d2;
	double	thc;
	double	t1;
	double	t0;
	double	a;
	double	b;
	double	c;
	double	m;
	double	k;
	t_dot	x;
	t_dot	t_os;
	t_dot	len;
	t_dot	luch;
	t_rgb	color;
	t_plane	p;
}	t_vars;

//ft_cone_utils.c

void		ft_find_t0_cone(t_dot start, t_dot luch,
				t_cone *cone, t_vars *vars);
t_plane		g_pl(t_dot center, t_dot vector, t_rgb color);
void		ft_get_dot_info_co(t_data *dot_info, t_cone *cone, float t_os);

//ft_cone.c

void		ft_find_cross_co_cap(t_dot start, t_dot luch,
				t_cone *cone, t_data *dot_info);
double		ft_find_cross_co(t_dot start, t_dot luch,
				t_cone *cone, t_data *dot_info);
int			ft_check_cross_co(t_list *tmp, t_data *dot_info, t_light *light);
void		ft_get_dot_info_co_cap(t_data *dot_info, t_cone *cone, double h);

//ft_cylinder_utils.c

double		ft_find_t0_cyl(t_dot start, t_dot luch, t_cylinder *cyl);
t_plane		g_pl(t_dot center, t_dot vector, t_rgb color);
void		ft_get_dot_info_cy(t_data *dot_info, t_cylinder *cyl, float t_os);

//ft_cylinder.c

double		ft_find_cross_cy_cap(t_dot start, t_dot luch,
				t_cylinder *cyl, t_data *dot_info);
double		ft_find_cross_cy(t_dot start, t_dot luch,
				t_cylinder *cyl, t_data *dot_info);
int			ft_check_cross_cy(t_list *tmp, t_data *dot_info, t_light *light);
void		ft_get_dot_info_cy_cap(t_data *dot_info, t_cylinder *cyl, double h);

//ft_plane.c

double		ft_check_cross_pl(t_list *tmp, t_data *dot_info, t_light *light);

double		ft_find_t0_plane(t_dot start, t_dot luch, t_plane *plane);
double		ft_find_cross_pl(t_dot start, t_dot luch,
				t_plane *plane, t_data *dot_info);
int			ft_start_ray(t_main_struct *m_s);
int			ft_ray_trace(t_dot start, t_main_struct *m_s);

//ft_sphere.c

double		ft_find_cross_sp(t_dot start, t_dot luch,
				t_sphere *sphere, t_data *dot_info);
double		ft_check_cross_sp(t_list *tmp, t_data *dot_info, t_light *light);

//ft_sphere_utils.c

t_angers	ft_find_angles_sp_txtr(t_data *dot_info, t_sphere *sphere);
void		ft_get_kX_kY(t_data *dot_info, t_sphere *sphere,
				double *kX, double *kY);

#endif