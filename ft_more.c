/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 02:28:38 by brel-baz          #+#    #+#             */
/*   Updated: 2017/11/03 03:59:19 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fp_is_true(t_env *env)
{
	env->len2 = env->value - ft_strlen(env->ptr);
	ft_putstr_len2(env->len2, env);
	ft_putstr(env->ptr);
}

void	more_d(va_list ap, t_env *env, t_id *id)
{
	init_more_d(ap, env, id);
	if (env->value > (int)ft_strlen(env->ptr))
		env->len2 = env->width - env->value;
	else
		env->len2 = env->width - ft_strlen(env->ptr);
	if (id->d >= 0)
		env->len2--;
	ft_putwidth(env->len2, env);
	if (id->d >= 0)
	{
		write(1, "+", 1);
		env->flag2 = 1;
	}
	if (env->fp == 1 && id->x == 0 && env->value == 0)
		prec_is_nul(env);
	if (env->fp == 1)
		fp_is_true(env);
	else
		ft_putstr(env->ptr);
	env->len += ft_strlen(env->ptr) + env->flag2 + env->i;
	free(env->ptr);
}
