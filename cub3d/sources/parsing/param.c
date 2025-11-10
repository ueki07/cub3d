/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilleu <aguilleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:23:58 by jlepany           #+#    #+#             */
/*   Updated: 2025/11/10 15:59:03 by aguilleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_char_color(char *str, int colors[2])
{
	int	i;
	int	a;
	int	res;

	res = 0;
	a = 0;
	i = 1;
	while (str[i] == ' ')
		i++;
	if (str[0] == 'F')
		a = 0;
	else if (str[0] == 'C')
		a = 1;
	res = check_color_binary(&str[i]);
	if (res == -1)
	{
		free(str);
		return (1);
	}
	colors[a] = res;
	free(str);
	return (0);
}

int	check_first_letter(char *str)
{
	if (str[0] && str[1])
	{
		if (str[0] == 'N' || str[0] == 'S')
			if (str[1] != 'O')
				return (error_detected(str, "Wrong map1"));
		if (str[0] == 'W')
			if (str[1] != 'E')
				return (error_detected(str, "Wrong map2"));
		if (str[0] == 'E')
			if (str[1] != 'A')
				return (error_detected(str, "Wrong map3"));
	}
	else
		return (error_detected(str, "Wrong map4"));
	return (0);
}

int	check_char_text(char *str, char **img_name)
{
	int	i;
	int	a;

	i = 2;
	a = 0;
	if (check_first_letter(str))
		return (1);
	str[ft_strlen(str) - 1] = 0;
	while (str[i] == ' ')
		i++;
	if (str[0] == 'N')
		a = 0;
	else if (str[0] == 'S')
		a = 1;
	else if (str[0] == 'W')
		a = 2;
	else if (str[0] == 'E')
		a = 3;
	img_name[a] = ft_strdup(&str[i]);
	free(str);
	if (!img_name[a])
		return (error_detected(0, "Memory allocation failure"));
	return (0);
}

int	check_all(char *str, int fd, char *img_name[4], int colors[2])
{
	while (str)
	{
		while (str[0] == '\n')
		{
			free(str);
			str = get_next_line(fd);
		}
		if (str[0] == 'N' || str[0] == 'S' || str[0] == 'W' || str[0] == 'E')
		{
			if (check_char_text(str, img_name))
				return (1);
		}
		else if (str[0] == 'F' || str[0] == 'C')
		{
			if (check_char_color(str, colors))
				return (1);
		}
		else
			return (error_detected(str, "Wrong map10"));
		if (img_name[0] && img_name[1] && img_name[2] && img_name[3]
			&& colors[0] != 0 && colors[1] != 0)
			break ;
		str = get_next_line(fd);
	}
	return (0);
}

int	parsing_param(int fd, char *img_name[4], int colors[2])
{
	char	*str;

	str = get_next_line(fd);
	if (!str)
		return (write(2, "Wrong map\n", 10), -1);
	if (check_all(str, fd, img_name, colors))
		return (1);
	else
		return (0);
}
