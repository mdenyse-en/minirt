/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:45:05 by mdenyse           #+#    #+#             */
/*   Updated: 2021/09/04 13:56:19 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parcer.h>

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
	if (!ft_switch_spaces(line, &i))
		return (0);
	if (!ft_is_koord_or_color(line, &i))
		return (0);
	if (line[i] != '\0')
		return (0);
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
		|| !ft_fill_rgb(&(sphere->color), ft_split(mas[3], ',')))
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
		ft_terminate("Error\nWrong color for sphere!\n", 1, m_s);
	if (sphere->diameter <= 0)
		ft_terminate("Error\nWrong diameter of sphere!\n", 1, m_s);
	return (1);
}
