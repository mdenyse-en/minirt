/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:33:24 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/03 20:14:13 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_trace.h>

double	ft_return_t0(t_dot start, t_dot luch, t_sphere *sphere)
{
	t_vars	vars;

	vars.tca = v_multipl(v_minus((sphere->center), start), luch);
	vars.d2 = v_multipl(v_minus((sphere->center), start),
			v_minus((sphere->center), start)) - vars.tca * vars.tca;
	if (vars.d2 > (sphere->diameter * sphere->diameter / 4))
		return (-1);
	vars.thc = sqrt((sphere->diameter * sphere->diameter / 4) - vars.d2);
	vars.t0 = vars.tca - vars.thc;
	vars.t1 = vars.tca + vars.thc;
	if (vars.t0 < 0)
		vars.t0 = vars.t1;
	return (vars.t0);
}

double	ft_find_cross_sp(t_dot start, t_dot luch,
	t_sphere *sphere, t_data *dot_info)
{
	t_vars	vars;

	vars.t0 = ft_return_t0(start, luch, sphere);
	if ((dot_info->dist0 < 0 && vars.t0 > 0) || (dot_info->dist0 > 0
			&& vars.t0 < dot_info->dist0 && vars.t0 > 0))
	{
		dot_info->dist0 = vars.t0;
		dot_info->dot = v_plus(start, v_umn(luch, vars.t0));
		dot_info->normal = v_minus(dot_info->dot, sphere->center);
		ft_normalize(&dot_info->normal);
		dot_info->color = sphere->color;
		dot_info->figure = sphere;
		if (v_multipl(luch, dot_info->normal) > 0)
			dot_info->normal = v_umn(dot_info->normal, -1);
	}
	return (1);
}

double	ft_check_cross_sp(t_list *tmp, t_data *dot_info, t_light *light)
{
	double	t0;
	t_dot	start;
	t_dot	luch;

	while (tmp)
	{
		luch = v_norm(v_minus(light->center, dot_info->dot));
		start = v_plus(dot_info->dot, v_umn(luch, 0.001));
		t0 = ft_return_t0(start, luch, tmp->content);
		if (t0 > 0 && t0 < v_length(v_minus(light->center,
					dot_info->dot)))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
