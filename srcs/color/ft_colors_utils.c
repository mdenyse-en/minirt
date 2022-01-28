/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:14:01 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/03 20:46:40 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>

int	ft_get_color(int x, int r, int g, int b)
{
	return (x << 24 | r << 16 | g << 8 | b);
}

void	ft_check_max_min_color(t_rgb *color)
{
	if (color->r > 255)
		color->r = 255;
	if (color->g > 255)
		color->g = 255;
	if (color->b > 255)
		color->b = 255;
	if (color->r < 0)
		color->r = 0;
	if (color->g < 0)
		color->g = 0;
	if (color->b < 0)
		color->b = 0;
}

int	ft_get_vec_color(t_rgb color)
{
	ft_check_max_min_color(&color);
	return (ft_get_color(0, color.r, color.g, color.b));
}

void	ft_my_pixel_put(t_img *image, int x, int y, int color)
{
	image->data[x + y * image->size_l / 4] = color;
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
