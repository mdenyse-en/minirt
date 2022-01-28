/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:58:52 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/17 16:25:29 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include <mlx.h>
# include <scene_bonus.h>
# include <ray_trace_bonus.h>
# include <parcer_bonus.h>

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