/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:14:29 by jlepany           #+#    #+#             */
/*   Updated: 2024/11/13 17:03:17 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	unity(long n)
{
	if (n < 0)
		n = -n;
	if (n < 10)
		return (1);
	else
		return (1 + unity(n / 10));
}

static int	neg_pos(long n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	l;
	int		i;
	int		j;

	l = (long)n;
	j = unity(l) + neg_pos(l);
	res = (char *)malloc((j + 1) * sizeof(char));
	if (!res)
		return (00);
	res[j] = '\0';
	i = -1;
	if (neg_pos(l))
	{
		res[++i] = '-';
		l = -l;
	}
	while (--j > i)
	{
		res[j] = l % 10 + '0';
		l = l / 10;
	}
	return (res);
}
