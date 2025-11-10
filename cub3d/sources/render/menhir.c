/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menhir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilleu <aguilleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:16:06 by jlepany           #+#    #+#             */
/*   Updated: 2025/11/10 15:59:09 by aguilleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	auto_move(t_struct *cub)
{
	if (cub->key[XK_w])
		player_move(XK_w, cub->data, cub->map, 0.01);
	if (cub->key[XK_s])
		player_move(XK_s, cub->data, cub->map, 0.01);
	if (cub->key[XK_a])
		player_move(XK_a, cub->data, cub->map, 0.01);
	if (cub->key[XK_d])
		player_move(XK_d, cub->data, cub->map, 0.01);
	return (0);
}

int	change_pos(t_engine *data, char **map, double new_x, double new_y)
{
	if (map[(int)(data->p_y)][(int)(new_x)] == '0')
		data->p_x = new_x;
	if (map[(int)(new_y)][(int)(data->p_x)] == '0')
		data->p_y = new_y;
	return (0);
}

int	end_part_two(t_struct *cub)
{
	int	i;

	i = 0;
	if (cub->wall)
	{
		while (i < 4)
		{
			if (cub->wall[i])
			{
				if (cub->wall[i]->wall)
					mlx_destroy_image(cub->mlx, cub->wall[i]->wall);
				free(cub->wall[i]);
				i++;
			}
		}
		free(cub->wall);
	}
	return (0);
}

int	is_new_wall(t_engine *data, int hit_count)
{
	int	res;

	res = hit_count + 1;
	if (res >= 64)
		res = 0;
	if (!data->wall_side)
	{
		if (data->map_x != data->old_hit_x)
			res = 0;
	}
	if (data->wall_side)
	{
		if (data->map_y != data->old_hit_y)
			res = 0;
	}
	data->old_hit_x = data->map_x;
	data->old_hit_y = data->map_y;
	return (res);
}
