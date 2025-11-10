/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilleu <aguilleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:36:17 by jlepany           #+#    #+#             */
/*   Updated: 2025/11/10 15:58:21 by aguilleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	to_decimal(int colors[3], int binary)
{
	colors[0] = (binary & 0x00ff0000) >> 16;
	colors[1] = (binary & 0x0000ff00) >> 8;
	colors[2] = (binary & 0x000000ff);
	return (0);
}

int	to_binary(int rgb[3])
{
	int	res;

	res = 0;
	res = rgb[0];
	res = res << 8;
	res += rgb[1];
	res = res << 8;
	res += rgb[2];
	return (res);
}

int	check_color_binary(char *str)
{
	int	rgb[3];
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		rgb[j] = ft_atoi(str, &i);
		if (rgb[j] < 0 || rgb[j] > 255)
			return (write(2, "Wrong colors\n", 13), -1);
		if (str[i] && j != 2)
		{
			if (str[i++] != ',')
				return ((write(2, "Wrong colors\n", 13), -1));
		}
		else if (j == 2 && str[++i])
			return ((write(2, "Wrong colors\n", 13), -1));
		j++;
	}
	return (to_binary(rgb));
}
