/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilleu <aguilleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:39:23 by jlepany           #+#    #+#             */
/*   Updated: 2025/11/10 15:59:14 by aguilleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_top_and_bot(double wall_dist, int *top, int *bot)
{
	int	wall_height;

	wall_height = (int)(HEIGHT / wall_dist);
	*top = wall_height / 2 + HEIGHT / 2;
	*bot = (-wall_height) / 2 + HEIGHT / 2;
}

char	wall_side_hit(t_engine *data, int wall_side)
{
	if (wall_side)
	{
		if (data->p_y < data->map_y)
			return ('N');
		else
			return ('S');
	}
	else
	{
		if (data->p_x < data->map_x)
			return ('W');
		else
			return ('E');
	}
}

t_wall	*get_texture_addr(t_struct *cub, char wall_or)
{
	t_wall	*tmp;

	tmp = 0;
	if (wall_or == 'N')
		tmp = cub->wall[0];
	if (wall_or == 'E')
		tmp = cub->wall[3];
	if (wall_or == 'W')
		tmp = cub->wall[1];
	if (wall_or == 'S')
		tmp = cub->wall[2];
	tmp->addr = mlx_get_data_addr(tmp->wall, &tmp->bpp,
			&tmp->len, &tmp->endian);
	return (tmp);
}

int	wall_pixel(int bot, int top, int i, t_engine *data)
{
	double	wall_x;
	int		text_x;
	double	step_y;
	int		text_y;

	if (data->wall_side)
		wall_x = data->p_x + data->wall_dist * data->ray_dir_x;
	else
		wall_x = data->p_y + data->wall_dist * data->ray_dir_y;
	if (wall_x == ceil(wall_x))
		wall_x -= ceil(wall_x);
	else
		wall_x -= ceil(wall_x) - 1;
	text_x = (int)(wall_x * 64.0);
	if ((data->wall_side && data->ray_dir_y < 0)
		|| (!data->wall_side && data->ray_dir_x > 0))
		text_x = 64 - text_x - 1;
	step_y = 64.0 / (double)(top - bot) *(i - bot);
	text_y = 64 - (int)(step_y) - 1;
	return (text_x * 4 + text_y * data->wall_txt->len);
}

int	print_wall_part(t_struct *cub, double wall_dist, int pixel_raw, t_wall *txt)
{
	int	top;
	int	bot;
	int	i;
	int	index;
	int	txt_i;

	cub->data->wall_dist = wall_dist;
	calculate_top_and_bot(wall_dist, &top, &bot);
	i = 0;
	while (i < HEIGHT)
	{
		index = cub->img->len * (HEIGHT - i) + pixel_raw * 4;
		if (i < bot)
			*(int *)(cub->img->addr + index) = cub->colors[1];
		else if (i < top)
		{
			txt_i = wall_pixel(bot, top, i, cub->data);
			*(int *)(cub->img->addr + index) = *(int *)(txt->addr + txt_i);
		}
		else
			*(int *)(cub->img->addr + index) = cub->colors[0];
		i++;
	}
	return (0);
}
