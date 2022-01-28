/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_main_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <mdenyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:39:56 by mdenyse           #+#    #+#             */
/*   Updated: 2021/10/15 23:18:51 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_bonus.h>

int	ft_inits(t_main_struct *m_s)
{
	m_s->scene.am_light = NULL;
	m_s->scene.camera = NULL;
	m_s->scene.l_lights = NULL;
	m_s->scene.l_spheres = NULL;
	m_s->scene.l_planes = NULL;
	m_s->scene.l_cylinders = NULL;
	m_s->width = W_WIDTH;
	m_s->height = W_HEIGHT;
	return (0);
}

void	ft_draw_scene(t_main_struct *m_s)
{
	ft_start_ray(m_s);
	mlx_put_image_to_window(m_s->mlx, m_s->win, m_s->image.img, 0, 0);
}

int	create_window(t_main_struct *m_s, char *file_name)
{
	m_s->mlx = mlx_init();
	if (!m_s->mlx)
		return (0);
	m_s->win = mlx_new_window(m_s->mlx, m_s->width, m_s->height, "miniRT");
	if (!m_s->win)
		return (0);
	m_s->image.img = mlx_new_image(m_s->mlx, m_s->width, m_s->height);
	if (!m_s->image.img)
		return (0);
	m_s->image.data = (int *)mlx_get_data_addr(m_s->image.img,
			&m_s->image.bpp, &m_s->image.size_l, &m_s->image.end);
	if (!m_s->image.data)
		return (0);
	if (!ft_parcer(file_name, m_s))
		ft_terminate("Error\nCorrupted file\n", 1, m_s);
	ft_draw_scene(m_s);
	mlx_key_hook (m_s->win, get_keyboard, m_s);
	mlx_hook(m_s->win, 17, 0, ft_close_p, m_s);
	mlx_loop(m_s->mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_main_struct	m_s;

	ft_inits(&m_s);
	if (argc != 2 || !ft_strnstr(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3))
		ft_terminate("Error\nMust choose scene .rt file!\n", 1, &m_s);
	if (!create_window(&m_s, argv[1]))
		ft_terminate("Can't creat the window\n", 1, &m_s);
	ft_free_main_struct(&m_s);
	return (0);
}
