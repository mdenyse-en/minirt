/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:45:02 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/03 18:31:16 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parcer.h>

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
	if (!ft_is_koord_or_color(line, &i))
		return (0);
	if (line[i] != '\0')
		return (0);
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
		|| !ft_fill_rgb(&(plane->color), ft_split(mas[3], ','))
		|| !ft_normalize(&(plane->vector)))
	{
		free(plane);
		ft_terminate("Error\nMalloc or plane vector, damn!\n", 1, m_s);
	}
	ft_lstadd_back(&(m_s->scene.l_planes), ft_lstnew(plane));
	ft_free_split_mas(mas);
	if (plane->color.r < 0 || plane->color.r > 255
		|| plane->color.g < 0 || plane->color.g > 255
		|| plane->color.b < 0 || plane->color.b > 255)
		ft_terminate("Error\nWrong color for plane!\n", 1, m_s);
	ft_normalize(&(plane->vector));
	return (1);
}
