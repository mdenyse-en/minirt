/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:43:18 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/05 11:26:36 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_gnl_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_gnl_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
		if (s[i++] == c)
			return (s + i);
	return (0);
}

char	*ft_gnl_strndup(char *s1, int n)
{
	int		i;
	char	*s;

	i = 0;
	s = malloc((n + 1) * sizeof(char));
	if (!s)
		return (0);
	while (i < n)
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_gnl_strcat(char *s1, char *s2, int rs)
{
	char	*res;
	char	*b;
	int		i;
	int		j;

	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + rs + 1));
	if (!res)
	{
		return (0);
		free (s1);
	}
	i = 0;
	b = s1;
	if (s1 != 0)
		while (*s1)
			res[i++] = *s1++;
	j = -1;
	while (s2[++j] && j < rs)
		res[i + j] = s2[j];
	res[i + j] = '\0';
	if (b)
		free (b);
	return (res);
}
