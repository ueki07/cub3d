/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilleu <aguilleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:39:18 by jlepany           #+#    #+#             */
/*   Updated: 2025/11/10 15:58:57 by aguilleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	around_is_zero(t_struct *garbage, int x, int y)
{
	if (x == 0)
		return (1);
	if (y == 0)
		return (1);
	if (!garbage->map[x][y + 1])
		return (1);
	if (!garbage->map[x + 1])
		return (1);
	if (garbage->map[x + 1][y] || garbage->map[x][y - 1]
		|| garbage->map[x - 1][y] || garbage->map[x][y + 1])
	{
		if (garbage->map[x + 1][y] == '0'
			|| garbage->map[x - 1][y] == '0'
			|| garbage->map[x][y + 1] == '0'
			|| garbage->map[x][y - 1] == '0')
			return (0);
	}
	return (1);
}

int	is_valid_char(t_struct *garbage, char c, int x, int y)
{
	if (c != '0' && c != '1' && c != ' ' && c != 'N'
		&& c != 'S' && c != 'E' && c != 'W' && c != '\n' && c != '\0')
		return (error_detected(NULL, "Wrong chars"));
	if ((c == 'N' || c == 'S' || c == 'E' || c == 'W')
		&& garbage->two_start == 1)
		return (error_detected(NULL, "Two or more starts"));
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		garbage->two_start = 1;
		garbage->p_xy[0] = y;
		garbage->p_xy[1] = x;
		garbage->p_direction = c;
		garbage->map[x][y] = '0';
	}
	return (0);
}

int	around(t_struct *garbage, int x, int y, char c)
{
	if (x == 0)
		return (1);
	if (y == 0)
		return (1);
	if (!garbage->map[x][y + 1])
		return (1);
	if (!garbage->map[x + 1])
		return (1);
	if (garbage->map[x + 1][y] || garbage->map[x][y - 1]
		|| garbage->map[x - 1][y] || garbage->map[x][y + 1])
	{
		if (garbage->map[x + 1][y] == c
			|| garbage->map[x - 1][y] == c
			|| garbage->map[x][y + 1] == c
			|| garbage->map[x][y - 1] == c)
			return (1);
	}
	return (0);
}

int	cant_move(t_struct *garbage, int x, int y)
{
	if (garbage->map[x][y] == 'N' || garbage->map[x][y] == 'S'
		|| garbage->map[x][y] == 'W' || garbage->map[x][y] == 'E')
	{
		if (around(garbage, x, y, ' ') || around(garbage, x, y, '\n'))
			return (error_detected(NULL, "Player stuck"));
		if (around_is_zero(garbage, x, y))
			return (error_detected(NULL, "Player stuck"));
	}
	return (0);
}

int	check_map(t_struct *garbage)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (garbage->map[x])
	{
		while (garbage->map[x][y])
		{
			if (is_valid_char(garbage, garbage->map[x][y], x, y))
				return (1);
			if (garbage->map[x][y] == '0')
				if (around(garbage, x, y, ' ') || around(garbage, x, y, '\n')
					|| around(garbage, x, y, '\t'))
					return (error_detected(NULL, "0 next to empty"));
			if (cant_move(garbage, x, y))
				return (1);
			y++;
		}
		y = 0;
		x++;
	}
	if (garbage->two_start == 0)
		return (error_detected(NULL, "No start"));
	return (0);
}
