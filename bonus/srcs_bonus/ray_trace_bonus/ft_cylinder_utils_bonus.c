/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:15:12 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/16 13:45:13 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_trace_bonus.h>
#include <math.h>

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

void	ft_found_in_txtrs(t_data *dot_info, double kx,
	double ky, t_cylinder *cyl)
{
	int	i;
	int	j;

	i = (int)(cyl->txtr.w * kx) % cyl->txtr.w;
	j = (int)(((float)cyl->txtr.w / (cyl->dmt * M_PI)) * ky)
		% cyl->txtr.h;
	dot_info->color = ft_get_vec_rgb(cyl->txtr.data[i + j
			* (cyl->txtr.size_l / 4)]);
	if (cyl->txtr_n.img != NULL)
	{
		i = i % cyl->txtr_n.w;
		j = j % cyl->txtr_n.h;
		dot_info->normal = ft_rotate_vec2(dot_info->normal,
				ft_get_normal_from_rgb(ft_get_vec_rgb(cyl->txtr_n.data[i
						+ j * (cyl->txtr_n.size_l / 4)])));
	}
}

void	ft_get_dot_info_cy_cap(t_data *dot_info, t_cylinder *cyl, double h)
{
	double	kx;
	double	ky;
	t_dot	vec;

	vec = v_minus(dot_info->dot, v_plus(cyl->center, v_umn(cyl->v, h)));
	if (v_multipl(v_norm(vec), cyl->v_x) < 0)
		kx = (2 * M_PI - acos(v_multipl(v_norm(vec), cyl->v_z))) / (2 * M_PI);
	else
		kx = (float)acos(v_multipl(v_norm(vec), cyl->v_z)) / (2 * M_PI);
	ky = v_length(v_minus(dot_info->dot, v_plus(cyl->center,
					v_umn(cyl->v, h))));
	if (h != 0)
		ky = cyl->dmt + cyl->height + (cyl->dmt / 2 - ky);
	if (cyl->txtr.img != NULL)
		ft_found_in_txtrs(dot_info, kx, ky, cyl);
	else if (cyl->color.r != -1)
		dot_info->color = cyl->color;
	else
		dot_info->color = ft_get_grid_color(kx * cyl->dmt
				* M_PI * GRID_STEP, ky * GRID_STEP, GRID_STEP);
}

void	ft_get_dot_info_cy(t_data *dot_info, t_cylinder *cyl, float h)
{
	double	kx;
	double	ky;
	t_dot	z_norm;

	z_norm.x = 0;
	z_norm.y = 0;
	z_norm.z = 1;
	if (v_multipl(dot_info->normal, cyl->v_x) < 0)
		kx = (2 * M_PI - acos(v_multipl(dot_info->normal,
						cyl->v_z))) / (2 * M_PI);
	else
		kx = (float)acos(v_multipl(dot_info->normal, cyl->v_z)) / (2 * M_PI);
	ky = cyl->dmt / 2 + h;
	if (cyl->txtr.img != NULL)
		ft_found_in_txtrs(dot_info, kx, ky, cyl);
	else if (cyl->color.r >= 0)
		dot_info->color = cyl->color;
	else
		dot_info->color = ft_get_grid_color(kx * cyl->dmt
				* M_PI * GRID_STEP, ky * GRID_STEP, GRID_STEP);
}
