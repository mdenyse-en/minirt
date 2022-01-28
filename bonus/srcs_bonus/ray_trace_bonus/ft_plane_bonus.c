/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:33:28 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/16 14:47:11 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_trace_bonus.h>

void	ft_found_in_pl_txtrs(t_data *dot_info, int i, int j, t_plane *plane)
{
	if (plane->txtr.img != NULL)
	{
		i = i % plane->txtr.w;
		j = j % plane->txtr.h;
		if (i < 0)
			i = i + plane->txtr.w;
		if (j < 0)
			j = j + plane->txtr.h;
		dot_info->color = ft_get_vec_rgb(plane->txtr.data[i + j
				* (plane->txtr.size_l / 4)]);
		if (plane->txtr_n.img != NULL)
		{
			i = i % plane->txtr_n.w;
			j = j % plane->txtr_n.h;
			dot_info->normal = ft_rotate_vec2(dot_info->normal,
					ft_get_normal_from_rgb(ft_get_vec_rgb(plane->txtr_n.data[i
							+ j * (plane->txtr_n.size_l / 4)])));
		}
	}
}

void	ft_get_dot_info_pl(t_data *dot_info, t_plane *plane, int t)
{
	int	i;
	int	j;

	dot_info->normal = v_umn(plane->vector, t);
	i = v_multipl(v_minus(dot_info->dot, plane->center),
			v_umn(plane->v_x, t)) * PLANE_TXTR_STEP;
	j = v_multipl(v_minus(dot_info->dot, plane->center),
			v_umn(plane->v_y, t)) * PLANE_TXTR_STEP;
	if (plane->txtr.img != NULL)
		ft_found_in_pl_txtrs(dot_info, i, j, plane);
	else if (plane->color.r >= 0)
		dot_info->color = plane->color;
	else
		dot_info->color = ft_get_grid_color(i, j, GRID_STEP);
}

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
			ft_get_dot_info_pl(dot_info, plane, 1);
		else
			ft_get_dot_info_pl(dot_info, plane, -1);
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
