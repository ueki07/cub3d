/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilleu <aguilleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:01:18 by jlepany           #+#    #+#             */
/*   Updated: 2025/11/10 15:59:05 by aguilleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	end(t_struct *cub, int i)
{
	if (i == 1)
		write(2, "Wrong texture path\n", 19);
	if (cub->data)
		free(cub->data);
	if (cub->img)
	{
		if (cub->img->img)
			mlx_destroy_image(cub->mlx, cub->img->img);
		free(cub->img);
	}
	end_part_two(cub);
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
		mlx_destroy_display(cub->mlx);
	if (cub->mlx)
		free(cub->mlx);
	drop_the_garbage(cub);
	exit(0);
}

int	init_t_wall(t_struct *cub)
{
	int	i;

	cub->wall = ft_calloc(4, sizeof(t_wall *));
	if (!cub->wall)
		end(cub, 0);
	i = 0;
	while (i < 4)
	{
		cub->wall[i] = ft_calloc(1, sizeof(t_wall));
		if (!cub->wall[i])
			end(cub, 0);
		i++;
	}
	return (0);
}

void	set_img(t_struct *cub)
{
	init_t_wall(cub);
	cub->wall[0]->wall = mlx_xpm_file_to_image(cub->mlx, cub->img_name[0],
			&cub->wall[0]->width, &cub->wall[0]->height);
	if (!cub->wall[0]->wall)
		end(cub, 1);
	cub->wall[1]->wall = mlx_xpm_file_to_image(cub->mlx, cub->img_name[2],
			&cub->wall[1]->width, &cub->wall[1]->height);
	if (!cub->wall[1]->wall)
		end(cub, 1);
	cub->wall[2]->wall = mlx_xpm_file_to_image(cub->mlx, cub->img_name[1],
			&cub->wall[2]->width, &cub->wall[2]->height);
	if (!cub->wall[2]->wall)
		end(cub, 1);
	cub->wall[3]->wall = mlx_xpm_file_to_image(cub->mlx, cub->img_name[3],
			&cub->wall[3]->width, &cub->wall[3]->height);
	if (!cub->wall[3]->wall)
		end(cub, 1);
}

int	init_raycasting(t_struct	*garbage)
{
	t_screen	*tmp;

	garbage->img = ft_calloc(1, sizeof(t_screen));
	if (!garbage->img)
		end(garbage, 0);
	garbage->img->img = mlx_new_image(garbage->mlx, WIDTH, HEIGHT);
	if (!garbage->img->img)
		end(garbage, 0);
	tmp = garbage->img;
	tmp->addr = mlx_get_data_addr(tmp->img, &tmp->bpp, &tmp->len, &tmp->endian);
	garbage->data = ft_calloc(1, sizeof(t_engine));
	if (!garbage->data)
		return (1);
	garbage->data->p_x = garbage->p_xy[0] + 0.5;
	garbage->data->p_y = garbage->p_xy[1] + 0.5;
	player_first_angle(garbage, garbage->data);
	return (0);
}

int	mlx_start(t_struct *garbage)
{
	garbage->mlx = mlx_init();
	if (!garbage->mlx)
		return (error_detected(NULL, "MLX Initialization failed"));
	garbage->win = mlx_new_window(garbage->mlx, WIDTH, HEIGHT,
			"le s pif d'Adrien qui me laisse le plus chiant du projet");
	if (!garbage->win)
		end(garbage, 0);
	set_img(garbage);
	mlx_hook(garbage->win, 2, 1L << 0, handle_keys, garbage);
	mlx_hook(garbage->win, 3, 1L << 1, handle_key_release, garbage);
	mlx_hook(garbage->win, 17, 1L << 2, end, garbage);
	mlx_loop_hook(garbage->mlx, raycasting_engine, garbage);
	init_raycasting(garbage);
	raycasting_engine(garbage);
	mlx_loop(garbage->mlx);
	return (0);
}
