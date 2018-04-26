/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_less.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 01:10:58 by brel-baz          #+#    #+#             */
/*   Updated: 2018/04/24 16:45:50 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_less(char c, va_list ap, t_env *env, t_id *id)
{
	if (env->flag != '-')
		return ;
	if (c == '%')
		less_modulo(env);
	if (c == 'c')
		less_c(ap, env, id);
	if (c == 's')
	{
		id->s = va_arg(ap, char*);
		less_s(env, id);
	}
	if (c == 'd' || c == 'i')
		less_d(ap, env, id);
	if (c == 'u')
		less_u(ap, env, id);
	if (c == 'o')
		less_o(ap, env, id);
	else if (c == 'x')
		less_x(ap, env, id);
	else if (c == 'X')
		less_xx(ap, env, id);
}

void	print_wchar_0(int a, int b, wchar_t ch)
{
	a = (192 + (ch >> 6));
	b = (128 + (ch & 63));
	write(1, &a, 1);
	write(1, &b, 1);
}

void	print_wchar_01(int a, int b, int c, wchar_t ch)
{
	a = (224 + (ch >> 12));
	b = (128 + ((ch >> 6) & 63));
	c = (128 + (ch & 63));
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}

void	ft_convert2(char c, va_list ap, t_env *env, t_id *id)
{
	if (c == 'D')
	{
		env->modifier = 1;
		env->cast = 'l';
		ft_d(ap, env, id);
	}
	if (c == 'C')
		print_unicode_c(ap, env, id);
	if (c == 'S')
		print_unicode_s(ap, env, id);
}
