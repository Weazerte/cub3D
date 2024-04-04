/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weaz <weaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:52:23 by thenry            #+#    #+#             */
/*   Updated: 2024/02/26 23:46:41 by weaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	i = 0;
	if (ft_strlen(s1) == 0 && ft_strlen(s2) == 0)
		return (0);
	tmp1 = ((unsigned char *)s1);
	tmp2 = ((unsigned char *)s2);
	while (i < n)
	{
		if (tmp1[i] != tmp2[i])
			return (tmp1[i] - tmp2[i]);
		else
			i++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
int main()
{
	char *str = "test\200";
	char *str2 = "test\0";
	printf("%d\n", ft_strncmp(str, str2, 6));
	printf("%d\n", strncmp(str, str2, 6));
	return 0;
}
*/
