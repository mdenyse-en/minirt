/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:09:13 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/16 15:00:46 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vectors_bonus.h>

t_dot	ft_get_normal_from_rgb(t_rgb color)
{
	t_dot	normal;

	normal.x = (float)color.r / 255 * 2 - 1;
	normal.y = (float)color.g / 255 * 2 - 1;
	normal.z = (float)color.b / 255 * 2 - 1;
	normal = v_norm(normal);
	return (normal);
}

t_angers	ft_get_angles_from_vec2(t_dot norm)
{
	t_angers	ang;

	if (norm.z != 0)
	{
		ang.sinY = (-norm.x / sqrt(norm.x * norm.x + norm.z * norm.z));
		ang.cosY = (norm.z / sqrt(norm.x * norm.x + norm.z * norm.z));
		ang.sinX = (norm.y);
		ang.cosX = sqrt(norm.x * norm.x + norm.z * norm.z);
	}
	else
	{
		ang.sinY = -1;
		ang.cosY = 0;
		ang.sinX = (norm.y);
		ang.cosX = (norm.x);
	}
	return (ang);
}

t_dot	ft_rotate_vec2(t_dot dot, t_dot norm)
{
	double		x;
	double		y;
	double		z;
	t_angers	angers;

	angers = ft_get_angles_from_vec2(norm);
	x = dot.x;
	y = dot.y;
	z = dot.z;
	if (dot.z < 0)
	{
		angers.sinX = angers.sinX;
		angers.sinY = angers.sinY;
		angers.cosX = angers.cosX;
		angers.cosY = angers.cosY;
	}
	dot.x = (x * angers.cosY + y * angers.sinY
			* angers.sinX + z * -angers.sinY * angers.cosX);
	dot.y = (x * 0 + y * angers.cosX + z * angers.sinX);
	dot.z = (x * angers.sinY + y * -angers.cosY
			* angers.sinX + z * angers.cosX * angers.cosY);
	return (dot);
}

t_angers	ft_get_angles_from_vec(t_dot norm)
{
	t_angers	ang;

	if (norm.z != 0)
	{
		ang.sinY = (-norm.x / sqrt(norm.x * norm.x + norm.z * norm.z));
		ang.cosY = (norm.z / sqrt(norm.x * norm.x + norm.z * norm.z));
		ang.sinX = (norm.y);
		ang.cosX = sqrt(norm.x * norm.x + norm.z * norm.z);
	}
	else
	{
		ang.sinY = -1;
		ang.cosY = 0;
		ang.sinX = (norm.y);
		ang.cosX = (norm.x);
	}	
	return (ang);
}

t_dot	ft_rotate_vec(t_dot dot, t_dot norm)
{
	double		x;
	double		y;
	double		z;
	t_angers	angers;

	angers = ft_get_angles_from_vec(norm);
	x = dot.x;
	y = dot.y;
	z = dot.z;
	dot.x = (x * angers.cosY + y * angers.sinY
			* angers.sinX + z * -angers.sinY * angers.cosX);
	dot.y = (x * 0 + y * angers.cosX + z * angers.sinX);
	dot.z = (x * angers.sinY + y * -angers.cosY
			* angers.sinX + z * angers.cosX * angers.cosY);
	return (dot);
}
