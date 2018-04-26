/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 04:26:52 by brel-baz          #+#    #+#             */
/*   Updated: 2017/11/08 03:07:22 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_modulo(t_env *env)
{
	int len;

	len = 0;
	len = env->width - 1;
	ft_putwidth(len, env);
	write(1, "%", 1);
	env->len += env->i + 1;
}

void	ft_x(va_list ap, t_env *env, t_id *id)
{
	int len;

	len = 0;
	init_x(ap, env, id);
	if (env->value > (int)ft_strlen(env->ptr))
		len = env->width - env->value;
	else
		len = env->width - ft_strlen(env->ptr);
	if (env->fp == 1 && id->x == 0 && env->value == 0)
		len++;
	ft_putwidth(len, env);
	if (env->fp == 1 && id->x == 0 && env->value == 0)
	{
		env->len += env->i;
		return ;
	}
	if (env->fp == 1)
		ft_putstr_len(env->ptr, ft_atoi(env->ptr));
	else
		ft_putstr(env->ptr);
	env->len += ft_strlen(env->ptr) + env->i;
	free(env->ptr);
}

void	ft_xx(va_list ap, t_env *env, t_id *id)
{
	int len;

	len = 0;
	init_xx(ap, env, id);
	if (env->value > (int)ft_strlen(env->ptr))
		len = env->width - env->value;
	else
		len = env->width - ft_strlen(env->ptr);
	ft_putwidth(len, env);
	if (env->fp == 1 && id->x == 0 && env->value == 0)
	{
		env->len += env->i;
		return ;
	}
	if (env->fp == 1)
		ft_putstr_len(env->ptr, env->value);
	else
		ft_putstr(env->ptr);
	env->len += ft_strlen(env->ptr) + env->i;
	free(env->ptr);
}

void	ft_p(va_list ap, t_env *env, t_id *id)
{
	int len;

	len = 0;
	id->x = va_arg(ap, unsigned long long);
	env->ptr = ft_ub(id->x, 16);
	if (ft_strcmp(env->ptr, "0") == 0)
	{
		write(1, "0x0", 3);
		env->len += 3;
		free(env->ptr);
	}
	else
	{
		write(1, "0x", 2);
		ft_putstr(env->ptr);
		env->len += ft_strlen(env->ptr) + 2;
		free(env->ptr);
	}
}

void	ft_u(va_list ap, t_env *env, t_id *id)
{
	if (env->modifier == 1)
		ft_cast_oux(env->cast, ap, id);
	else if (env->modifier2 == 1)
		ft_cast_oux2(env->c, env->d, ap, id);
	else
		id->x = va_arg(ap, unsigned int);
	env->ptr = ft_ub(id->x, 10);
	if (env->value > (int)ft_strlen(env->ptr))
		env->len2 = env->width - env->value;
	else
		env->len2 = env->width - ft_strlen(env->ptr);
	ft_putwidth(env->len2, env);
	if (env->fp == 1)
	{
		env->len2 = env->value - ft_strlen(env->ptr);
		ft_putstr_len2(env->len2, env);
		ft_putstr(env->ptr);
	}
	else
		ft_putstr(env->ptr);
	env->len += ft_strlen(env->ptr) + env->i;
	free(env->ptr);
}
