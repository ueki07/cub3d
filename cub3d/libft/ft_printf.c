/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.f>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:44:40 by jlepany           #+#    #+#             */
/*   Updated: 2024/12/15 12:50:45 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printparam(char c1, va_list *ap)
{
	if (c1 == '%')
		write(1, &c1, 1);
	if (c1 == 'c')
		return (printchar(ap));
	if (c1 == 's')
		return (printstr(ap));
	if (c1 == 'p')
		return (printpointer(ap));
	if (c1 == 'd' || c1 == 'i' || c1 == 'u')
		return (printnbr(ap, c1));
	if (c1 == 'x' || c1 == 'X')
		return (printnumberhexa(ap, c1));
	return (1);
}

int	ft_printf(const char *a1, ...)
{
	va_list		ap;
	const char	*str;
	int			i;
	int			j;

	va_start(ap, a1);
	str = a1;
	if (!str)
		return (-1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i++] == '%')
			j += printparam(str[i++], &ap);
		else
		{
			write(1, &str[i - 1], 1);
			j++;
		}
	}
	va_end(ap);
	return (j);
}
/*
int	main(void)
{
	char	*s;

	s = "bonjour";
	ft_printf("bonjour\n");
	printf("bonjour\n");
	ft_printf("%s\n%s\n", s, "coucou");
	printf("%s\n%s\n", s, "coucou");
}*/
