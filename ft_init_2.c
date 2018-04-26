/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 03:49:36 by brel-baz          #+#    #+#             */
/*   Updated: 2018/04/21 17:17:07 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_d(va_list ap, t_env *env, t_id *id)
{
	if (env->modifier == 1)
		ft_cast_d(env->cast, ap, id);
	else if (env->modifier2 == 1)
		ft_cast_dd(env->c, env->d, ap, id);
	else
		id->d = va_arg(ap, int);
	if (id->d >= 0)
		env->ptr = ft_ub(id->d, 10);
	else if (id->d < 0)
		env->ptr = ft_itoa_base(id->d, 10, 1);
	if (env->value > (int)ft_strlen(env->ptr))
		env->len2 = env->width - env->value;
	else
		env->len2 = env->width - ft_strlen(env->ptr);
	if (env->fp == 1 && id->d == 0 && env->value == 0)
		env->len2++;
	if (env->width > 0 && env->value > 0)
		env->zero = 0;
	if ((env->flag == '+' && id->d > 0) || (env->width > 0 &&
		env->zero == 1 && env->flag == '+' && id->d > 0))
	{
		write(1, "+", 1);
		env->len++;
		env->len2--;
	}
}

void	init_less_d(va_list ap, t_env *env, t_id *id)
{
	if (env->modifier == 1)
		ft_cast_d(env->cast, ap, id);
	else if (env->modifier2 == 1)
		ft_cast_dd(env->c, env->d, ap, id);
	else
		id->d = va_arg(ap, int);
	if (id->d >= 0)
		env->ptr = ft_ub(id->d, 10);
	else if (id->d < 0)
		env->ptr = ft_itoa(id->d);
}

void	init_less_o(va_list ap, t_env *env, t_id *id)
{
	if (env->modifier == 1)
		ft_cast_oux(env->cast, ap, id);
	else if (env->modifier2 == 1)
		ft_cast_oux2(env->c, env->d, ap, id);
	else
		id->x = va_arg(ap, unsigned int);
	env->ptr = ft_itoa_base(id->x, 8, 1);
	env->len2 = env->width - ft_strlen(env->ptr);
	if (env->flag_bis == 1)
	{
		write(1, "0", 1);
		env->len2--;
		env->len++;
	}
	if (env->width < env->value)
	{
		env->len2 = env->value - ft_strlen(env->ptr);
		while (env->k < env->len2)
		{
			write(1, "0", 1);
			env->k++;
		}
		env->flag2 = 1;
	}
}

void	init_less_x(va_list ap, t_env *env, t_id *id)
{
	if (env->modifier == 1)
		ft_cast_oux(env->cast, ap, id);
	else if (env->modifier2 == 1)
		ft_cast_oux2(env->c, env->d, ap, id);
	else
		id->x = va_arg(ap, unsigned int);
	if (id->x >= 0)
		env->ptr = ft_ub(id->x, 16);
	else if (id->x < 0)
		env->ptr = ft_itoa_base(id->x, 16, 1);
	env->len2 = env->width - ft_strlen(env->ptr);
}

void	convertor_d(t_env *env)
{
	if (ft_strcmp(env->ptr, "-(") == 0)
	{
		free(env->ptr);
		if (!(env->ptr = (char*)malloc(sizeof(env->ptr) * 20)))
			return ;
		if (!(env->ptr = ft_strcpy(env->ptr, "-9223372036854775808")))
			return ;
		env->len += ft_strlen(env->ptr);
		ft_putstr(env->ptr);
		free(env->ptr);
		return ;
	}
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
