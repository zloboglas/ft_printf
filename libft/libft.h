/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:12:53 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/17 08:37:37 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef NULL
#  define NULL ((void*)0)
# endif

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

int					ft_putchars(int size, char char2put);
char				*ft_itoa_base_unsigned(unsigned long long num, int base);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
int					ft_atoi(const char *str);
char				*ft_strdup(const char *src);
size_t				ft_strlen(const char *str);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_putstr(const char *c);
char				*ft_strnew(size_t size);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnstr(const char *strb, const char *stra, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strstr(const char *strb, const char *stra);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
char				*ft_strncat(char *dest, const char *apnd, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strrchr(const char *str, int c);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				*ft_memset(void *dest, int c, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strcmp(const char *str1, const char *str2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_putnbr(unsigned long long n);
void				ft_putchar(char c);
void				ft_putstr(const char *c);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(const char *s);
void				ft_putchar_fd(char c, int fd);
char				*ft_strchr(const char *str, int s);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_strcat(char *dest, const char *append);
void				ft_memdel(void **ap);
void				ft_bzero(void *dest, size_t n);
void				*ft_memalloc(size_t size);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memchr(const void *buf, int ch, size_t count);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);
int					ft_count(const char *s, char c);
char				*ft_strtrim(const char *s);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
int					ft_memcmp(const void *b1, const void *b2, size_t count);

char				*ft_itoa_base(int num, int base);
char				*ft_itoa_pointer(void *p);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_herobora
{
	char			*buff2;
	char			*str;
	long			shift;
	long			tmp;
	int				flag;
	char			*to_free;
}					t_herobora;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				*ft_memmove(void *dest, const void *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_fact(int n);
void				*ft_realloc(void *str, size_t s);
int					ft_sqrt(int nb);
void				ft_swap(int *a, int *b);

#endif
