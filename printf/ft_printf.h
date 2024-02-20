/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:15:47 by eaubry            #+#    #+#             */
/*   Updated: 2022/12/12 16:21:52 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);

int	ft_display(va_list parameterinfos, char c);

int	ft_print_hexa(unsigned int nbr, const char c);

int	ft_print_unsigned(unsigned int nb);

int	ft_print_ptr(unsigned long long nbr);

int	ft_putchar(char c);

int	ft_putstr(char *s);

int	ft_putnbr(int nb);

#endif