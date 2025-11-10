/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:36:49 by jlepany           #+#    #+#             */
/*   Updated: 2024/11/18 12:16:23 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*bdest;
	char			*bsrc;

	if (dest == src)
		return (00);
	i = -1;
	bdest = (char *)dest;
	bsrc = (char *)src;
	while (++i < n)
		bdest[i] = bsrc[i];
	return (dest);
}
