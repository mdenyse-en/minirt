/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_am_light_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:44:26 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/05 11:26:33 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parcer_bonus.h>

int	ft_check_line_A(char *line)
{
	int	i;

	i = 1;
	if (!ft_switch_spaces(line, &i))
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

int	ft_get_A(t_main_struct *m_s, char **mas)
{
	t_am_light	*am_light;

	if (mas == NULL)
		ft_terminate("Error\nMalloc, damn!\n", 1, m_s);
	if (m_s->scene.am_light != NULL)
		ft_terminate("Error\nDouble A in file!\n", 1, m_s);
	am_light = malloc(sizeof(t_am_light));
	if (!am_light)
		ft_terminate("Error\nMalloc, damn!\n", 1, m_s);
	am_light->ratio = ft_atod(mas[1]);
	if (!ft_fill_rgb(&(am_light->color), ft_split(mas[2], ',')))
	{
		free(am_light);
		ft_terminate("Error\nMalloc, damn!\n", 1, m_s);
	}
	ft_lstadd_back(&(m_s->scene.am_light), ft_lstnew(am_light));
	ft_free_split_mas(mas);
	if (am_light->ratio < 0 || am_light->ratio > 1)
		ft_terminate("Error\nWrong ratio for ambient light!\n", 1, m_s);
	if (am_light->color.r < 0 || am_light->color.r > 255
		|| am_light->color.g < 0 || am_light->color.g > 255
		|| am_light->color.b < 0 || am_light->color.b > 255)
		ft_terminate("Error\nWrong color for ambient light!\n", 1, m_s);
	return (1);
}
