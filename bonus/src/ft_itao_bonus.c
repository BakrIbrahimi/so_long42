/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itao.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bibrahim <bibrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:47:33 by bibrahim          #+#    #+#             */
/*   Updated: 2022/03/17 19:47:36 by bibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_intlen(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = (n / 10);
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*ml;
	long	c;
	int		ifneg;

	c = n;
	ifneg = 0;
	i = ft_intlen(c);
	ml = malloc(i + 1);
	if (ml == 0)
		return (0);
	ml[i] = '\0';
	if (c < 0)
	{
		c = c * -1;
		ml[0] = '-';
		ifneg = 1;
	}
	while (i > ifneg)
	{
		i--;
		ml[i] = (c % 10) + 48;
		c = (c / 10);
	}
	return (ml);
}
