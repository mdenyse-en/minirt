/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lights_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:44:41 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/12 18:33:46 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parcer_bonus.h>

int	ft_check_line_L(char *line)
{
	int	i;

	i = 1;
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

int	ft_get_L(t_main_struct *m_s, char **mas)
{
	t_light	*light;

	if (mas == NULL)
		ft_terminate("Error\nMalloc, damn!\n", 1, m_s);
	light = malloc(sizeof(t_light));
	if (!light)
		ft_terminate("Error\nMalloc, damn!\n", 1, m_s);
	if (!ft_fill_dot(&(light->center), ft_split(mas[1], ','))
		|| !ft_fill_rgb(&(light->color), ft_split(mas[3], ',')))
	{
		free(light);
		ft_terminate("Error\nMalloc, damn!\n", 1, m_s);
	}
	light->ratio = ft_atod(mas[2]);
	ft_lstadd_back(&(m_s->scene.l_lights), ft_lstnew(light));
	ft_free_split_mas(mas);
	if (light->color.r < 0 || light->color.r > 255
		|| light->color.g < 0 || light->color.g > 255
		|| light->color.b < 0 || light->color.b > 255)
		ft_terminate("Error\nWrong color for light!\n", 1, m_s);
	if (light->ratio < 0 || light->ratio > 1)
		ft_terminate("Error\nWrong ratio of light!\n", 1, m_s);
	return (1);
}
