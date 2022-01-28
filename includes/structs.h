/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:57:51 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/03 18:24:05 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <scene.h>

# define L_ARROW 123
# define R_ARROW 124
# define UP_ARROW 126
# define DOWN_ARROW 125
# define KEY_A 0
# define KEY_D 2
# define KEY_W 13
# define KEY_S 1
# define KEY_H 4
# define KEY_ESC 53

# define W_WIDTH 1080
# define W_HEIGHT 800

# define MENU_WIDTH 400

# define CAM_LENGTH 1
# define CAM_SPEED 1.5

# define BACK_COLOR 0x00343444 //0x005454D4 //ft_get_color(0,30,30,30)

# define LIGHT_MAX 500

typedef struct s_data
{
	double	dist0;
	t_dot	dot;
	t_dot	normal;
	t_rgb	color;
	void	*figure;
}	t_data;

typedef struct s_keys
{
	char	key_h;
	char	key_esc;
}	t_keys;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		bpp;
	int		size_l;
	int		end;
}	t_img;

typedef struct s_main_struct
{
	void	*mlx;
	void	*win;
	t_img	image;
	t_img	menu;
	t_scene	scene;
	int		width;
	int		height;
	int		oldx;
	int		oldy;
	int		mouse_key_press;
}	t_main_struct;

#endif