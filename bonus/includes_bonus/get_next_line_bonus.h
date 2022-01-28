/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:59:04 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/15 22:06:54 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include "../../libft/libft.h"

# define BUFFER_SIZE 30

int		get_next_line(int fd, char **line);
char	*ft_gnl_strcat(char *s1, char *s2, int rs);
char	*ft_gnl_strchr(char *s, char c);
char	*ft_gnl_strndup(char *s1, int n);
int		ft_gnl_strlen(char *s);

#endif