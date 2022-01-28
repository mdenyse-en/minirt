/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:58:09 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/17 16:26:35 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCER_BONUS_H
# define PARCER_BONUS_H

# include <structs_bonus.h>
# include <minirt_bonus.h>
# include <vectors_bonus.h>
# include <get_next_line_bonus.h>
# include <fcntl.h>

//ft_am_light.c

int		ft_check_line_A(char *line);
int		ft_get_A(t_main_struct *m_s, char **mas);

//ft_camera.c

int		ft_check_line_C(char *line);
int		ft_get_C(t_main_struct *m_s, char **mas);

//ft_cone.c

int		ft_check_line_co(char *line);
int		ft_get_co(t_main_struct *m_s, char **mas);

//ft_cylinder.c

int		ft_check_line_cy(char *line);
int		ft_get_cy(t_main_struct *m_s, char **mas);

//ft_lights.c

int		ft_check_line_L(char *line);
int		ft_get_L(t_main_struct *m_s, char **mas);

//ft_fill_structs.c

void	ft_all_color_and_txtrs_inite(t_rgb *color, t_img *txtr, t_img *txtr_n);
int		ft_fill_rgb(t_rgb *color, char **mas);
int		ft_fill_dot(t_dot *dot, char **mas);

//ft_parcer_utils.c

int		ft_switch_spaces(char *line, int *i);
int		ft_is_double(char *line, int *i);
int		ft_is_koord_or_color(char *line, int *i);
int		ft_is_color(char *line);

//ft_parcer.c

int		ft_parcer(char *file, t_main_struct *m_s);

//ft_sphere.c

int		ft_check_line_sp(char *line);
int		ft_get_sp(t_main_struct *m_s, char **mas);

//ft_plane.c

int		ft_check_line_pl(char *line);
int		ft_get_pl(t_main_struct *m_s, char **mas);

#endif