/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:21:09 by mdenyse           #+#    #+#             */
/*   Updated: 2021/09/07 10:21:10 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_absd(double n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}