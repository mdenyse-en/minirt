/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:58:52 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/17 16:26:05 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include <scene.h>
# include <ray_trace.h>
# include <parcer.h>

//ft_keyboard.c

int		get_keyboard(int key, t_main_struct *m_s);

//ft_utils.c

void	ft_free_main_struct(t_main_struct *m_s);
void	ft_terminate(char *msg, int code, t_main_struct *m_s);
int		ft_close_p(t_main_struct m_s);
void	ft_print_scene_data(t_scene *scene);

//ft_minirt.c

void	ft_draw_scene(t_main_struct *m_s);

#endif