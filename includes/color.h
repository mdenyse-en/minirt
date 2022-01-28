/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:15:57 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/03 20:46:13 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <ray_trace.h>
# include <structs.h>
# include <vectors.h>

//ft_colors_trace.c

int		ft_trace_color(t_data dot_info, t_main_struct *m_s, t_dot luch);

//ft_colors_utils.c

int		ft_get_color(int x, int r, int g, int b);
int		ft_get_vec_color(t_rgb color);
void	ft_check_max_min_color(t_rgb *color);
void	ft_my_pixel_put(t_img *image, int x, int y, int color);
t_rgb	ft_get_shadow(t_data dot_info, t_am_light *am_l);

//ft_colors_vec.c

t_rgb	ft_col_minus(t_rgb vec1, t_rgb vec2);
t_rgb	ft_col_plus(t_rgb vec1, t_rgb vec2);
t_rgb	ft_col_plus_t(t_rgb vec1, double t);
t_rgb	ft_col_umn(t_rgb vec1, double t);
t_rgb	ft_col_razd(t_rgb vec1, double t);

#endif