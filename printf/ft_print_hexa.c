/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:13:51 by eaubry            #+#    #+#             */
/*   Updated: 2022/12/12 16:17:35 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_len(unsigned int nbr)
{
	int	count;

	count = 0;
	while (nbr != 0)
	{
		count++;
		nbr /= 16;
	}
	return (count);
}

void	ft_put_hexa(unsigned int nbr, const char c)
{
	if (nbr >= 16)
	{
		ft_put_hexa(nbr / 16, c);
		ft_put_hexa(nbr % 16, c);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar((nbr + '0'));
		else
		{
			if (c == 'x')
				ft_putchar((nbr - 10 + 'a'));
			if (c == 'X')
				ft_putchar((nbr - 10 + 'A'));
		}
	}
}

int	ft_print_hexa(unsigned int nbr, const char c)
{
	if (nbr == 0)
		return (ft_putchar('0'));
	else
		ft_put_hexa(nbr, c);
	return (ft_hexa_len(nbr));
}
