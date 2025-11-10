/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:55:59 by jlepany           #+#    #+#             */
/*   Updated: 2024/11/12 15:10:09 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*bs;
	unsigned char	bc;
	size_t			i;

	i = -1;
	bs = (unsigned char *)s;
	bc = (unsigned char)c;
	while (++i < n)
		if (bs[i] == bc)
			return (bs + i);
	return (00);
}
