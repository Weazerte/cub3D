/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:14:38 by eaubry            #+#    #+#             */
/*   Updated: 2022/12/13 17:17:39 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		res;
	va_list	parametersinfos;

	va_start(parametersinfos, str);
	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			res += ft_putchar(str[i]);
			i++;
			continue ;
		}
		i++;
		res += ft_display(parametersinfos, str[i]);
		i++;
	}
	va_end(parametersinfos);
	return (res);
}
