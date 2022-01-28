/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors_rotate_utils_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:00:16 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/16 15:00:56 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vectors_bonus.h>

t_dot	ft_rotate_vec_xy(t_dot dot, t_dot norm)
{
	t_dot		res;
	t_angers	ang;

	ang = ft_get_angles_from_vec(norm);
	res.x = dot.x * ang.cosY + dot.y * ang.cosY * ang.cosX
		+ dot.z * ang.cosY * ang.cosX;
	res.y = dot.x * 0 + dot.y * ang.cosX + dot.z * -ang.sinX;
	res.z = dot.x * -ang.sinX + dot.y * ang.cosY * ang.sinX
		+ dot.z * ang.cosY * ang.cosX;
	return (res);
}

t_dot	ft_rotate_vec_os_x(t_dot vector, t_dot norm)
{
	t_dot		res;
	t_angers	ang;

	ang = ft_get_angles_from_vec(norm);
	res.x = vector.x;
	res.y = vector.y * ang.cosX + vector.z * ang.sinX;
	res.z = vector.y * -ang.sinX + vector.z * ang.cosX;
	return (res);
}

t_dot	ft_rotate_vec_os_y(t_dot vector, t_dot norm)
{
	t_dot		res;
	t_angers	ang;

	ang = ft_get_angles_from_vec(norm);
	res.x = vector.x * ang.cosY - ang.sinY * vector.z;
	res.y = vector.y;
	res.z = vector.x * ang.sinY + vector.z * ang.cosY;
	return (res);
}
