/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:44:30 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/03 16:07:46 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parcer_bonus.h>

void	ft_change_cam_vectors(t_camera *c)
{
	double	x;
	double	y;
	double	z;

	x = c->r_vec.x;
	y = c->r_vec.y;
	z = c->r_vec.z;
	c->r_vec.x = (x * c->cam_v.cosY + y * c->cam_v.sinY
			* c->cam_v.sinX + z * -c->cam_v.sinY * c->cam_v.cosX);
	c->r_vec.y = (x * 0 + y * c->cam_v.cosX + z * c->cam_v.sinX);
	c->r_vec.z = (x * c->cam_v.sinY + y * -c->cam_v.cosY
			* c->cam_v.sinX + z * c->cam_v.cosX * c->cam_v.cosY);
	x = c->h_vec.x;
	y = c->h_vec.y;
	z = c->h_vec.z;
	c->h_vec.x = (x * c->cam_v.cosY + y * c->cam_v.sinY
			* c->cam_v.sinX + z * -c->cam_v.sinY * c->cam_v.cosX);
	c->h_vec.y = (x * 0 + y * c->cam_v.cosX + z * c->cam_v.sinX);
	c->h_vec.z = (x * c->cam_v.sinY + y * -c->cam_v.cosY
			* c->cam_v.sinX + z * c->cam_v.cosX * c->cam_v.cosY);
}

void	ft_get_data_cams(t_camera *c, t_main_struct *m_s)
{
	t_angers	ang;

	c->cam_v.c_width = 2 * CAM_LENGTH * tan(c->fov / 2 / (180 / M_PI));
	c->cam_v.pixel_value = c->cam_v.c_width / m_s->width ;
	c->cam_v.c_height = m_s->height * c->cam_v.pixel_value;
	ang = ft_get_angles_from_vec(c->v);
	c->cam_v.sinX = ang.sinX;
	c->cam_v.sinY = ang.sinY;
	c->cam_v.cosX = ang.cosX;
	c->cam_v.cosY = ang.cosY;
	ft_change_cam_vectors(c);
}

static void	ft_get_other_normales(t_camera *c, t_main_struct *m_s)
{
	c->r_vec.x = 1;
	c->r_vec.y = 0;
	c->r_vec.z = 0;
	c->h_vec.x = 0;
	c->h_vec.y = 1;
	c->h_vec.z = 0;
	ft_get_data_cams(c, m_s);
}

int	ft_check_line_C(char *line)
{
	int	i;

	i = 1;
	if (!ft_switch_spaces(line, &i))
		return (0);
	if (!ft_is_koord_or_color(line, &i))
		return (0);
	if (!ft_is_koord_or_color(line, &i))
		return (0);
	if (!ft_is_double(line, &i))
		return (0);
	ft_switch_spaces(line, &i);
	if (line[i] != '\0')
		return (0);
	return (1);
}

int	ft_get_C(t_main_struct *m_s, char **mas)
{
	t_camera	*c;

	if (mas == NULL)
		ft_terminate("Error\nMalloc, damn!\n", 1, m_s);
	if (m_s->scene.camera != NULL)
		ft_terminate("Error\nDouble C in file!\n", 1, m_s);
	if (!mas)
		ft_terminate("Error\nMalloc error!\n", 1, m_s);
	c = (t_camera *)malloc(sizeof(t_camera));
	if (!c)
		ft_terminate("Error\nMalloc, damn!\n", 1, m_s);
	if (!ft_fill_dot(&(c->center), ft_split(mas[1], ','))
		|| !ft_fill_dot(&(c->v), ft_split(mas[2], ','))
		|| !ft_normalize(&(c->v)))
	{
		free(c);
		ft_terminate("Error\nMalloc or c vector, damn!\n", 1, m_s);
	}
	c->fov = ft_atod(mas[3]);
	ft_lstadd_back(&(m_s->scene.camera), ft_lstnew(c));
	ft_free_split_mas(mas);
	if (c->fov < 0 || c->fov > 180)
		ft_terminate("Error\nFov in c is wrong!\n", 1, m_s);
	ft_get_other_normales(c, m_s);
	return (1);
}
