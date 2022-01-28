/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors_trace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:57:59 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/05 10:50:53 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>

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

t_rgb	ft_get_am_l(t_rgb color, t_am_light *am_l)
{
	t_rgb	res;

	res.r = (float)color.r / 255 * (am_l->ratio * (float)am_l->color.r);
	res.g = (float)color.g / 255 * (am_l->ratio * (float)am_l->color.g);
	res.b = (float)color.b / 255 * (am_l->ratio * (float)am_l->color.b);
	return (res);
}

t_rgb	ft_add_res_color(double k, t_rgb color, t_data dot_info, t_light *light)
{
	if (k < 0)
		k = 0;
	color.r = (k) * (float)light->color.r
		* light->ratio * dot_info.color.r / 255 + color.r;
	color.g = (k) * (float)light->color.g
		* light->ratio * dot_info.color.g / 255 + color.g;
	color.b = (k) * (float)light->color.b
		* light->ratio * dot_info.color.b / 255 + color.b;
	return (color);
}

t_rgb	ft_add_phong_refl(double k, t_rgb color, t_light *light)
{
	color.r = color.r + ft_pow(k, 32)
		* (float)light->color.r * light->ratio * 0.5;
	color.g = color.g + ft_pow(k, 32)
		* (float)light->color.g * light->ratio * 0.5;
	color.b = color.b + ft_pow(k, 32)
		* (float)light->color.b * light->ratio * 0.5;
	return (color);
}

int	ft_trace_color(t_data dot_info, t_main_struct *m_s, t_dot luch)
{
	t_rgb		color;
	t_am_light	*am_l;
	t_light		*light;
	double		k;
	t_dot		line_to_light;

	am_l = m_s->scene.am_light->content;
	if (m_s->scene.l_lights == NULL)
		return (ft_get_vec_color(ft_get_am_l(dot_info.color, am_l)));
	light = m_s->scene.l_lights->content;
	if (ft_check_cross_sp(m_s->scene.l_spheres, &dot_info, light)
		|| ft_check_cross_pl(m_s->scene.l_planes, &dot_info, light)
		|| ft_check_cross_cy(m_s->scene.l_cylinders, &dot_info, light))
		return (ft_get_vec_color(ft_get_shadow(dot_info, am_l)));
	line_to_light = v_norm(v_minus(light->center, dot_info.dot));
	k = v_multipl(dot_info.normal, line_to_light);
	color = ft_add_res_color(k, ft_get_am_l(dot_info.color, am_l),
			dot_info, light);
	k = v_multipl(v_minus(v_umn(dot_info.normal,
					v_multipl(v_umn(luch, 1), dot_info.normal) * 2),
				v_umn(luch, 1)), v_umn(line_to_light, -1));
	if (k > 0)
		color = ft_add_phong_refl(k, color, light);
	return (ft_get_vec_color(color));
}
