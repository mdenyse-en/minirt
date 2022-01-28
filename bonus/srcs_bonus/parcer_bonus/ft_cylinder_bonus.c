/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:44:32 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/17 14:45:48 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parcer_bonus.h>

void	ft_get_cylinder_normales(t_cylinder *cyl)
{
	cyl->v_x.x = 1;
	cyl->v_x.y = 0;
	cyl->v_x.z = 0;
	cyl->v_z.x = 0;
	cyl->v_z.y = 0;
	cyl->v_z.z = 1;
	cyl->v_x = ft_rotate_vec(cyl->v_x, cyl->v);
	cyl->v_z = v_cross(cyl->v, cyl->v_x);
}

int	ft_check_line_cy(char *line)
{
	int	i;

	i = 2;
	if (!ft_switch_spaces(line, &i))
		return (0);
	if (!ft_is_koord_or_color(line, &i))
		return (0);
	if (!ft_is_koord_or_color(line, &i))
		return (0);
	if (!ft_is_double(line, &i))
		return (0);
	ft_switch_spaces(line, &i);
	if (!ft_is_double(line, &i))
		return (0);
	if (!(line[i] == ' ' || line[i] == '\0'))
		return (0);
	return (1);
}

void	ft_create_images_cy(t_cylinder *cyl, char *line, t_main_struct *m_s)
{
	if (cyl->txtr.img == NULL)
	{
		cyl->txtr.img = mlx_xpm_file_to_image(m_s->mlx, line,
				&cyl->txtr.w, &cyl->txtr.h);
		if (cyl->txtr.img != 0)
			cyl->txtr.data = (int *)mlx_get_data_addr
				(cyl->txtr.img, &cyl->txtr.bpp,
					&cyl->txtr.size_l, &cyl->txtr.end);
	}
	else
	{
		if (cyl->txtr_n.img == NULL)
		{
			cyl->txtr_n.img = mlx_xpm_file_to_image(m_s->mlx, line,
					&cyl->txtr_n.w, &cyl->txtr_n.h);
			if (cyl->txtr_n.img != 0)
				cyl->txtr_n.data = (int *)mlx_get_data_addr
					(cyl->txtr_n.img, &cyl->txtr_n.bpp,
						&cyl->txtr_n.size_l, &cyl->txtr_n.end);
		}
	}
}

int	ft_txtr_cy(t_cylinder *cyl, char **mas, int i, t_main_struct *m_s)
{
	ft_all_color_and_txtrs_inite(&cyl->color, &cyl->txtr, &cyl->txtr_n);
	while (mas[++i] != NULL)
	{
		if (i > 7)
			return (0);
		if (ft_isdigit(mas[i][0]))
		{
			if (cyl->color.r != -2 || !ft_is_color(mas[i])
				|| !ft_fill_rgb(&(cyl->color), ft_split(mas[i], ',')))
				return (0);
		}
		else if (ft_strnstr(mas[i], "./", 2) || ft_strnstr(mas[i], "../", 3))
			ft_create_images_cy(cyl, mas[i], m_s);
		else
			return (0);
	}
	return (1);
}

int	ft_get_cy(t_main_struct *m_s, char **mas)
{
	t_cylinder	*cyl;

	if (mas == NULL)
		ft_terminate("Error\nMalloc, damn!\n", 1, m_s);
	cyl = malloc(sizeof(t_cylinder));
	if (!cyl)
		ft_terminate("Error\nMalloc, damn!\n", 1, m_s);
	if (!ft_fill_dot(&(cyl->center), ft_split(mas[1], ','))
		|| !ft_fill_dot(&(cyl->v), ft_split(mas[2], ','))
		|| !ft_normalize(&(cyl->v)) || !ft_txtr_cy(cyl, mas, 4, m_s))
	{
		free(cyl);
		ft_terminate("Error\nMalloc or cylinder vector, damn!\n", 1, m_s);
	}
	cyl->dmt = ft_atod(mas[3]);
	cyl->height = ft_atod(mas[4]);
	ft_lstadd_back(&(m_s->scene.l_cylinders), ft_lstnew(cyl));
	ft_free_split_mas(mas);
	if (cyl->color.r < 0 || cyl->color.r > 255 || cyl->color.g < 0
		|| cyl->color.g > 255 || cyl->color.b < 0 || cyl->color.b > 255)
		cyl->color.r = -1;
	if (cyl->dmt <= 0 || cyl->height <= 0)
		ft_terminate("Error\nWrong parameters of cylinder!\n", 1, m_s);
	ft_get_cylinder_normales(cyl);
	return (1);
}
