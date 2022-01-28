/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors_utils_vec_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:28:05 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/15 22:19:14 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color_bonus.h>

int	ft_get_color(int x, int r, int g, int b)
{
	return (x << 24 | r << 16 | g << 8 | b);
}

void	ft_my_pixel_put(t_img *image, int x, int y, int color)
{
	image->data[x + y * image->size_l / 4] = color;
}

t_rgb	ft_get_vec_rgb(int x)
{
	t_rgb	res;

	res.r = x >> 16 & 255;
	res.g = x >> 8 & 255;
	res.b = x & 255;
	return (res);
}

t_rgb	ft_get_grid_color(int i, int j, int step)
{
	t_rgb	res_color;

	if (i >= 0)
		i = i / step % 2;
	else
		i = (-(i + 1) / step + 1) % 2;
	if (j >= 0)
		j = j / step % 2;
	else
		j = (-(j + 1) / step + 1) % 2;
	if ((i == 0 && j == 0) || (i != 0 && j != 0))
		res_color = ft_get_vec_rgb(GRID_COLOR_LIGHT);
	else
		res_color = ft_get_vec_rgb(GRID_COLOR_DARK);
	return (res_color);
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
