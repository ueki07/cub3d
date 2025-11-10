/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:10:48 by jlepany           #+#    #+#             */
/*   Updated: 2024/11/12 15:18:53 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*bs1;
	unsigned char	*bs2;
	size_t			i;

	i = -1;
	bs1 = (unsigned char *)s1;
	bs2 = (unsigned char *)s2;
	while (++i < n)
		if (bs1[i] != bs2[i])
			return (bs1[i] - bs2[i]);
	return (0);
}
