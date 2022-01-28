/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:44:46 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/18 11:40:17 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parcer.h>

int	ft_put_to_scene(t_main_struct *m_s, char *line)
{
	if (line[0] == '#')
		return (1);
	else if (line[0] == 'A' && ft_check_line_A(line))
		ft_get_A(m_s, ft_split(line, ' '));
	else if (line[0] == 'C' && ft_check_line_C(line))
		ft_get_C(m_s, ft_split(line, ' '));
	else if (line[0] == 'L' && ft_check_line_L(line))
		ft_get_L(m_s, ft_split(line, ' '));
	else if (ft_strnstr(line, "sp", 2) && ft_check_line_sp(line))
		ft_get_sp(m_s, ft_split(line, ' '));
	else if (ft_strnstr(line, "pl", 2) && ft_check_line_pl(line))
		ft_get_pl(m_s, ft_split(line, ' '));
	else if (ft_strnstr(line, "cy", 2) && ft_check_line_cy(line))
		ft_get_cy(m_s, ft_split(line, ' '));
	else
		return (0);
	return (1);
}

int	ft_parcer(char *file, t_main_struct *m_s)
{
	char	*line;
	int		res_gnl;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	res_gnl = get_next_line(fd, &line);
	while (res_gnl >= 0)
	{
		if (ft_strlen(line) > 0)
		{
			if (!ft_put_to_scene(m_s, line))
				ft_terminate("Error\nFile corrupted!\n", 1, m_s);
		}
		if (res_gnl == 0)
			break ;
		free(line);
		res_gnl = get_next_line(fd, &line);
	}
	free(line);
	close(fd);
	if (!m_s->scene.camera || !m_s->scene.am_light)
		ft_terminate("Error\nNeed a camera and ambient light!\n", 1, m_s);
	return (1);
}
