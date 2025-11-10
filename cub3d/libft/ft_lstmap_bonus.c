/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:19:09 by jlepany           #+#    #+#             */
/*   Updated: 2024/11/27 12:28:19 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*truebegin;
	t_list	*begin;

	if (!lst)
		return (ft_lstnew(00));
	begin = ft_lstnew((*f)(lst->content));
	if (!begin)
	{
		ft_lstdelone(begin, del);
		return (00);
	}
	truebegin = begin;
	lst = lst->next;
	while (lst)
	{
		begin->next = ft_lstnew((*f)(lst->content));
		if (!begin)
		{
			ft_lstclear(&truebegin, del);
			return (00);
		}
		begin = begin->next;
		lst = lst->next;
	}
	return (truebegin);
}
/*

void	*ft_toupup(void *str)
{
	char 	*bstr;
	int	i;
	char	*res;

	i = -1;
	bstr = (char *)str;
	res = malloc(ft_strlen(bstr) * sizeof(char));
	while (bstr[++i])
		if (bstr[i] >= 'a' && bstr[i] <= 'z')
			res[i] = bstr[i] - 32;
	return (res);
}

void	jbdel(void *s)
{
	int	i;

	i = -1;
	while(((char *)s)[++i])
		((char *)s)[i] = '\0';
}

int	main(void)
{
	t_list	*res;
	t_list	*l1=ft_lstnew("numberone");
	t_list	*l2=ft_lstnew("numbertwo");
	t_list	*l3=ft_lstnew("numberthree");
	t_list	*l4=ft_lstnew("numberfour");

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	res = ft_lstmap(l1, ft_toupup, jbdel);
	while(res->next)
	{
		printf("%s\n", (char *)res->content);
		res = res->next;
	}
	printf("%s\n", (char *)res->content);
}*/
