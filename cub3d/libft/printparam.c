/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printparam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.f>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:56:21 by jlepany           #+#    #+#             */
/*   Updated: 2024/12/16 23:26:39 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printchar(va_list *ap)
{
	int	c;

	c = va_arg(*ap, int);
	write(1, &c, 1);
	return (1);
}

int	printstr(va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (str)
	{
		ft_putstr_fd(str, 1);
		return ((int)ft_strlen(str));
	}
	else
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
}

int	printpointer(va_list *ap)
{
	void			*p;
	unsigned long	*i;
	int				r;

	p = (void *)va_arg(*ap, void *);
	if (!p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	i = (unsigned long *)&p;
	r = 2;
	ft_putstr_fd("0x", 1);
	r += ft_putnbrbase((*i), "0123456789abcdef", 0);
	return (r);
}

int	ft_printlong(long u, int r)
{
	if (u < 0)
	{
		u = -u;
		write(1, "-", 1);
		r = 1;
	}
	if (u < 10)
	{
		ft_putchar_fd(u + '0', 1);
		r++;
	}
	if (u >= 10)
	{
		r = ft_printlong(u / 10, r);
		r = ft_printlong(u % 10, r);
	}
	return (r);
}

int	printnbr(va_list *ap, char c1)
{
	long	u;
	int		r;

	if (c1 == 'd')
		u = (long)va_arg(*ap, int);
	if (c1 == 'i')
		u = (long)va_arg(*ap, int);
	if (c1 == 'u')
		u = (long)va_arg(*ap, unsigned int);
	r = ft_printlong(u, 0);
	return (r);
}
