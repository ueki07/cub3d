/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilleu <aguilleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:40:38 by jlepany           #+#    #+#             */
/*   Updated: 2025/06/25 19:48:08 by aguilleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	i = 0;
	dest = str;
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tmp;
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (!s1 && !s2)
		return (NULL);
	tmp = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tmp)
		return (NULL);
	while (s1[a])
	{
		tmp[a] = s1[a];
		a++;
	}
	while (s2[i])
	{
		tmp[a] = s2[i];
		a++;
		i++;
	}
	tmp[a] = '\0';
	free(s1);
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0' && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

// char	*last_line(char *res, char *temp)
// {
// 	free(temp);
// 	return (res);
// }
