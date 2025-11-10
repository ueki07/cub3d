/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.f>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:13:30 by jlepany           #+#    #+#             */
/*   Updated: 2024/12/06 19:01:03 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	char	*bres;
	size_t	i;

	if (nmemb * size > 2147483647)
		return (00);
	res = (malloc(nmemb * size));
	if (!res)
		return (00);
	if (nmemb == 0 || size == 0)
		return (res);
	bres = (char *)res;
	i = -1;
	while (++i < nmemb * size)
		bres[i] = '\0';
	return (res);
}
/*

int	main(void)
{
	int	*s;

	s = ft_calloc(0, 2);
	free(s);
}*/
