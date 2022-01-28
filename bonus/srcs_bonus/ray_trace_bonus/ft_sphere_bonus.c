/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:33:24 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/16 14:47:23 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_trace_bonus.h>

void	ft_found_in_sp_txtrs(t_data *dot_info, double kX,
	double kY, t_sphere *sphere)
{
	int	i;
	int	j;

	i = (int)(1 * kY * (float)(sphere->txtr.w) / (float)(M_PI));
	j = (int)(1 * kX * (float)(sphere->txtr.h) / (float)(M_PI));
	if (i >= sphere->txtr.w)
		i = i % sphere->txtr.w;
	if (j >= sphere->txtr.h)
		j = j % sphere->txtr.h;
	dot_info->color = ft_get_vec_rgb(sphere->txtr.data[i + j
			* (sphere->txtr.size_l / 4)]);
	if (sphere->txtr_n.img)
	{
		i = i % sphere->txtr_n.w;
		j = j % sphere->txtr_n.h;
		dot_info->normal = ft_rotate_vec(dot_info->normal,
				ft_get_normal_from_rgb(ft_get_vec_rgb(sphere->txtr_n.data[i + j
						* (sphere->txtr_n.size_l / 4)])));
	}
}

void	ft_get_dot_info_sp(t_data *dot_info, t_sphere *sphere)
{
	int			i;
	int			j;
	double		kX;
	double		kY;

	ft_get_kX_kY(dot_info, sphere, &kX, &kY);
	if (sphere->txtr.img)
		ft_found_in_sp_txtrs(dot_info, kX, kY, sphere);
	else if (sphere->color.r >= 0)
		dot_info->color = sphere->color;
	else
	{
		i = (int)(1 * kY * (float)(sphere->diameter) / (float)(M_PI));
		j = (int)(1 * kX * (float)(sphere->diameter) / (float)(M_PI));
		dot_info->color = ft_get_grid_color(i * GRID_STEP,
				j * GRID_STEP, GRID_STEP);
	}
}

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
		ft_get_dot_info_sp(dot_info, sphere);
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
