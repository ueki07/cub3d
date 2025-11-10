/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilleu <aguilleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:39:54 by jlepany           #+#    #+#             */
/*   Updated: 2025/11/10 15:57:51 by aguilleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	drop_the_garbage(t_struct *garbage)
{	
	int	i;

	i = 0;
	if (garbage->img_name)
	{
		while (i < 4)
		{
			if (garbage->img_name[i])
				free(garbage->img_name[i]);
			i++;
		}
	}
	if (garbage->img_name)
		free(garbage->img_name);
	if (garbage->map)
		free_split(garbage->map);
	if (garbage->fd_map)
		close(garbage->fd_map);
	free(garbage);
	return (1);
}

int	whole_checking(t_struct *garbage, char **argv)
{
	garbage->img_name = ft_calloc(4, sizeof(char *));
	if (!garbage->img_name)
		return (1);
	if (parsing_param(garbage->fd_map, garbage->img_name, garbage->colors))
		return (1);
	if (handle_map(garbage, argv[1]))
		return (1);
	if (check_map(garbage))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_struct	*garbage;

	if (argc != 2)
		return (write(2, "Wrong number of arguments\n", 26));
	garbage = ft_calloc(1, sizeof(t_struct));
	if (!garbage)
		return (1);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 5))
		return (drop_the_garbage(garbage), write(2, "Wrong extension\n", 16));
	garbage->fd_map = open(argv[1], O_RDONLY, 0666);
	if (garbage->fd_map <= -1)
		return (drop_the_garbage(garbage), write(2, "Non existent file\n", 18));
	if (whole_checking(garbage, argv))
		return (drop_the_garbage(garbage));
	if (mlx_start(garbage))
		drop_the_garbage(garbage);
	drop_the_garbage(garbage);
	printf("OK\n");
	return (0);
}
