/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:50:24 by jlepany           #+#    #+#             */
/*   Updated: 2024/11/12 14:55:24 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*bs1;
	unsigned char	*bs2;

	i = 0;
	bs1 = (unsigned char *)s1;
	bs2 = (unsigned char *)s2;
	while (i < n)
	{
		if (bs1[i] != bs2[i] || !bs1[i] || !bs2[i])
			return (bs1[i] - bs2[i]);
		i++;
	}
	return (0);
}
