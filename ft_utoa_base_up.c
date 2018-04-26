/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 00:44:05 by brel-baz          #+#    #+#             */
/*   Updated: 2017/11/02 23:24:20 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long		ft_pow3(unsigned long long nb, unsigned long long pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char					*ft_ubu(unsigned long long value, unsigned long long b)
{
	char				*nbr;
	unsigned long long	i;
	unsigned long long	neg;

	i = 1;
	neg = 0;
	while (ft_pow3(b, i) - 1 < value)
		i++;
	if (!(nbr = (char*)malloc(sizeof(nbr) * i)))
		return (NULL);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (value % b) + (value % b > 9 ? 'A' - 10 : '0');
		value = value / b;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}
