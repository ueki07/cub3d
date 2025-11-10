/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilleu <aguilleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:07:56 by aguilleu          #+#    #+#             */
/*   Updated: 2025/11/10 15:57:54 by aguilleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_detected(char *str, char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(2, &s[i++], 1);
	write(2, "\n", 1);
	if (str)
		free(str);
	return (-1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	free_split(char **tot)
{
	int	i;

	i = 0;
	if (!tot)
		return ;
	while (tot[i])
	{
		free(tot[i]);
		i++;
	}
	if (tot)
		free(tot);
}
