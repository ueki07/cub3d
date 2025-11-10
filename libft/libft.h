/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilleu <aguilleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:08:43 by jlepany           #+#    #+#             */
/*   Updated: 2025/07/28 11:30:05 by jlepany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;
int		ft_atoi(const char *nptr, int *i);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t	ft_strlcat(char *dst, const char *src, size_t siz);
size_t	ft_strlcpy(char *dst, const char *src, size_t siz);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *l_new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *l_new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_printf(const char *a, ...);
int		printparam(char c1, va_list *ap);
int		printchar(va_list *ap);
int		printstr(va_list *ap);
int		printpointer(va_list *ap);
int		printnumberhexa(va_list *ap, char c1);
int		printnbr(va_list *ap, char c1);
int		ft_printlong(long u, int r);
int		ft_putnbrbase(long d, char *base, int r);
char	*get_next_line(int fd);
char	*actual_line(char *buffer);
char	*next_line(char *buffer);
char	*bytes_read(int fd, char *buffer, char *line);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *str, size_t n);

#endif
