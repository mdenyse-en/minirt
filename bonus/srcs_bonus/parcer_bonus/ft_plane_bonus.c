/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:45:02 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/17 14:59:14 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parcer_bonus.h>

void	ft_get_plane_normales(t_plane *pl)
{
	pl->v_x.x = 1;
	pl->v_x.y = 0;
	pl->v_x.z = 0;
	pl->v_y.x = 0;
	pl->v_y.y = 1;
	pl->v_y.z = 0;
	pl->v_x = ft_rotate_vec(pl->v_x, pl->vector);
	pl->v_y = v_cross(pl->vector, pl->v_x);
}

int	ft_check_line_pl(char *line)
{
	int	i;

	i = 2;
	if (!ft_switch_spaces(line, &i))
		return (0);
	if (!ft_is_koord_or_color(line, &i))
		return (0);
	if (!ft_is_koord_or_color(line, &i))
		return (0);
	return (1);
}

void	ft_create_images_pl(t_plane *plane, char *line, t_main_struct *m_s)
{
	if (plane->txtr.img == NULL)
	{
		plane->txtr.img = mlx_xpm_file_to_image(m_s->mlx, line,
				&plane->txtr.w, &plane->txtr.h);
		if (plane->txtr.img != 0)
			plane->txtr.data = (int *)mlx_get_data_addr
				(plane->txtr.img, &plane->txtr.bpp,
					&plane->txtr.size_l, &plane->txtr.end);
	}
	else
	{
		if (plane->txtr_n.img == NULL)
		{
			plane->txtr_n.img = mlx_xpm_file_to_image
				(m_s->mlx, line, &plane->txtr_n.w, &plane->txtr_n.h);
			if (plane->txtr_n.img != 0)
				plane->txtr_n.data = (int *)mlx_get_data_addr
					(plane->txtr_n.img, &plane->txtr_n.bpp,
						&plane->txtr_n.size_l, &plane->txtr_n.end);
		}
	}
}

int	ft_fill_txtr_pl(t_plane *plane, char **mas, int i, t_main_struct *m_s)
{
	ft_all_color_and_txtrs_inite(&plane->color, &plane->txtr, &plane->txtr_n);
	while (mas[++i] != NULL)
	{
		if (i > 5)
			return (0);
		if (ft_isdigit(mas[i][0]))
		{
			if (plane->color.r != -2 || !ft_is_color(mas[i])
				|| !ft_fill_rgb(&(plane->color), ft_split(mas[i], ',')))
				return (0);
		}
		else if (ft_strnstr(mas[i], "./", 2) || ft_strnstr(mas[i], "../", 3))
			ft_create_images_pl(plane, mas[i], m_s);
		else
			return (0);
	}
	return (1);
}

int	ft_get_pl(t_main_struct *m_s, char **mas)
{
	t_plane	*plane;

	if (mas == NULL)
		ft_terminate("Error\nMalloc, damn!\n", 1, m_s);
	plane = malloc(sizeof(t_plane));
	if (!plane)
		ft_terminate("Error\nMalloc, damn!\n", 1, m_s);
	if (!ft_fill_dot(&(plane->center), ft_split(mas[1], ','))
		|| !ft_fill_dot(&(plane->vector), ft_split(mas[2], ','))
		|| !ft_normalize(&(plane->vector))
		|| !ft_fill_txtr_pl(plane, mas, 2, m_s))
	{
		free(plane);
		ft_terminate("Error\nMalloc or plane vector, damn!\n", 1, m_s);
	}
	ft_lstadd_back(&(m_s->scene.l_planes), ft_lstnew(plane));
	ft_free_split_mas(mas);
	if (plane->color.r < 0 || plane->color.r > 255
		|| plane->color.g < 0 || plane->color.g > 255
		|| plane->color.b < 0 || plane->color.b > 255)
		plane->color.r = -1;
	ft_normalize(&(plane->vector));
	ft_get_plane_normales(plane);
	return (1);
}
