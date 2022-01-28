/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:44:16 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/04 12:40:44 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

char	*ft_ch_ost(char *ost, char **line)
{
	char	*k;

	k = ft_gnl_strchr(ost, '\n');
	if (k)
	{
		*line = ft_gnl_strcat(*line, ost, k - ost - 1);
		k = ft_gnl_strndup(k, ft_strlen(k));
		free(ost);
		if (!k || !*line)
		{
			if (k)
				free (k);
			return (0);
		}
	}
	else
	{
		*line = ft_gnl_strcat(*line, ost, ft_strlen(ost));
		if (ost)
			free (ost);
		if (!*line)
			return (0);
	}
	return (k);
}

char	*ft_go_k(char **line, char *k, char *buf, int rs)
{
	char	*tmp;

	if (k)
	{
		*line = ft_gnl_strcat(*line, buf, k - buf - 1);
		if (!*line)
			return (0);
		tmp = ft_gnl_strndup(k, ft_gnl_strlen(k));
		if (!tmp)
		{
			free(*line);
			return (0);
		}
		return (tmp);
	}
	*line = ft_gnl_strcat(*line, buf, rs);
	return (0);
}

int	ft_chk_rs(int rs, char **line)
{
	if (rs == 0)
	{
		*line = ft_gnl_strcat(*line, "", 1);
		if (!*line)
			return (-1);
		return (rs);
	}
	return (rs);
}

int	ft_chk_all(int fd, char **line, char **ost)
{
	*line = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	if (*ost)
	{
		*ost = ft_ch_ost(*ost, line);
		if (*ost && !*line)
			return (-1);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*ost;
	char		buf[BUFFER_SIZE + 1];
	char		*k;
	int			rs;

	rs = ft_chk_all(fd, line, &ost);
	if (rs < 1)
		return (-1);
	while (!ost)
	{
		rs = read(fd, buf, BUFFER_SIZE);
		rs = ft_chk_rs(rs, line);
		if (rs < 1)
			return (rs);
		buf[rs] = '\0';
		k = ft_gnl_strchr(buf, '\n');
		ost = ft_go_k(line, k, buf, rs);
		if (!ost && k)
			return (-1);
	}
	return (1);
}
