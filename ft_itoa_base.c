/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 02:56:41 by brel-baz          #+#    #+#             */
/*   Updated: 2017/11/02 23:23:25 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long		ft_pow(long long nb, long long pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char			*overflow(long long value, long long base)
{
	char		*nbr;

	if (value == -4294967296 && base == 16)
	{
		if (!(nbr = (char*)malloc(sizeof(nbr) * 17)))
			return (NULL);
		nbr = ft_strcpy(nbr, "ffffffff00000000");
		return (nbr);
	}
	if (value == -4294967297 && base == 16)
	{
		if (!(nbr = (char*)malloc(sizeof(nbr) * 17)))
			return (NULL);
		nbr = ft_strcpy(nbr, "fffffffeffffffff");
		return (nbr);
	}
	return (NULL);
}

char			*ft_itoa_base(long long value, long long b, int i)
{
	char		*nbr;
	long long	neg;

	neg = 0;
	if ((value == -4294967296 && b == 16) || (value == -4294967297 && b == 16))
		return (overflow(value, b));
	if (value < 0)
	{
		if (b == 10)
			neg = 1;
		value *= -1;
	}
	while (ft_pow(b, i) - 1 < value)
		i++;
	if (!(nbr = (char*)malloc(sizeof(nbr) * i)))
		return (NULL);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (value % b) + (value % b > 9 ? 'a' - 10 : '0');
		value = value / b;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}
