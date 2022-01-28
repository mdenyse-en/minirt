/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:29:32 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/16 13:31:51 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_trace_bonus.h>

t_angers	ft_find_angles_sp_txtr(t_data *dot_info, t_sphere *sphere)
{
	t_dot		z_norm;
	t_dot		rad;
	t_angers	angers;

	z_norm.x = 0;
	z_norm.y = 0;
	z_norm.z = 1;
	rad = v_minus(dot_info->dot, sphere->center);
	if (rad.z == 0 && rad.x == 0)
	{
		angers.cosY = 0;
		if (rad.y < 0)
			angers.sinY = -1;
		else
			angers.sinY = 1;
	}
	else
	{
		angers.cosY = rad.z / sqrt(rad.z * rad.z + rad.x * rad.x);
		angers.sinY = rad.x / sqrt(rad.z * rad.z + rad.x * rad.x);
	}
	angers.cosX = sqrt(rad.z * rad.z + rad.x * rad.x) / v_length(rad);
	angers.sinX = rad.y / v_length(rad);
	return (angers);
}

void	ft_get_kX_kY(t_data *dot_info, t_sphere *sphere, double *kX, double *kY)
{
	t_angers	angers;

	angers = ft_find_angles_sp_txtr(dot_info, sphere);
	if (angers.sinY > 0)
		*kY = acos(angers.cosY);
	else
		*kY = 2 * M_PI - acos(angers.cosY);
	if (angers.sinX > 0)
		*kX = acos(angers.cosX);
	else
		*kX = 2 * M_PI - acos(angers.cosX);
}
