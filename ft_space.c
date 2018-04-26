/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 01:58:36 by brel-baz          #+#    #+#             */
/*   Updated: 2017/11/08 03:24:01 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prec_is_nul(t_env *env)
{
	env->len += env->i;
	return ;
}

void	space_d(va_list ap, t_env *env, t_id *id)
{
	init_space_d(ap, env, id);
	if (env->value > (int)ft_strlen(env->ptr))
		env->len2 = env->width - env->value;
	else
		env->len2 = env->width - ft_strlen(env->ptr);
	if (id->d >= 0)
	{
		write(1, " ", 1);
		env->flag2 = 1;
		env->len2--;
	}
	ft_putwidth(env->len2, env);
	if (env->fp == 1 && id->x == 0 && env->value == 0)
		prec_is_nul(env);
	if (env->fp == 1)
	{
		env->len2 = env->value - ft_strlen(env->ptr);
		ft_putstr_len2(env->len2, env);
		ft_putstr(env->ptr);
	}
	else
		ft_putstr(env->ptr);
	env->len += ft_strlen(env->ptr) + env->flag2 + env->i;
	free(env->ptr);
}

void	space_u(va_list ap, t_env *env, t_id *id)
{
	if (env->modifier == 1)
		ft_cast_oux(env->cast, ap, id);
	else if (env->modifier2 == 1)
		ft_cast_oux2(env->c, env->d, ap, id);
	else
		id->x = va_arg(ap, unsigned int);
	if (id->x < 0)
		env->ptr = ft_itoa_base(id->x, 10, 1);
	else if (id->x >= 0)
		env->ptr = ft_ub(id->x, 10);
	ft_putstr(env->ptr);
	env->len += ft_strlen(env->ptr) + env->i;
	free(env->ptr);
}

void	space_diup(va_list ap, t_env *env, t_id *id, char c)
{
	if (c == 'd' || c == 'i')
		space_d(ap, env, id);
	if (c == 'u')
		space_u(ap, env, id);
	if (c == 'p')
		ft_p(ap, env, id);
}

void	fp_is_true2(t_env *env)
{
	env->len2 = env->value - ft_strlen(env->ptr);
	env->flag2 = env->len2;
	ft_putstr_len2(env->len2, env);
	ft_putstr(env->ptr);
}
