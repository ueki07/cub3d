/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:16:14 by jlepany           #+#    #+#             */
/*   Updated: 2024/11/18 16:11:28 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	startpoint(char const *s, char c);

static char	**freestar(char **star, int row)
{
	int	i;

	i = -1;
	while (i++ < row)
		if (star[i])
			free(star[i]);
	if (star)
		free(star);
	return (00);
}

static int	count_size(char const *s, char c)
{
	int	i;
	int	k;

	i = startpoint(s, c);
	k = 0;
	if (!s[0])
		return (1);
	while (s[++i])
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			k++;
	return (k + 2);
}

static char	*create_line(char const *s, char c, int k)
{
	int		i;
	int		j;
	char	*res;

	i = k - 1;
	while (s[++i] != c && s[i])
		;
	res = (char *)malloc((i - k + 1) * sizeof(char));
	if (!res)
		return (00);
	j = 0;
	while (k < i && s[k] != c)
	{
		res[j] = s[k];
		j++;
		k++;
	}
	res[j] = '\0';
	return (res);
}

static int	startpoint(char const *s, char c)
{
	int	i;

	i = -1;
	while (s[++i] == c)
		;
	return (i - 1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		k;
	int		j;

	res = (char **)malloc((count_size(s, c)) * sizeof(char *));
	if (!res)
		return (00);
	i = startpoint(s, c);
	k = i + 1;
	j = -1;
	while (s[++i] && s[0])
	{
		if ((s[i] == c && s[i + 1] != c) || !s[i + 1])
		{
			res[++j] = create_line(s, c, k);
			if (!res[j])
				return (freestar(res, j - 1));
			k = i + 1;
		}
	}
	res[j + 1] = 00;
	return (res);
}
