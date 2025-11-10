/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilleu <aguilleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:43:34 by aguilleu          #+#    #+#             */
/*   Updated: 2025/11/10 15:59:00 by aguilleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	need_skip(char c)
{
	if (c == '\n' || c == 'S' || c == 'N' || c == 'E'
		|| c == 'C' || c == 'F' || c == 'W')
		return (0);
	return (1);
}

int	save_map(t_struct *garbage, char **map, char *argv)
{
	char	*str;
	int		i;

	i = 0;
	garbage->fd_map = open(argv, O_RDONLY, 0666);
	if (garbage->fd_map < 0)
		return (1);
	str = get_next_line(garbage->fd_map);
	while (str && need_skip(str[0]) == 0)
	{		
		free(str);
		str = get_next_line(garbage->fd_map);
	}
	while (str)
	{
		if (ft_strlen(str) > garbage->map_len_x)
			garbage->map_len_x = ft_strlen(str);
		map[i] = ft_calloc(ft_strlen(str) + 1, sizeof(char));
		if (!map[i])
			return (free(str), free_split(map), 1);
		ft_strcpy(map[i++], str);
		free(str);
		str = get_next_line(garbage->fd_map);
	}
	return (0);
}

int	all_map(t_struct *garbage, char *str)
{
	int	i;

	i = 0;
	while (str)
	{
		free(str);
		str = get_next_line(garbage->fd_map);
		i++;
	}
	return (i);
}

int	nb_lines_gnl(t_struct *garbage)
{
	char	*str;
	int		i;

	i = 0;
	str = get_next_line(garbage->fd_map);
	if (!str)
		return (error_detected(0, "Mem erorr"));
	while (str[0] == '\n')
	{
		free(str);
		str = get_next_line(garbage->fd_map);
		if (!str)
			break ;
	}
	while (str[i] && str[i] != '1')
		i++;
	if (str && str[i] != '1')
		return (error_detected(str, "Wrong map"));
	i = all_map(garbage, str);
	return (close(garbage->fd_map), i);
}

int	handle_map(t_struct *garbage, char *argv)
{
	int	nb;

	nb = nb_lines_gnl(garbage);
	if (nb < 0)
		return (1);
	garbage->map_len_y = nb;
	garbage->map = ft_calloc((nb + 1), sizeof(char *));
	if (!garbage->map)
		return (1);
	if (save_map(garbage, garbage->map, argv))
		return (1);
	return (0);
}
