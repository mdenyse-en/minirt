/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:45:05 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/17 14:55:15 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parcer_bonus.h>

int	ft_check_line_sp(char *line)
{
	int	i;

	i = 2;
	if (!ft_switch_spaces(line, &i))
		return (0);
	if (!ft_is_koord_or_color(line, &i))
		return (0);
	if (!ft_is_double(line, &i))
		return (0);
	if (!(line[i] == ' ' || line[i] == '\0'))
		return (0);
	return (1);
}

void	ft_create_images_sp(t_sphere *sphere, char *line, t_main_struct *m_s)
{
	if (sphere->txtr.img == NULL)
	{
		sphere->txtr.img = mlx_xpm_file_to_image(m_s->mlx, line,
				&sphere->txtr.w, &sphere->txtr.h);
		if (sphere->txtr.img != 0)
			sphere->txtr.data = (int *)mlx_get_data_addr
				(sphere->txtr.img, &sphere->txtr.bpp,
					&sphere->txtr.size_l, &sphere->txtr.end);
	}
	else
	{
		if (sphere->txtr_n.img == NULL)
		{
			sphere->txtr_n.img = mlx_xpm_file_to_image(m_s->mlx, line,
					&sphere->txtr_n.w, &sphere->txtr_n.h);
			if (sphere->txtr_n.img != 0)
				sphere->txtr_n.data = (int *)mlx_get_data_addr
					(sphere->txtr_n.img, &sphere->txtr_n.bpp,
						&sphere->txtr_n.size_l, &sphere->txtr_n.end);
		}
	}
}

int	ft_fill_txtr_sp(t_sphere *sphere, char **mas, int i, t_main_struct *m_s)
{
	ft_all_color_and_txtrs_inite(&sphere->color,
		&sphere->txtr, &sphere->txtr_n);
	while (mas[++i] != NULL)
	{
		if (i > 5)
			return (0);
		if (ft_isdigit(mas[i][0]))
		{
			if (sphere->color.r != -2 || !ft_is_color(mas[i])
				|| !ft_fill_rgb(&(sphere->color), ft_split(mas[i], ',')))
				return (0);
		}
		else if (ft_strnstr(mas[i], "./", 2) || ft_strnstr(mas[i], "../", 3))
			ft_create_images_sp(sphere, mas[i], m_s);
		else
			return (0);
	}
	return (1);
}

int	ft_get_sp(t_main_struct *m_s, char **mas)
{
	t_sphere	*sphere;

	if (mas == NULL)
		ft_terminate("Error\nMalloc, damn!\n", 1, m_s);
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		ft_terminate("Error\nMalloc, damn!\n", 1, m_s);
	if (!ft_fill_dot(&(sphere->center), ft_split(mas[1], ','))
		|| !ft_fill_txtr_sp(sphere, mas, 2, m_s))
	{
		free(sphere);
		ft_terminate("Error\nMalloc, damn!\n", 1, m_s);
	}
	sphere->diameter = ft_atod(mas[2]);
	ft_lstadd_back(&(m_s->scene.l_spheres), ft_lstnew(sphere));
	ft_free_split_mas(mas);
	if (sphere->color.r < 0 || sphere->color.r > 255
		|| sphere->color.g < 0 || sphere->color.g > 255
		|| sphere->color.b < 0 || sphere->color.b > 255)
		sphere->color.r = -1;
	if (sphere->diameter <= 0)
		ft_terminate("Error\nWrong diameter of sphere!\n", 1, m_s);
	return (1);
}
