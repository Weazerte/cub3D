/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:59:14 by eaubry            #+#    #+#             */
/*   Updated: 2022/12/12 16:21:11 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_len(unsigned int nbr)
{
	int	count;

	count = 0;
	while (nbr != 0)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

char	*ft_itoa_unsigned(unsigned int nbr)
{
	int		len;
	char	*str;

	len = ft_unsigned_len(nbr);
	str = malloc (sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = 0;
	while (nbr != 0)
	{
		str[len - 1] = nbr % 10 + 48;
		nbr /= 10;
		len--;
	}
	return (str);
}

int	ft_print_unsigned(unsigned int nbr)
{
	int		count;
	char	*str;

	count = 0;
	if (nbr == 0)
		count += ft_putchar('0');
	else
	{
		str = ft_itoa_unsigned(nbr);
		count += ft_putstr(str);
		free(str);
	}
	return (count);
}
