/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 00:57:30 by brel-baz          #+#    #+#             */
/*   Updated: 2017/11/08 03:26:49 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_o(va_list ap, t_env *env, t_id *id)
{
	int	len;

	if (env->modifier == 1)
		ft_cast_oux(env->cast, ap, id);
	else
		id->x = va_arg(ap, unsigned long long);
	env->ptr = ft_itoa_base(id->x, 8, 1);
	len = env->width - ft_strlen(env->ptr) - 1;
	if (ft_strcmp(env->ptr, "0") == 0)
	{
		write(1, "0", 1);
		env->len++;
		free(env->ptr);
		return ;
	}
	ft_putwidth(len, env);
	write(1, "0", 1);
	if (env->fp == 1 && id->x == 0 && env->value == 0)
	{
		env->len++;
		return ;
	}
	ft_putstr(env->ptr);
	env->len += ft_strlen(env->ptr) + 1 + env->i;
	free(env->ptr);
}

void	ft_flag_x(va_list ap, t_env *env, t_id *id)
{
	int len;

	init_x(ap, env, id);
	len = env->width - ft_strlen(env->ptr) - 2;
	if (env->zero == 1)
		write(1, "0x", 2);
	ft_putwidth(len, env);
	if (id->x == 0)
	{
		if (env->fp == 1)
			return ;
		write(1, "0", 1);
		env->len++;
	}
	else
	{
		if (env->zero == 0)
			write(1, "0x", 2);
		ft_putstr(env->ptr);
		env->len += ft_strlen(env->ptr) + 2 + env->i;
	}
	free(env->ptr);
}

void	ft_flag_xx(va_list ap, t_env *env, t_id *id)
{
	int len;

	id->x = va_arg(ap, unsigned long long);
	env->ptr = ft_itoa_base_up(id->x, 16);
	if (env->modifier == 1)
		ft_cast_oux(env->cast, ap, id);
	len = env->width - ft_strlen(env->ptr) - 2;
	if (env->zero == 1)
		write(1, "0X", 2);
	ft_putwidth(len, env);
	if (id->x == 0)
	{
		write(1, "0", 1);
		env->len++;
	}
	else
	{
		if (env->zero == 0)
			write(1, "0X", 2);
		ft_putstr(env->ptr);
		env->len += ft_strlen(env->ptr) + 2 + env->i;
	}
	free(env->ptr);
}
