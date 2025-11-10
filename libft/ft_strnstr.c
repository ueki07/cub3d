/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:19:17 by jlepany           #+#    #+#             */
/*   Updated: 2024/11/18 15:48:28 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!little[0])
		return ((char *)big);
	if (!big[0] || !len)
		return (00);
	i = -1;
	while (++i < len && big[i])
	{
		j = 0;
		while ((little[j] == big[i + j]) && ((i + j) < len))
			if (little[j++ + 1] == '\0')
				return ((char *)big + i);
	}
	return (00);
}
