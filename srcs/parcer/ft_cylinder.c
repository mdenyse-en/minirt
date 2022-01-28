/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:44:32 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/03 16:52:01 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parcer.h>

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
	ft_switch_spaces(line, &i);
	if (!ft_is_koord_or_color(line, &i))
		return (0);
	if (line[i] != '\0')
		return (0);
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
		|| !ft_fill_rgb(&(cyl->color), ft_split(mas[5], ','))
		|| !ft_normalize(&(cyl->v)))
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
		ft_terminate("Error\nWrong color for cylinder!\n", 1, m_s);
	if (cyl->dmt <= 0 || cyl->height <= 0)
		ft_terminate("Error\nWrong parameters of cylinder!\n", 1, m_s);
	return (1);
}
