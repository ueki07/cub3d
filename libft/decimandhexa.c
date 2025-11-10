/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimandhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.f>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:41:44 by jlepany           #+#    #+#             */
/*   Updated: 2024/12/22 18:19:56 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbrbase(long d, char *base, int r)
{
	if (d < 0)
	{
		d = -d;
		write(1, "-", 1);
		r = 1;
	}
	if (d < 16)
	{
		ft_putchar_fd(base[d], 1);
		r++;
	}
	if (d >= 16)
	{
		r = ft_putnbrbase(d / 16, base, r);
		r = ft_putnbrbase(d % 16, base, r);
	}
	return (r);
}

int	printnumberhexa(va_list *ap, char c1)
{
	long	d;
	int		r;

	d = (long)va_arg(*ap, unsigned int);
	if (c1 == 'x')
		r = ft_putnbrbase(d, "0123456789abcdef", 0);
	if (c1 == 'X')
		r = ft_putnbrbase(d, "0123456789ABCDEF", 0);
	return (r);
}
