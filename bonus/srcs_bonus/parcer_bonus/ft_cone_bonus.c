/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cone_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:10:58 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/17 14:51:46 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parcer_bonus.h>

void	ft_get_cone_normales(t_cone *cone)
{
	cone->v_x.x = 1;
	cone->v_x.y = 0;
	cone->v_x.z = 0;
	cone->v_z.x = 0;
	cone->v_z.y = 0;
	cone->v_z.z = 1;
	cone->v_x = ft_rotate_vec(cone->v_x, cone->v);
	cone->v_z = v_cross(cone->v, cone->v_x);
}

int	ft_check_line_co(char *line)
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

void	ft_create_images_co(t_cone *cone, char *line, t_main_struct *m_s)
{
	if (cone->txtr.img == NULL)
	{
		cone->txtr.img = mlx_xpm_file_to_image(m_s->mlx, line,
				&cone->txtr.w, &cone->txtr.h);
		if (cone->txtr.img != 0)
			cone->txtr.data = (int *)mlx_get_data_addr
				(cone->txtr.img, &cone->txtr.bpp,
					&cone->txtr.size_l, &cone->txtr.end);
	}
	else
	{
		if (cone->txtr_n.img == NULL)
		{
			cone->txtr_n.img = mlx_xpm_file_to_image(m_s->mlx, line,
					&cone->txtr_n.w, &cone->txtr_n.h);
			if (cone->txtr_n.img != 0)
				cone->txtr_n.data = (int *)mlx_get_data_addr
					(cone->txtr_n.img, &cone->txtr_n.bpp,
						&cone->txtr_n.size_l, &cone->txtr_n.end);
		}
	}
}

int	ft_txtr_co(t_cone *cone, char **mas, int i, t_main_struct *m_s)
{
	ft_all_color_and_txtrs_inite(&cone->color, &cone->txtr, &cone->txtr_n);
	while (mas[++i] != NULL)
	{
		if (i > 7)
			return (0);
		if (ft_isdigit(mas[i][0]))
		{
			if (cone->color.r != -2 || !ft_is_color(mas[i])
				|| !ft_fill_rgb(&(cone->color), ft_split(mas[i], ',')))
				return (0);
		}
		else if (ft_strnstr(mas[i], "./", 2) || ft_strnstr(mas[i], "../", 3))
			ft_create_images_co(cone, mas[i], m_s);
		else
			return (0);
	}
	return (1);
}

int	ft_get_co(t_main_struct *m_s, char **mas)
{
	t_cone	*cone;

	if (mas == NULL)
		ft_terminate("Error\nMalloc, damn!\n", 1, m_s);
	cone = malloc(sizeof(t_cone));
	if (!cone)
		ft_terminate("Error\nMalloc, damn!\n", 1, m_s);
	if (!ft_fill_dot(&(cone->center), ft_split(mas[1], ','))
		|| !ft_fill_dot(&(cone->v), ft_split(mas[2], ','))
		|| !ft_normalize(&(cone->v)) || !ft_txtr_co(cone, mas, 4, m_s))
	{
		free(cone);
		ft_terminate("Error\nMalloc or coneus vector, damn!\n", 1, m_s);
	}
	cone->dmt = ft_atod(mas[3]);
	cone->height = ft_atod(mas[4]);
	ft_lstadd_back(&(m_s->scene.l_cones), ft_lstnew(cone));
	ft_free_split_mas(mas);
	if (cone->color.r < 0 || cone->color.r > 255 || cone->color.g < 0
		|| cone->color.g > 255 || cone->color.b < 0 || cone->color.b > 255)
		cone->color.r = -1;
	if (cone->dmt <= 0 || cone->height <= 0)
		ft_terminate("Error\nWrong parameters of coneus!\n", 1, m_s);
	ft_get_cone_normales(cone);
	return (1);
}
