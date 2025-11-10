/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:48:12 by jlepany           #+#    #+#             */
/*   Updated: 2024/11/12 12:53:12 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = 0;
	while (src[len])
		len++;
	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (src[j] && i + 1 < siz)
		dst[i++] = src[j++];
	dst[i] = '\0';
	if (siz < i - j)
		return (len + siz);
	else
		return (len + i - j);
}
