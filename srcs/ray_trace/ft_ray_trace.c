/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_trace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:01:16 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/03 20:14:19 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_trace.h>

int	ft_get_first_cross(t_dot start, t_dot luch, t_main_struct *m_s)
{
	t_list	*tmp;
	t_data	dot_info;

	dot_info.dist0 = -1;
	tmp = m_s->scene.l_spheres;
	while (tmp)
	{
		ft_find_cross_sp(start, luch, tmp->content, &dot_info);
		tmp = tmp->next;
	}
	tmp = m_s->scene.l_planes;
	while (tmp)
	{
		ft_find_cross_pl(start, luch, tmp->content, &dot_info);
		tmp = tmp->next;
	}
	tmp = m_s->scene.l_cylinders;
	while (tmp)
	{
		ft_find_cross_cy(start, luch, tmp->content, &dot_info);
		tmp = tmp->next;
	}
	if (dot_info.dist0 < 0)
		return (BACK_COLOR);
	return (ft_trace_color(dot_info, m_s, luch));
}

int	ft_ray_trace(t_dot start, t_main_struct *m_s)
{
	t_dot		luch;
	t_camera	*camera;

	camera = m_s->scene.camera->content;
	luch = v_norm(v_minus(start, camera->center));
	return (ft_get_first_cross(start, luch, m_s));
}

void	ft_rotate(t_dot *dot, t_camera *c)
{
	double	x;
	double	y;
	double	z;

	x = dot->x;
	y = dot->y;
	z = dot->z;
	dot->x = (x * c->cam_v.cosY + y * c->cam_v.sinY
			* c->cam_v.sinX + z * -c->cam_v.sinY * c->cam_v.cosX);
	dot->y = (x * 0 + y * c->cam_v.cosX + z * c->cam_v.sinX);
	dot->z = (x * c->cam_v.sinY + y * -c->cam_v.cosY
			* c->cam_v.sinX + z * c->cam_v.cosX * c->cam_v.cosY);
	return ;
}

int	ft_start_ray(t_main_struct *m_s)
{
	int			i;
	int			j;
	t_dot		start;
	t_camera	*c;

	c = m_s->scene.camera->content;
	j = -1;
	while (++j < m_s->height)
	{
		i = -1;
		while (++i < m_s->width)
		{
			start.x = 0 - c->cam_v.c_width / 2 + i * c->cam_v.pixel_value;
			start.y = 0 + c->cam_v.c_height / 2 - j * c->cam_v.pixel_value;
			start.z = 0;
			ft_rotate(&start, c);
			start = v_plus(v_plus(start, c->center), c->v);
			ft_my_pixel_put(&(m_s->image), i, j, ft_ray_trace(start, m_s));
		}
	}
	return (0);
}
