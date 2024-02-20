/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:11:30 by eaubry            #+#    #+#             */
/*   Updated: 2022/12/12 16:22:37 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long long nbr)
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

void	ft_put_ptr(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		ft_put_ptr(nbr / 16);
		ft_put_ptr(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar((nbr + '0'));
		else
			ft_putchar((nbr - 10 + 'a'));
	}
}

int	ft_print_ptr(unsigned long long nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	count += ft_putstr("0x");
	ft_put_ptr(nbr);
	count += ft_ptr_len(nbr);
	return (count);
}
