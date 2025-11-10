/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilleu <aguilleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:20:25 by jlepany           #+#    #+#             */
/*   Updated: 2025/11/10 15:59:07 by aguilleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	player_first_angle(t_struct *cub, t_engine *data)
{
	if (cub->p_direction == 'N')
	{
		data->p_dir_x = 0;
		data->p_dir_y = -1;
	}
	if (cub->p_direction == 'E')
	{
		data->p_dir_x = 1;
		data->p_dir_y = 0;
	}
	if (cub->p_direction == 'W')
	{
		data->p_dir_x = -1;
		data->p_dir_y = 0;
	}
	if (cub->p_direction == 'S')
	{
		data->p_dir_x = 0;
		data->p_dir_y = 1;
	}
	data->c_plane_x = -data->p_dir_y;
	data->c_plane_y = data->p_dir_x;
}

double	launch_dda(t_engine	*data, char **map)
{
	data->wall_side = 0;
	while (1)
	{
		if (data->ray_f_side_x < data->ray_f_side_y)
		{
			data->ray_f_side_x += data->ray_delta_x;
			data->map_x += data->step_x;
			data->wall_side = 0;
		}
		else
		{
			data->ray_f_side_y += data->ray_delta_y;
			data->map_y += data->step_y;
			data->wall_side = 1;
		}
		if (map[data->map_y][data->map_x] == '1')
			break ;
	}
	data->wall_hit = wall_side_hit(data, data->wall_side);
	if (data->wall_side)
		return (data->ray_f_side_y - data->ray_delta_y);
	else
		return (data->ray_f_side_x - data->ray_delta_x);
}

void	init_dda(t_engine *data)
{
	if (data->ray_dir_x)
		data->ray_delta_x = fabs(1 / data->ray_dir_x);
	else
		data->ray_delta_x = 1e30;
	if (data->ray_dir_y)
		data->ray_delta_y = fabs(1 / data->ray_dir_y);
	else
		data->ray_delta_y = 1e30;
	if (data->ray_dir_x < 0)
		data->step_x = -1;
	else
		data->step_x = 1;
	if (data->ray_dir_y < 0)
		data->step_y = -1;
	else
		data->step_y = 1;
	if (data->ray_dir_x < 0)
		data->ray_f_side_x = (data->p_x - data->map_x) * data->ray_delta_x;
	else
		data->ray_f_side_x = (data->map_x + 1 - data->p_x) * data->ray_delta_x;
	if (data->ray_dir_y < 0)
		data->ray_f_side_y = (data->p_y - data->map_y) * data->ray_delta_y;
	else
		data->ray_f_side_y = (data->map_y + 1 - data->p_y) * data->ray_delta_y;
}

int	raycasting(t_struct *cub, t_engine *data)
{
	int		x;
	double	wall_distance;

	x = 0;
	while (x < WIDTH)
	{
		data->cplane = 2 * (double)x / WIDTH - 1;
		data->ray_dir_x = data->p_dir_x + data->c_plane_x * data->cplane;
		data->ray_dir_y = data->p_dir_y + data->c_plane_y * data->cplane;
		data->map_x = (int)data->p_x;
		data->map_y = (int)data->p_y;
		init_dda(data);
		wall_distance = launch_dda(data, cub->map);
		data->hit_count = is_new_wall(data, data->hit_count);
		cub->data->wall_txt = get_texture_addr(cub, data->wall_hit);
		print_wall_part(cub, wall_distance, x, data->wall_txt);
		x++;
	}
	return (0);
}

int	raycasting_engine(t_struct *cub)
{
	t_engine	*data;

	data = cub->data;
	raycasting(cub, data);
	auto_move(cub);
	mlx_clear_window(cub->mlx, cub->win);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img, 0, 0);
	return (0);
}
