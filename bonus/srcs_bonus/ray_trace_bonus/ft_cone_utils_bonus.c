/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cone_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:15:12 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/16 13:59:20 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_trace_bonus.h>
#include <math.h>

void	ft_find_t0_cone(t_dot start, t_dot luch, t_cone *cone, t_vars *v)
{
	v->k = cone->dmt / cone->height / 2;
	v->x = v_minus(start, cone->center);
	v->a = v_multipl(luch, luch) - (1 + v->k * v->k) * v_multipl(luch,
			cone->v) * v_multipl(luch, cone->v);
	v->b = 2 * (v_multipl(luch, v->x) - (1 + v->k * v->k) * (v_multipl(luch,
					cone->v) * v_multipl(v->x, cone->v)));
	v->c = v_multipl(v->x, v->x) - (1 + v->k * v->k) * v_multipl(v->x,
			cone->v) * v_multipl(v->x, cone->v);
	v->d2 = v->b * v->b - 4 * v->a * v->c;
	if (v->d2 < 0)
	{
		v->t0 = -1;
		return ;
	}
	v->t0 = (-v->b - sqrt(v->d2)) / (2 * v->a);
	v->t1 = (-v->b + sqrt(v->d2)) / (2 * v->a);
	if (v->t0 < 0)
		v->t0 = v->t1;
}

void	ft_found_in_co_txtrs(t_data *dot_info, double kx,
	double ky, t_cone *cone)
{
	int	i;
	int	j;

	i = (int)(cone->txtr.w * kx) % cone->txtr.w;
	j = (int)(((float)cone->txtr.w / (cone->dmt * M_PI))
			* ky) % cone->txtr.h;
	dot_info->color = ft_get_vec_rgb(cone->txtr.data[i + j
			* (cone->txtr.size_l / 4)]);
	if (cone->txtr_n.img != NULL)
	{
		i = i % cone->txtr_n.w;
		j = j % cone->txtr_n.h;
		dot_info->normal = ft_rotate_vec2(dot_info->normal,
				ft_get_normal_from_rgb(ft_get_vec_rgb(cone->txtr_n.data[i + j
						* (cone->txtr_n.size_l / 4)])));
	}
}

void	ft_get_dot_info_co_cap(t_data *dot_info, t_cone *cone, double h)
{
	double	kx;
	double	ky;
	t_dot	vec;

	vec = v_minus(dot_info->dot, v_plus(cone->center, v_umn(cone->v, h)));
	if (v_multipl(v_norm(vec), cone->v_x) < 0)
		kx = (2 * M_PI - acos(v_multipl(v_norm(vec), cone->v_z))) / (2 * M_PI);
	else
		kx = (float)acos(v_multipl(v_norm(vec), cone->v_z)) / (2 * M_PI);
	ky = v_length(v_minus(dot_info->dot, v_plus(cone->center,
					v_umn(cone->v, h))));
	if (h != 0)
		ky = cone->dmt + cone->height + (cone->dmt / 2 - ky);
	if (cone->txtr.img != NULL)
		ft_found_in_co_txtrs(dot_info, kx, ky, cone);
	else if (cone->color.r != -1)
		dot_info->color = cone->color;
	else
		dot_info->color = ft_get_grid_color(kx * cone->dmt * M_PI * GRID_STEP,
				ky * GRID_STEP, GRID_STEP);
}

void	ft_get_dot_info_co(t_data *dot_info, t_cone *cone, float h)
{
	double	kx;
	double	ky;
	t_dot	z_norm;

	z_norm.x = 0;
	z_norm.y = 0;
	z_norm.z = 1;
	if (v_multipl(dot_info->normal, cone->v_x) < 0)
		kx = (2 * M_PI - acos(v_multipl(dot_info->normal,
						cone->v_z))) / (2 * M_PI);
	else
		kx = (float)acos(v_multipl(dot_info->normal, cone->v_z)) / (2 * M_PI);
	ky = cone->dmt / 2 + h;
	if (cone->txtr.img != NULL)
		ft_found_in_co_txtrs(dot_info, kx, ky, cone);
	else if (cone->color.r >= 0)
		dot_info->color = cone->color;
	else
		dot_info->color = ft_get_grid_color(kx * cone->dmt * M_PI * GRID_STEP,
				ky * GRID_STEP, GRID_STEP);
}
