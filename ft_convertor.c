/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 03:47:13 by brel-baz          #+#    #+#             */
/*   Updated: 2017/11/03 03:58:26 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c(va_list ap, t_env *env, t_id *id)
{
	int		len;

	len = 0;
	id->c = (char)va_arg(ap, int);
	len = env->width - 1;
	ft_putwidth(len, env);
	write(1, &id->c, 1);
	env->len += 1 + env->i;
}

void	ft_d(va_list ap, t_env *env, t_id *id)
{
	init_d(ap, env, id);
	if ((env->fp == 1 && id->d < 0) || (env->width > 0 &&
	env->zero == 1 && id->d < 0))
	{
		write(1, "-", 1);
		id->d *= -1;
		env->ptr = ft_ub(id->d, 10);
		env->len++;
		if (env->fp == 1)
			env->len2--;
	}
	ft_putwidth(env->len2, env);
	if (env->fp == 1 && id->d == 0 && env->value == 0)
	{
		env->len += env->i;
		return ;
	}
	convertor_d(env);
}

void	ft_s(va_list ap, t_env *env, t_id *id)
{
	int		len;

	len = 0;
	id->s = va_arg(ap, char*);
	if (id->s == NULL)
		id->s = "(null)";
	if (env->fp == 1)
	{
		if (id->s[0] == '\0')
			len = env->width;
		else
			len = env->width - env->value;
	}
	else
		len = env->width - ft_strlen(id->s);
	ft_putwidth(len, env);
	if (id->s[0] == '\0')
		env->len += ft_strlen(id->s) + env->i;
	else
		env->len += ft_strlen(id->s) + env->i - env->value;
	if (env->fp == 1)
		ft_putstr_len(id->s, env->value);
	else
		ft_putstr(id->s);
}

void	ft_o(va_list ap, t_env *env, t_id *id)
{
	init_o(ap, env, id);
	if (env->value > (int)ft_strlen(env->ptr))
		env->len2 = env->width - env->value;
	else
		env->len2 = env->width - ft_strlen(env->ptr);
	if (env->fp == 1 && id->x == 0 && env->value == 0)
		env->len2++;
	ft_putwidth(env->len2, env);
	if (env->fp == 1 && id->x == 0 && env->value == 0)
	{
		env->len += env->i;
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

void	ft_uu(va_list ap, t_env *env, t_id *id)
{
	if (env->modifier == 1)
		ft_cast_uu(env->cast, ap, id);
	else if (env->modifier2 == 1)
		ft_cast_oux2(env->c, env->d, ap, id);
	else
		id->x = va_arg(ap, unsigned long long);
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
