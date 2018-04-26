/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 01:02:02 by brel-baz          #+#    #+#             */
/*   Updated: 2018/04/21 17:17:25 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cast_d(char c, va_list ap, t_id *id)
{
	if (c == 'h')
		id->d = (short)va_arg(ap, int);
	if (c == 'l')
		id->d = va_arg(ap, long);
	if (c == 'j')
		id->d = va_arg(ap, intmax_t);
	if (c == 'z')
		id->d = va_arg(ap, ssize_t);
}

void	ft_cast_oux(char c, va_list ap, t_id *id)
{
	if (c == 'h')
		id->x = (unsigned short)va_arg(ap, int);
	if (c == 'l')
		id->x = va_arg(ap, unsigned long);
	if (c == 'j')
		id->x = va_arg(ap, uintmax_t);
	if (c == 'z')
		id->x = va_arg(ap, size_t);
}

void	ft_cast_dd(char c, char d, va_list ap, t_id *id)
{
	if (c == 'h' && d == 'h')
		id->d = (signed char)va_arg(ap, int);
	if (c == 'l' || d == 'l')
		id->d = va_arg(ap, long long);
}

void	ft_cast_oux2(char c, char d, va_list ap, t_id *id)
{
	if (c == 'h' && d == 'h')
		id->x = (unsigned char)va_arg(ap, int);
	if (c == 'l' || d == 'l')
		id->x = va_arg(ap, unsigned long long);
}

void	ft_cast_uu(char c, va_list ap, t_id *id)
{
	if (c == 'h')
		id->x = va_arg(ap, unsigned long long);
	if (c == 'l')
		id->x = va_arg(ap, unsigned long);
	if (c == 'j')
		id->x = va_arg(ap, uintmax_t);
	if (c == 'z')
		id->x = va_arg(ap, size_t);
}
