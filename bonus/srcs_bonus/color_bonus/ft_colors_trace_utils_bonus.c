/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors_trace_utils_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:52:48 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/16 14:53:20 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color_bonus.h>

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
