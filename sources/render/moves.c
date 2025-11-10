/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilleu <aguilleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:42:18 by jlepany           #+#    #+#             */
/*   Updated: 2025/11/10 15:59:12 by aguilleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	player_move(int keys, t_engine *data, char **map, double move_speed)
{
	double	new_x;
	double	new_y;

	if (keys == XK_w)
	{
		new_x = data->p_x + data->p_dir_x * move_speed;
		new_y = data->p_y + data->p_dir_y * move_speed;
	}
	if (keys == XK_s)
	{
		new_x = data->p_x - data->p_dir_x * move_speed;
		new_y = data->p_y - data->p_dir_y * move_speed;
	}
	if (keys == XK_a)
	{
		new_x = data->p_x + data->p_dir_y * move_speed;
		new_y = data->p_y - data->p_dir_x * move_speed;
	}
	if (keys == XK_d)
	{
		new_x = data->p_x - data->p_dir_y * move_speed;
		new_y = data->p_y + data->p_dir_x * move_speed;
	}
	change_pos(data, map, new_x, new_y);
	return (0);
}

int	camera_left(t_engine *data)
{
	double	olddir;
	double	old_c_x;

	olddir = data->p_dir_x;
	data->p_dir_x = data->p_dir_x * cos(0.785398163)
		- data->p_dir_y * sin(0.785398163);
	data->p_dir_y = olddir * sin(0.785398163)
		+ data->p_dir_y * cos(0.785398163);
	old_c_x = data->c_plane_x;
	data->c_plane_x = data->c_plane_x * cos(0.785398163)
		- data->c_plane_y * sin(0.785398163);
	data->c_plane_y = old_c_x * sin(0.785398163)
		+ data->c_plane_y * cos(0.785398163);
	return (0);
}

int	camera_right(t_engine *data)
{
	double	olddir;
	double	old_c_x;

	olddir = data->p_dir_x;
	data->p_dir_x = data->p_dir_x * cos(-0.785398163)
		- data->p_dir_y * sin(-0.785398163);
	data->p_dir_y = olddir * sin(-0.785398163)
		+ data->p_dir_y * cos(-0.785398163);
	old_c_x = data->c_plane_x;
	data->c_plane_x = data->c_plane_x * cos(-0.785398163)
		- data->c_plane_y * sin(-0.785398163);
	data->c_plane_y = old_c_x * sin(-0.785398163)
		+ data->c_plane_y * cos(-0.785398163);
	return (0);
}

int	handle_key_release(int keys, t_struct *cub)
{
	if (keys == XK_w)
		cub->key[XK_w] = 0;
	if (keys == XK_d)
		cub->key[XK_d] = 0;
	if (keys == XK_s)
		cub->key[XK_s] = 0;
	if (keys == XK_a)
		cub->key[XK_a] = 0;
	return (0);
}

int	handle_keys(int keys, t_struct *cub)
{
	if (keys == XK_Escape)
		end(cub, 0);
	if (keys == XK_w)
		cub->key[XK_w] = 1;
	if (keys == XK_d)
		cub->key[XK_d] = 1;
	if (keys == XK_a)
		cub->key[XK_a] = 1;
	if (keys == XK_s)
		cub->key[XK_s] = 1;
	if (keys == 65361)
		camera_right(cub->data);
	if (keys == 65363)
		camera_left(cub->data);
	return (0);
}
