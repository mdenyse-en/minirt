/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cone_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:33:32 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/16 14:56:18 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_trace_bonus.h>

void	ft_find_cross_co_cap(t_dot start, t_dot luch,
	t_cone *cone, t_data *dot_info)
{
	double	t0;
	t_dot	len;
	t_plane	plane;

	start = v_plus(start, v_umn(luch, 0.001));
	plane.center = v_plus(cone->center, v_umn(cone->v, cone->height));
	plane.vector = cone->v;
	plane.color = cone->color;
	t0 = ft_find_t0_plane(start, luch, &plane);
	if (t0 <= 0)
		return ;
	len = v_minus(plane.center, v_plus(start, v_umn(luch, t0)));
	if (((dot_info->dist0 < 0 && t0 > 0)
			|| (dot_info->dist0 > 0 && t0 > 0 && t0 < dot_info->dist0))
		&& v_length(len) < cone->dmt / 2)
	{
		dot_info->dist0 = t0;
		dot_info->dot = v_plus(start, v_umn(luch, t0));
		if (v_multipl(luch, plane.vector) < 0)
			dot_info->normal = plane.vector;
		else
			dot_info->normal = v_umn(plane.vector, -1);
		ft_get_dot_info_co_cap(dot_info, cone, cone->height);
	}
}

double	ft_find_cross_co(t_dot start, t_dot luch, t_cone *cone,
	t_data *dot_info)
{
	t_vars	vars;

	ft_find_cross_co_cap(start, luch, cone, dot_info);
	ft_find_t0_cone(start, luch, cone, &vars);
	vars.m = v_multipl(luch, cone->v) * vars.t0
		+ v_multipl(vars.x, cone->v);
	if (vars.m < 0 || vars.m > cone->height || vars.t0 < 0)
		return (-1);
	if (dot_info->dist0 < 0
		|| (dot_info->dist0 > 0 && vars.t0 < dot_info->dist0))
	{
		dot_info->dist0 = vars.t0;
		dot_info->dot = v_plus(start, v_umn(luch, vars.t0));
		vars.t_os = v_plus(cone->center, v_umn(cone->v, vars.m));
		dot_info->normal = v_minus(v_minus(dot_info->dot, vars.t_os),
				v_umn(cone->v, vars.m * vars.k * vars.k));
		ft_normalize(&dot_info->normal);
		ft_get_dot_info_co(dot_info, cone, vars.m);
		if (v_multipl(luch, dot_info->normal) > 0)
			dot_info->normal = v_umn(dot_info->normal, -1);
	}
	return (1);
}

int	ft_check_cross_caps_co(t_cone *cone, t_data *dot_info, t_light *light,
	double t0)
{
	t_dot	len;
	t_dot	luch;
	t_plane	p;

	dot_info->dot = v_plus(dot_info->dot, v_umn(dot_info->normal, 0.001));
	luch = v_norm(v_minus(dot_info->dot, light->center));
	p = g_pl(v_plus(cone->center, v_umn(cone->v, cone->height)),
			cone->v, cone->color);
	t0 = ft_find_t0_plane(light->center, luch, &p);
	if (t0 <= 0)
		return (0);
	len = v_minus(v_plus(cone->center, v_umn(cone->v, cone->height)),
			v_plus(light->center, v_umn(luch, t0)));
	if (t0 < v_length(v_minus(dot_info->dot, light->center))
		&& v_length(len) < cone->dmt / 2)
		return (1);
	return (0);
}

int	ft_check_cross_co(t_list *tmp, t_data *dot_info, t_light *light)
{
	t_vars	vars;
	t_cone	*cone;

	while (tmp)
	{
		cone = tmp->content;
		if (ft_check_cross_caps_co(cone, dot_info, light, 0.001))
			return (1);
		vars.t_os = v_minus(v_plus(dot_info->dot,
					v_umn(v_norm(v_minus(light->center,
								dot_info->dot)), 0.001)), light->center);
		ft_find_t0_cone(light->center, v_norm(vars.t_os), cone, &vars);
		if (vars.t0 < 0 || vars.t0 > v_length(vars.t_os))
		{
			tmp = tmp->next;
			continue ;
		}
		vars.x = v_minus(light->center, cone->center);
		vars.m = v_multipl(v_norm(vars.t_os), cone->v) * vars.t0
			+ v_multipl(vars.x, cone->v);
		if (!(vars.m < 0 || vars.m > cone->height || vars.t0 < 0))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
