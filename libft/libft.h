/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:24 by rmechety          #+#    #+#             */
/*   Updated: 2023/04/28 15:59:05 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* -------------------------------------------------------------------------- */
/*                            FILE = ./ft_memcmp.c                            */
/* -------------------------------------------------------------------------- */
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/* -------------------------------------------------------------------------- */
/*                            FILE = ./ft_memcpy.c                            */
/* -------------------------------------------------------------------------- */
void				*ft_memcpy(void *dest, const void *src, int n);

/* -------------------------------------------------------------------------- */
/*                            FILE = ./ft_calloc.c                            */
/* -------------------------------------------------------------------------- */
void				*ft_calloc(size_t nmemb, size_t size);

/* -------------------------------------------------------------------------- */
/*                          FILE = ./ft_putendl_fd.c                          */
/* -------------------------------------------------------------------------- */
void				ft_putendl_fd(char *s, int fd);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./ft_strnstr.c                            */
/* -------------------------------------------------------------------------- */
char				*ft_strnstr(const char *big, const char *little,
						size_t len);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./ft_isalpha.c                            */
/* -------------------------------------------------------------------------- */
int					ft_isalpha(char c);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./ft_strtrim.c                            */
/* -------------------------------------------------------------------------- */
char				*ft_strtrim(char const *s1, char const *set);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./ft_memmove.c                            */
/* -------------------------------------------------------------------------- */
void				*ft_memmove(void *dest, const void *src, size_t n);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./ft_isalnum.c                            */
/* -------------------------------------------------------------------------- */
int					ft_isalnum(char c);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./ft_isdigit.c                            */
/* -------------------------------------------------------------------------- */
int					ft_isdigit(char c);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./ft_isprint.c                            */
/* -------------------------------------------------------------------------- */
int					ft_isprint(char c);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./ft_tolower.c                            */
/* -------------------------------------------------------------------------- */
int					ft_tolower(int c);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./ft_toupper.c                            */
/* -------------------------------------------------------------------------- */
int					ft_toupper(int c);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./ft_strncmp.c                            */
/* -------------------------------------------------------------------------- */
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/* -------------------------------------------------------------------------- */
/*                            FILE = ./ft_strlen.c                            */
/* -------------------------------------------------------------------------- */
size_t				ft_strlen(const char *str);

/* -------------------------------------------------------------------------- */
/*                          FILE = ./ft_putstr_fd.c                           */
/* -------------------------------------------------------------------------- */
void				ft_putstr_fd(char *s, int fd);

/* -------------------------------------------------------------------------- */
/*                            FILE = ./ft_bzero.c                             */
/* -------------------------------------------------------------------------- */
void				ft_bzero(void *s, int n);

/* -------------------------------------------------------------------------- */
/*                            FILE = ./ft_memset.c                            */
/* -------------------------------------------------------------------------- */
void				*ft_memset(void *s, int c, int n);

/* -------------------------------------------------------------------------- */
/*                            FILE = ./ft_substr.c                            */
/* -------------------------------------------------------------------------- */
char				*ft_substr(char const *s, unsigned int start, size_t len);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./ft_strmapi.c                            */
/* -------------------------------------------------------------------------- */
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* -------------------------------------------------------------------------- */
/*                            FILE = ./ft_strchr.c                            */
/* -------------------------------------------------------------------------- */
char				*ft_strchr(const char *s, int c);

/* -------------------------------------------------------------------------- */
/*                             FILE = ./ft_atoi.c                             */
/* -------------------------------------------------------------------------- */
long long int		ft_atoi(const char *nptr);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./ft_isascii.c                            */
/* -------------------------------------------------------------------------- */
int					ft_isascii(int c);

/* -------------------------------------------------------------------------- */
/*                             FILE = ./ft_itoa.c                             */
/* -------------------------------------------------------------------------- */
char				*ft_calloc_str(size_t size);

char				*ft_itoa(int n);

/* -------------------------------------------------------------------------- */
/*                          FILE = ./ft_putchar_fd.c                          */
/* -------------------------------------------------------------------------- */
void				ft_putchar_fd(char c, int fd);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./ft_strjoin.c                            */
/* -------------------------------------------------------------------------- */
char				*ft_strjoin(char const *s1, char const *s2);

/* -------------------------------------------------------------------------- */
/*                            FILE = ./ft_split.c                             */
/* -------------------------------------------------------------------------- */
char				**ft_split(char const *s, char c);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./ft_strlcat.c                            */
/* -------------------------------------------------------------------------- */
size_t				ft_strlcat(char *dest, const char *src, size_t size);

/* -------------------------------------------------------------------------- */
/*                          FILE = ./ft_putnbr_fd.c                           */
/* -------------------------------------------------------------------------- */
void				ft_putnbr_fd(int nb, int fd);

/* -------------------------------------------------------------------------- */
/*                            FILE = ./ft_memchr.c                            */
/* -------------------------------------------------------------------------- */
void				*ft_memchr(const void *s, int c, size_t n);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./ft_strrchr.c                            */
/* -------------------------------------------------------------------------- */
char				*ft_strrchr(const char *s, int c);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./ft_striteri.c                           */
/* -------------------------------------------------------------------------- */
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/* -------------------------------------------------------------------------- */
/*                            FILE = ./ft_strdup.c                            */
/* -------------------------------------------------------------------------- */
char				*ft_strdup(char *src);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./ft_strlcpy.c                            */
/* -------------------------------------------------------------------------- */
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

#endif