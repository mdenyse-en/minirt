/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:33:28 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/03 20:14:22 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_trace.h>

double	ft_find_t0_plane(t_dot start, t_dot luch, t_plane *plane)
{
	t_vars	vars;

	vars.tca = v_multipl(luch, plane->vector);
	if (vars.tca == 0)
		return (-1);
	vars.thc = -1 * v_multipl(v_minus(start, plane->center),
			plane->vector);
	vars.t0 = vars.thc / vars.tca;
	return (vars.t0);
}

double	ft_find_cross_pl(t_dot start, t_dot luch,
	t_plane *plane, t_data *dot_info)
{
	double	t0;

	t0 = ft_find_t0_plane(start, luch, plane);
	if ((dot_info->dist0 < 0 && t0 > 0)
		|| (dot_info->dist0 > 0 && t0 > 0 && t0 < dot_info->dist0))
	{
		dot_info->dist0 = t0;
		dot_info->dot = v_plus(start, v_umn(luch, t0));
		if (v_multipl(luch, plane->vector) < 0)
			dot_info->normal = plane->vector;
		else
			dot_info->normal = v_umn(plane->vector, -1);
		dot_info->color = plane->color;
		dot_info->figure = plane;
	}
	return (1);
}

double	ft_check_cross_pl(t_list *tmp, t_data *dot_info, t_light *light)
{
	double	t0;
	t_dot	start;
	t_dot	luch;

	while (tmp)
	{
		luch = v_norm(v_minus(light->center, dot_info->dot));
		start = v_plus(dot_info->dot, v_umn(luch, 0.001));
		t0 = ft_find_t0_plane(start, luch, tmp->content);
		if (t0 > 0 && t0 < v_length(v_minus(light->center,
					dot_info->dot)))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
