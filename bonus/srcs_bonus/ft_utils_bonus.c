/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:13:49 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/05 11:25:55 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

void	ft_terminate(char *msg, int code, t_main_struct *m_s)
{
	write(1, msg, ft_strlen(msg));
	ft_free_main_struct(m_s);
	exit(code);
}

int	ft_close_p(t_main_struct m_s)
{
	(void) m_s;
	exit (0);
}

void	ft_free_content(void *content)
{
	free (content);
}

void	ft_free_main_struct(t_main_struct *m_s)
{
	if (m_s->scene.am_light)
		ft_lstclear(&(m_s->scene.am_light), &ft_free_content);
	if (m_s->scene.camera)
		ft_lstclear(&(m_s->scene.camera), &ft_free_content);
	if (m_s->scene.l_lights)
		ft_lstclear(&(m_s->scene.l_lights), &ft_free_content);
	if (m_s->scene.l_spheres)
		ft_lstclear(&(m_s->scene.l_spheres), &ft_free_content);
	if (m_s->scene.l_planes)
		ft_lstclear(&(m_s->scene.l_planes), &ft_free_content);
	if (m_s->scene.l_cylinders)
		ft_lstclear(&(m_s->scene.l_cylinders), &ft_free_content);
}

/*
void	ft_print_scene_data(t_scene *scene)
{
	t_list	*tmp;
	char	*buf;
	t_am_light	*am_light;
	t_camera	*camera;
	t_light		*light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cyl;


	write(1, "------------start----------\n", 28);
	tmp = scene->am_light;
	write(1, "Am_light:\n", 10);
	while (tmp)
	{
		am_light = tmp->content;
		
		buf = ft_dtoa(am_light->ratio, 2);
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free(buf);
		buf = ft_itoa(am_light->color.r);
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free(buf);
		buf = ft_itoa(am_light->color.g);
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free(buf);
		buf = ft_itoa(am_light->color.b);
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free(buf);
		tmp = tmp->next;
	}
	tmp = scene->camera;
	write(1, "Camera:\n", 8);
	while (tmp)
	{
		camera = tmp->content;
		buf = ft_dtoa(camera->center.x, 2);
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free(buf);
		buf = ft_dtoa(camera->center.y, 2);
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free(buf);
		buf = ft_dtoa(camera->center.z, 2);
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free(buf);
		buf = ft_dtoa(camera->v.x, 5);
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free(buf);
		buf = ft_dtoa(camera->v.y, 5);
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free(buf);
		buf = ft_dtoa(camera->v.z, 5);
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free(buf);
		buf = ft_dtoa(camera->fov, 2);
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free(buf);
		tmp = tmp->next;
	}
	tmp = scene->l_lights;
	write(1, "lights:\n", 8);
	while (tmp)
	{
		light = tmp->content;
		
		buf = ft_dtoa(light->center.x, 2);
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free(buf);
		buf = ft_dtoa(light->center.y, 2);
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free(buf);
		buf = ft_dtoa(light->center.z, 2);
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free(buf);

		buf = ft_dtoa(light->ratio, 2);
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free(buf);

		buf = ft_itoa(light->color.r);
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free(buf);
		buf = ft_itoa(light->color.g);
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free(buf);
		buf = ft_itoa(light->color.b);
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free(buf);
		tmp = tmp->next;
	}
	tmp = scene->l_spheres;
	write(1, "Spheres:\n", 9);
	while (tmp)
	{
		sphere = tmp->content;
		printf("diam - %f\n", sphere->diameter);
		buf = ft_dtoa(sphere->diameter, 2);
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free(buf);
		tmp = tmp->next;
	}
	tmp = scene->l_planes;
	write(1, "Planes:\n", 8);
	while (tmp)
	{
		plane = tmp->content;
		buf = ft_dtoa(plane->center.x, 2);
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free(buf);
		tmp = tmp->next;
	}
	tmp = scene->l_cylinders;
	write(1, "Cylinders:\n", 11);
	while (tmp)
	{
		cyl = tmp->content;
		buf = ft_dtoa(cyl->center.x, 2);
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free(buf);
		tmp = tmp->next;
	}
}
*/