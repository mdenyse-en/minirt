/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:33:32 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/11 19:27:08 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_trace.h>

void	ft_find_cross_begin_cap(t_dot start, t_dot luch,
	t_cylinder *cyl, t_data *dot_info)
{
	double	t0;
	t_dot	len;
	t_plane	plane;

	start = v_plus(start, v_umn(luch, 0.001));
	plane.center = cyl->center;
	plane.vector = v_umn(cyl->v, -1);
	plane.color = cyl->color;
	t0 = ft_find_t0_plane(start, luch, &plane);
	if (t0 <= 0)
		return ;
	len = v_minus(cyl->center, v_plus(start, v_umn(luch, t0)));
	if (((dot_info->dist0 < 0 && t0 > 0) || (dot_info->dist0 > 0 && t0 > 0
				&& t0 < dot_info->dist0)) && v_length(len) < cyl->dmt / 2)
	{
		dot_info->dist0 = t0;
		dot_info->dot = v_plus(start, v_umn(luch, t0));
		if (v_multipl(luch, plane.vector) < 0)
			dot_info->normal = plane.vector;
		else
			dot_info->normal = v_umn(plane.vector, -1);
		dot_info->color = plane.color;
		dot_info->figure = cyl;
	}
}

void	ft_find_cross_end_cap(t_dot start, t_dot luch,
	t_cylinder *cyl, t_data *dot_info)
{
	double	t0;
	t_dot	len;
	t_plane	plane;

	start = v_plus(start, v_umn(luch, 0.001));
	plane.center = v_plus(cyl->center, v_umn(cyl->v, cyl->height));
	plane.vector = cyl->v;
	plane.color = cyl->color;
	t0 = ft_find_t0_plane(start, luch, &plane);
	if (t0 <= 0)
		return ;
	len = v_minus(plane.center, v_plus(start, v_umn(luch, t0)));
	if (((dot_info->dist0 < 0 && t0 > 0)
			|| (dot_info->dist0 > 0 && t0 > 0 && t0 < dot_info->dist0))
		&& v_length(len) < cyl->dmt / 2)
	{
		dot_info->dist0 = t0;
		dot_info->dot = v_plus(start, v_umn(luch, t0));
		if (v_multipl(luch, plane.vector) < 0)
			dot_info->normal = plane.vector;
		else
			dot_info->normal = v_umn(plane.vector, -1);
		dot_info->color = plane.color;
		dot_info->figure = cyl;
	}
}

double	ft_find_cross_cy(t_dot start, t_dot luch, t_cylinder *cyl,
	t_data *dot_info)
{
	t_vars	vars;

	ft_find_cross_begin_cap(start, luch, cyl, dot_info);
	ft_find_cross_end_cap(start, luch, cyl, dot_info);
	vars.x = v_minus(start, cyl->center);
	vars.t0 = ft_find_t0_cyl(start, luch, cyl);
	vars.m = v_multipl(luch, cyl->v) * vars.t0
		+ v_multipl(vars.x, cyl->v);
	if (vars.m < 0 || vars.m > cyl->height || vars.t0 < 0)
		return (-1);
	if (dot_info->dist0 < 0
		|| (dot_info->dist0 > 0 && vars.t0 < dot_info->dist0))
	{
		dot_info->dist0 = vars.t0;
		dot_info->dot = v_plus(start, v_umn(luch, vars.t0));
		vars.t_os = v_plus(cyl->center, v_umn(cyl->v, vars.m));
		dot_info->normal = v_minus(dot_info->dot, vars.t_os);
		ft_normalize(&dot_info->normal);
		dot_info->color = cyl->color;
		dot_info->figure = cyl;
		if (v_multipl(luch, dot_info->normal) > 0)
			dot_info->normal = v_umn(dot_info->normal, -1);
	}
	return (1);
}

int	ft_check_cross_caps(t_cylinder *cyl, t_data *dot_info, t_light *light,
	double t0)
{
	t_dots	v;
	t_plane	p;

	dot_info->dot = v_plus(dot_info->dot, v_umn(dot_info->normal, 0.001));
	p = g_pl(cyl->center, cyl->v, cyl->color);
	v.luch = v_norm(v_minus(dot_info->dot, light->center));
	t0 = ft_find_t0_plane(light->center, v.luch, &p);
	if (t0 > 0)
	{
		v.len = v_minus(cyl->center, v_plus(light->center, v_umn(v.luch, t0)));
		if (v_length(v.len) < cyl->dmt / 2
			&& t0 < v_length(v_minus(dot_info->dot, light->center)))
			return (1);
	}	
	p = g_pl(v_plus(cyl->center, v_umn(cyl->v, cyl->height)),
			cyl->v, cyl->color);
	t0 = ft_find_t0_plane(light->center, v.luch, &p);
	if (t0 <= 0)
		return (0);
	v.len = v_minus(v_plus(cyl->center, v_umn(cyl->v, cyl->height)),
			v_plus(light->center, v_umn(v.luch, t0)));
	if (t0 < v_length(v_minus(dot_info->dot, light->center))
		&& v_length(v.len) < cyl->dmt / 2)
		return (1);
	return (0);
}

int	ft_check_cross_cy(t_list *tmp, t_data *dot_info, t_light *light)
{
	t_vars		vars;
	t_cylinder	*cyl;

	while (tmp)
	{
		cyl = tmp->content;
		if (ft_check_cross_caps(cyl, dot_info, light, 0.001))
			return (1);
		vars.t_os = v_minus(v_plus(dot_info->dot,
					v_umn(v_norm(v_minus(light->center,
								dot_info->dot)), 0.001)), light->center);
		vars.t0 = ft_find_t0_cyl(light->center, v_norm(vars.t_os), cyl);
		if (vars.t0 < 0 || vars.t0 > v_length(vars.t_os))
		{
			tmp = tmp->next;
			continue ;
		}
		vars.x = v_minus(light->center, cyl->center);
		vars.m = v_multipl(v_norm(vars.t_os), cyl->v) * vars.t0
			+ v_multipl(vars.x, cyl->v);
		if (!(vars.m < 0 || vars.m > cyl->height || vars.t0 < 0))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
