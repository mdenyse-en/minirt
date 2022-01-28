/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:57:51 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/16 14:49:27 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

# include <scene_bonus.h>

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

# define W_WIDTH 800
# define W_HEIGHT 600

# define MENU_WIDTH 400

# define CAM_LENGTH 1
# define CAM_SPEED 1.5

# define BACK_COLOR 0x00343444 //0x005454D4 //ft_get_color(0,30,30,30)
# define GRID_COLOR_LIGHT 0x00E1E1E1
# define GRID_COLOR_DARK 0x00AFAFAF
# define GRID_STEP 10
# define PLANE_TXTR_STEP 10

# define LIGHT_MAX 500

typedef struct s_data
{
	double	dist0;
	t_dot	dot;
	t_dot	normal;
	t_rgb	color;
	t_rgb	refl;
	t_dot	luch;
}	t_data;

typedef struct s_keys
{
	char	key_h;
	char	key_esc;
}	t_keys;

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