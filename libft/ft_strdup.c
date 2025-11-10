/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.f>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:50:17 by jlepany           #+#    #+#             */
/*   Updated: 2024/12/21 18:19:33 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = -1;
	while (s[++i])
		;
	dup = (char *)ft_calloc((i + 1), sizeof(char));
	if (!dup)
		return (00);
	i = -1;
	while (s[++i])
		dup[i] = s[i];
	return (dup);
}
