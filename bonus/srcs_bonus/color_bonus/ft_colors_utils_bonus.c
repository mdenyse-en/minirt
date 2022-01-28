/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:14:01 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/16 23:13:41 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color_bonus.h>

t_rgb	ft_check_color(t_data dot_info, t_rgb color, t_am_light *am_l)
{
	t_rgb	shadow;

	shadow = ft_get_shadow(dot_info, am_l);
	if (color.r > dot_info.color.r)
		color.r = dot_info.color.r;
	if (color.g > dot_info.color.g)
		color.g = dot_info.color.g;
	if (color.b > dot_info.color.b)
		color.b = dot_info.color.b;
	if (color.r < shadow.r)
		color.r = shadow.r;
	if (color.g < shadow.g)
		color.g = shadow.g;
	if (color.b < shadow.b)
		color.b = shadow.b;
	return (color);
}

int	ft_get_vec_color(t_rgb color)
{
	ft_check_max_min_color(&color);
	return (ft_get_color(0, color.r, color.g, color.b));
}

t_rgb	ft_get_shadow(t_data dot_info, t_am_light *am_l)
{
	t_rgb	res_color;

	res_color.r = (float)dot_info.color.r / 255
		* (am_l->ratio * (float)am_l->color.r);
	res_color.g = (float)dot_info.color.g / 255
		* (am_l->ratio * (float)am_l->color.g);
	res_color.b = (float)dot_info.color.b / 255
		* (am_l->ratio * (float)am_l->color.b);
	return (res_color);
}

t_rgb	ft_add_shadow(t_data dot_info, t_light *l, t_rgb color)
{
	t_rgb	res_color;

	res_color.r = color.r - 1.0 * (float)dot_info.color.r / 255
		* (l->ratio * (float)l->color.r);
	res_color.g = color.g - 1.0 * (float)dot_info.color.g / 255
		* (l->ratio * (float)l->color.g);
	res_color.b = color.b - 1.0 * (float)dot_info.color.b / 255
		* (l->ratio * (float)l->color.b);
	return (res_color);
}

t_rgb	ft_add_l_color(t_data dot_info, t_light *light, t_rgb color, double k)
{
	t_rgb	res_color;

	if (k > 0)
	{
		res_color.r = (k) * (float)light->color.r
			* light->ratio * dot_info.color.r / 255 + color.r;
		res_color.g = (k) * (float)light->color.g
			* light->ratio * dot_info.color.g / 255 + color.g;
		res_color.b = (k) * (float)light->color.b
			* light->ratio * dot_info.color.b / 255 + color.b;
	}
	else
		return (color);
	return (res_color);
}
