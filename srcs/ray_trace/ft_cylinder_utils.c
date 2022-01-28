/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:15:12 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/03 20:17:55 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_trace.h>

double	ft_find_t0_cyl(t_dot start, t_dot luch, t_cylinder *cyl)
{
	t_vars	vars;

	vars.x = v_minus(start, cyl->center);
	vars.a = v_multipl(luch, luch) - v_multipl(luch,
			cyl->v) * v_multipl(luch, cyl->v);
	vars.b = 2 * (v_multipl(luch, vars.x) - (v_multipl(luch,
					cyl->v) * v_multipl(vars.x, cyl->v)));
	vars.c = v_multipl(vars.x, vars.x) - v_multipl(vars.x,
			cyl->v) * v_multipl(vars.x, cyl->v) - cyl->dmt * cyl->dmt / 4;
	vars.d2 = vars.b * vars.b - 4 * vars.a * vars.c;
	if (vars.d2 < 0)
		return (-1);
	vars.t0 = (-vars.b - sqrt(vars.d2)) / (2 * vars.a);
	vars.t1 = (-vars.b + sqrt(vars.d2)) / (2 * vars.a);
	if (vars.t0 < 0)
		vars.t0 = vars.t1;
	return (vars.t0);
}

t_plane	g_pl(t_dot center, t_dot vector, t_rgb color)
{
	t_plane	p;

	p.center = center;
	p.vector = vector;
	p.color = color;
	return (p);
}
