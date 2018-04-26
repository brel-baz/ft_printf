/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 00:41:47 by brel-baz          #+#    #+#             */
/*   Updated: 2017/11/08 04:03:16 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long		ft_pow2(unsigned long long nb, unsigned long long pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow2(nb, pow - 1));
}

char					*ft_ub(unsigned long long value, unsigned long long b)
{
	char				*nbr;
	unsigned long long	i;
	unsigned long long	neg;

	i = 1;
	neg = 0;
	while (ft_pow2(b, i) - 1 < value)
		i++;
	if (!(nbr = (char*)malloc(sizeof(nbr) * i)))
		return (NULL);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (value % b) + (value % b > 9 ? 'a' - 10 : '0');
		value = value / b;
	}
	(neg ? nbr[0] = '-' : 0);
	if (nbr[0] == '0' && ft_strcmp(nbr, "0") != 0)
	{
		i = 0;
		while (nbr[i] == '0')
			i++;
		return (ft_strsub(nbr, i, ft_strlen(nbr) - i));
	}
	return (nbr);
}
