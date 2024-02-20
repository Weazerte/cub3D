/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:10:59 by eaubry            #+#    #+#             */
/*   Updated: 2024/02/20 17:59:07 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

int	main(int ac, char **av)
{
	t_tibs tibs;

	if (ac == 2)
	{
		if (ft_pars(&tibs, av) == 1)
		{
			ft_free_pars(&tibs, NULL, NULL);
			return (1);
		}
		ft_printf("map valide\n");
		ft_free_tibs(&tibs);
	}
	return (0);
}

//error avec : ligne vide dans map / manque virgule rgb / parser correctement les path text