/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vtors_oper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:57:37 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/03 18:52:48 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vectors.h>

double	v_length(t_dot vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_dot	v_minus(t_dot vec1, t_dot vec2)
{
	t_dot	res;

	res.x = (vec1.x - vec2.x);
	res.y = (vec1.y - vec2.y);
	res.z = (vec1.z - vec2.z);
	return (res);
}

t_dot	v_plus(t_dot vec1, t_dot vec2)
{
	t_dot	res;

	res.x = (vec1.x + vec2.x);
	res.y = (vec1.y + vec2.y);
	res.z = (vec1.z + vec2.z);
	return (res);
}

t_dot	v_umn(t_dot vec1, double t)
{
	t_dot	new;

	new.x = vec1.x * t;
	new.y = vec1.y * t;
	new.z = vec1.z * t;
	return (new);
}

t_dot	v_razdelit(t_dot vec1, double t)
{
	t_dot	new;

	new.x = vec1.x / t;
	new.y = vec1.y / t;
	new.z = vec1.z / t;
	return (new);
}
