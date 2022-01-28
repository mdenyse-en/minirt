/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:24:13 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/15 22:10:49 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_BONUS_H
# define VECTORS_BONUS_H

# include <scene_bonus.h>
# include <math.h>

//vtors_oper.c

double		v_length(t_dot vec);
t_dot		v_minus(t_dot vec1, t_dot vec2);
t_dot		v_plus(t_dot vec1, t_dot vec2);
t_dot		v_razdelit(t_dot vec1, double t);
t_dot		v_umn(t_dot vec1, double t);

//vtors.c

int			ft_normalize(t_dot *vector);
double		v_multipl(t_dot vec1, t_dot vec2);
t_dot		v_cross(t_dot vec1, t_dot vec2);
t_dot		v_norm(t_dot vector);

//ft_vectors_rotate.c

t_dot		ft_get_normal_from_rgb(t_rgb color);
t_angers	ft_get_angles_from_vec(t_dot norm);
t_angers	ft_get_angles_from_vec2(t_dot norm);
t_dot		ft_rotate_vec(t_dot dot, t_dot norm);
t_dot		ft_rotate_vec2(t_dot dot, t_dot norm);
t_dot		ft_rotate_vec_xy(t_dot dot, t_dot norm);
t_dot		ft_rotate_vec_os_x(t_dot dot, t_dot norm);
t_dot		ft_rotate_vec_os_y(t_dot dot, t_dot norm);

#endif