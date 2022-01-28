/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_structs_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:44:35 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/14 13:08:58 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parcer_bonus.h>

void	ft_all_color_and_txtrs_inite(t_rgb *color, t_img *txtr, t_img *txtr_n)
{
	color->r = -2;
	color->g = -1;
	color->b = -1;
	txtr->img = NULL;
	txtr->data = NULL;
	txtr_n->img = NULL;
	txtr_n->data = NULL;
}

int	ft_fill_rgb(t_rgb *color, char **mas)
{
	if (mas == NULL)
		return (0);
	color->r = ft_atoi(mas[0]);
	color->g = ft_atoi(mas[1]);
	color->b = ft_atoi(mas[2]);
	ft_free_split_mas(mas);
	return (1);
}

int	ft_fill_dot(t_dot *dot, char **mas)
{
	if (mas == NULL)
		return (0);
	dot->x = ft_atod(mas[0]);
	dot->y = ft_atod(mas[1]);
	dot->z = ft_atod(mas[2]);
	ft_free_split_mas(mas);
	return (1);
}
