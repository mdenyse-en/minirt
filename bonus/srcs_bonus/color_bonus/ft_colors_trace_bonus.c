/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors_trace_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:57:59 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/16 23:09:35 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color_bonus.h>

double	ft_pow(double x, int power)
{
	int		i;
	double	res;

	if (x == 0)
		return (1);
	i = 0;
	res = x;
	while (i++ < power)
		res = res * x;
	return (res);
}

t_rgb	ft_add_phong_refl(double k, t_rgb color, t_light *light)
{
	color.r = color.r + ft_pow(k, 32)
		* (float)light->color.r * light->ratio * 0.6;
	color.g = color.g + ft_pow(k, 32)
		* (float)light->color.g * light->ratio * 0.6;
	color.b = color.b + ft_pow(k, 32)
		* (float)light->color.b * light->ratio * 0.6;
	return (color);
}

t_rgb	ft_return_phong_refl(double k, t_light *light)
{
	t_rgb	color;

	color.r = ft_pow(k, 32)
		* (float)light->color.r * light->ratio * 0.6;
	color.g = ft_pow(k, 32)
		* (float)light->color.g * light->ratio * 0.6;
	color.b = ft_pow(k, 32)
		* (float)light->color.b * light->ratio * 0.6;
	return (color);
}

void	ft_apply_light(t_data *dot_info, t_main_struct *m_s,
	t_light *light, t_vars *v)
{
	t_am_light	*am_l;

	am_l = m_s->scene.am_light->content;
	if (!(ft_check_cross_sp(m_s->scene.l_spheres, dot_info, light)
			|| ft_check_cross_pl(m_s->scene.l_planes, dot_info, light)
			|| ft_check_cross_cy(m_s->scene.l_cylinders, dot_info, light)
			|| ft_check_cross_co(m_s->scene.l_cones, dot_info, light)))
	{
		v->len = v_norm(v_minus(light->center, dot_info->dot));
		v->k = v_multipl(dot_info->normal, v->len);
		v->color = ft_check_color(*dot_info,
				ft_add_l_color(*dot_info, light, v->color, v->k), am_l);
		v->k = v_multipl(v_minus(v_umn(dot_info->normal,
						v_multipl(v_umn(v->luch, 1), dot_info->normal) * 2),
					v_umn(v->luch, 1)), v_umn(v->len, -1));
		if (v->k >= 0)
			dot_info->refl = ft_col_plus(dot_info->refl,
					ft_return_phong_refl(v->k, light));
	}
}

int	ft_trace_color(t_data dot_info, t_main_struct *m_s, t_dot luch)
{
	t_am_light	*am_l;
	t_light		*light;
	t_list		*tmp;
	t_vars		v;

	dot_info.refl = ft_new_rgb(0, 0, 0);
	am_l = m_s->scene.am_light->content;
	v.color = ft_get_shadow(dot_info, am_l);
	v.luch = luch;
	if (m_s->scene.l_lights == NULL)
		return (ft_get_vec_color(v.color));
	tmp = m_s->scene.l_lights;
	while (tmp)
	{
		light = tmp->content;
		ft_apply_light(&dot_info, m_s, light, &v);
		tmp = tmp->next;
	}
	return (ft_get_vec_color(ft_col_plus(ft_check_color(dot_info,
					v.color, am_l), dot_info.refl)));
}
