/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 14:30:09 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/06 14:37:11 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACE_H
# define RAY_TRACE_H

# include <structs.h>
# include <vectors.h>
# include <color.h>
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
	t_dot	x;
	t_dot	t_os;
}	t_vars;

typedef struct s_dots
{
	t_dot	len;
	t_dot	luch;
}	t_dots;

// typedef struct s_cam_vars
// {
// 	double	c_width;
// 	double	c_height;
// 	double	pixel_value;
// 	double	cosX;
// 	double	sinX;
// 	double	cosY;
// 	double	sinY;
// }	t_cam_vars;

//ft_cylinder_utils.c

double	ft_find_t0_cyl(t_dot start, t_dot luch, t_cylinder *cyl);
t_plane	g_pl(t_dot center, t_dot vector, t_rgb color);

//ft_cylinder.c

double	ft_find_cross_cy_cap(t_dot start, t_dot luch,
			t_cylinder *cyl, t_data *dot_info);
double	ft_find_cross_cy(t_dot start, t_dot luch,
			t_cylinder *cyl, t_data *dot_info);
int		ft_check_cross_cy(t_list *tmp, t_data *dot_info, t_light *light);

//ft_plane.c

double	ft_check_cross_pl(t_list *tmp, t_data *dot_info, t_light *light);

double	ft_find_t0_plane(t_dot start, t_dot luch, t_plane *plane);
double	ft_find_cross_pl(t_dot start, t_dot luch,
			t_plane *plane, t_data *dot_info);
int		ft_start_ray(t_main_struct *m_s);
int		ft_ray_trace(t_dot start, t_main_struct *m_s);

//ft_sphere.c

double	ft_find_cross_sp(t_dot start, t_dot luch,
			t_sphere *sphere, t_data *dot_info);
double	ft_check_cross_sp(t_list *tmp, t_data *dot_info, t_light *light);

#endif