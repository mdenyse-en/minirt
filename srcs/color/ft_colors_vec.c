/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors_vec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:35:45 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/03 20:34:57 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>

t_rgb	ft_col_minus(t_rgb vec1, t_rgb vec2)
{
	t_rgb	res;

	res.r = (vec1.r - vec2.r);
	res.g = (vec1.g - vec2.g);
	res.b = (vec1.b - vec2.b);
	return (res);
}

t_rgb	ft_col_plus(t_rgb vec1, t_rgb vec2)
{
	t_rgb	res;

	res.r = (vec1.r + vec2.r);
	res.g = (vec1.g + vec2.g);
	res.b = (vec1.b + vec2.b);
	return (res);
}

t_rgb	ft_col_plus_t(t_rgb vec1, double t)
{
	t_rgb	res;

	res.r = (vec1.r + t);
	res.g = (vec1.g + t);
	res.b = (vec1.b + t);
	return (res);
}

t_rgb	ft_col_umn(t_rgb vec1, double t)
{
	t_rgb	new;

	new.r = vec1.r * t;
	new.g = vec1.g * t;
	new.b = vec1.b * t;
	return (new);
}

t_rgb	ft_col_razd(t_rgb vec1, double t)
{
	t_rgb	new;

	new.r = vec1.r / t;
	new.g = vec1.g / t;
	new.b = vec1.b / t;
	return (new);
}
