/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:49:33 by jlepany           #+#    #+#             */
/*   Updated: 2024/11/13 14:06:42 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	i = -1;
	while (s[++i])
		;
	res = (char *)malloc((i + 1) * sizeof(char));
	if (!res)
		return (00);
	i = -1;
	while (s[++i])
		res[i] = f((unsigned int)i, s[i]);
	res[i] = '\0';
	return (res);
}
