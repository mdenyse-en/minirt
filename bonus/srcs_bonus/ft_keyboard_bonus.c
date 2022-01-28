/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:36:48 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/05 11:25:53 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

void	ft_rotate_vector(t_dot *vec, double angX, double angY)
{
	double	x;
	double	y;
	double	z;

	x = vec->x;
	y = vec->y;
	z = vec->z;
	angX = angX / 180 * M_PI;
	angY = angY / 180 * M_PI;
	vec->x = (x * cos(angY) + y * sin(angY) * sin(angX)
			+ z * -sin(angY) * cos(angX));
	vec->y = (x * 0 + y * cos(angX) + z * sin(angX));
	vec->z = (x * sin(angY) + y * -cos(angY) * sin(angX)
			+ z * cos(angX) * cos(angY));
}

int	get_key_rotate(int key, t_list *tmp)
{
	t_sphere	*sphere;

	if (key == 24)
	{
		while (tmp)
		{
			sphere = tmp->content;
			sphere->diameter = sphere->diameter * 1.05;
			tmp = tmp->next;
		}
	}
	else if (key == 27)
	{
		while (tmp)
		{
			sphere = tmp->content;
			sphere->diameter = sphere->diameter * 0.95;
			tmp = tmp->next;
		}
	}
	else
		return (0);
	return (1);
}

int	get_keyboard(int key, t_main_struct *m_s)
{
	t_camera	*c;

	c = m_s->scene.camera->content;
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		c->center = v_plus(c->center, v_umn(c->v, CAM_SPEED));
	else if (key == KEY_S)
		c->center = v_plus(c->center, v_umn(c->v, -CAM_SPEED));
	else if (key == UP_ARROW)
		c->center = v_plus(c->center, v_umn(c->h_vec, CAM_SPEED));
	else if (key == DOWN_ARROW)
		c->center = v_plus(c->center, v_umn(c->h_vec, -CAM_SPEED));
	else if (key == KEY_A)
		c->center = v_plus(c->center, v_umn(c->r_vec, -CAM_SPEED));
	else if (key == KEY_D)
		c->center = v_plus(c->center, v_umn(c->r_vec, CAM_SPEED));
	else if (key == L_ARROW)
		ft_rotate_vector(&c->v, 0, 10);
	else if (key == R_ARROW)
		ft_rotate_vector(&c->v, 0, -10);
	else if (!get_key_rotate(key, m_s->scene.l_spheres))
		return (0);
	ft_draw_scene(m_s);
	return (1);
}
