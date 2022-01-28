/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vtors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:24:55 by mdenyse           #+#    #+#             */
/*   Updated: 2021/09/30 11:35:20 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vectors_bonus.h>

int	ft_normalize(t_dot *vector)
{
	double	length;

	if (vector->x == 0 && vector->y == 0 && vector->z == 0)
		return (0);
	length = v_length(*vector);
	if (length == 1)
		return (1);
	vector->x = vector->x / length;
	vector->y = vector->y / length;
	vector->z = vector->z / length;
	return (1);
}

double	v_multipl(t_dot vec1, t_dot vec2)
{
	double	res;

	res = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	return (res);
}

t_dot	v_cross(t_dot vec1, t_dot vec2)
{
	t_dot	res;

	res.x = vec1.y * vec2.z - vec2.y * vec1.z;
	res.y = vec1.z * vec2.x - vec2.z * vec1.x;
	res.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (res);
}

t_dot	v_norm(t_dot vector)
{
	t_dot	new;
	double	length;

	length = v_length(vector);
	if (length == 1)
		return (vector);
	new.x = vector.x / length;
	new.y = vector.y / length;
	new.z = vector.z / length;
	return (new);
}
