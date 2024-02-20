/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:30:33 by eaubry            #+#    #+#             */
/*   Updated: 2022/12/12 16:17:24 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display(va_list parameterinfos, const char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(parameterinfos, int));
	else if (c == '%')
		count += ft_putchar('%');
	else if (c == 's')
		count += ft_putstr(va_arg(parameterinfos, void *));
	else if (c == 'd')
		count += ft_putnbr(va_arg(parameterinfos, int));
	else if (c == 'i')
		count += ft_putnbr(va_arg(parameterinfos, int));
	else if (c == 'u')
		count += ft_print_unsigned(va_arg(parameterinfos, unsigned int));
	else if (c == 'p')
		count += ft_print_ptr(va_arg(parameterinfos, unsigned long long));
	else if (c == 'x' || c == 'X')
		count += ft_print_hexa(va_arg(parameterinfos, unsigned int), c);
	return (count);
}
