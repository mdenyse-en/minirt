/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:24:13 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/03 21:05:03 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <scene.h>
# include <math.h>

//vtors_oper.c

double	v_length(t_dot vec);
t_dot	v_minus(t_dot vec1, t_dot vec2);
t_dot	v_plus(t_dot vec1, t_dot vec2);
t_dot	v_razdelit(t_dot vec1, double t);
t_dot	v_umn(t_dot vec1, double t);

//vtors.c

int		ft_normalize(t_dot *vector);
double	v_multipl(t_dot vec1, t_dot vec2);
t_dot	v_cross(t_dot vec1, t_dot vec2);
t_dot	v_norm(t_dot vector);

#endif