/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 02:47:58 by brel-baz          #+#    #+#             */
/*   Updated: 2017/11/03 03:59:37 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_len(char *str, int len)
{
	int i;

	i = 0;
	while ((str[i]) && (i < len))
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putstr_len2(int len, t_env *env)
{
	int i;

	i = 0;
	while (i < len)
	{
		write(1, "0", 1);
		i++;
	}
	env->i += i;
}
