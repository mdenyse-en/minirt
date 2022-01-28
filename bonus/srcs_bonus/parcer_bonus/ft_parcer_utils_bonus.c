/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:44:43 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/15 22:56:03 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parcer_bonus.h>

int	ft_switch_spaces(char *line, int *i)
{
	if (line[*i] != ' ')
		return (0);
	while (line[*i] == ' ' && line[*i] != '\0')
		*i = *i + 1;
	return (1);
}

int	ft_is_double(char *line, int *i)
{
	int	start;

	if (line[*i] == '\0' || line[*i] == ',' || line[*i] == ' ')
		return (0);
	if (line[*i] == '-' || line[*i] == '+')
		*i = *i + 1;
	start = *i;
	while (ft_isdigit(line[*i]))
		*i = *i + 1;
	if (*i - start > 10 || (*i - start == 10
			&& ft_strncmp(line + start, "2147483647", 10) > 0))
		return (0);
	if (line[*i] == '.')
	{
		*i = *i + 1;
		while (ft_isdigit(line[*i]))
			*i = *i + 1;
	}
	if (!(line[*i] == ' ' || line[*i] == ',' || line[*i] == '\0'))
		return (0);
	return (1);
}

int	ft_is_koord_or_color(char *line, int *i)
{
	if (!ft_is_double(line, i))
		return (0);
	if (line[*i] != ',')
		return (0);
	*i = *i + 1;
	if (!ft_is_double(line, i))
		return (0);
	if (line[*i] != ',')
		return (0);
	*i = *i + 1;
	if (!ft_is_double(line, i))
		return (0);
	if (!(line[*i] == ' ' || line[*i] == '\0'))
		return (0);
	while (line[*i] == ' ' && line[*i] != '\0')
		*i = *i + 1;
	return (1);
}

int	ft_is_color(char *line)
{
	int	i;

	i = 0;
	if (!ft_is_double(line, &i))
		return (0);
	if (line[i] != ',')
		return (0);
	i = i + 1;
	if (!ft_is_double(line, &i))
		return (0);
	if (line[i] != ',')
		return (0);
	i = i + 1;
	if (!ft_is_double(line, &i))
		return (0);
	if (!(line[i] == ' ' || line[i] == '\0'))
		return (0);
	while (line[i] == ' ' && line[i] != '\0')
		i = i + 1;
	return (1);
}
