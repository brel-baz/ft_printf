/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_less.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 04:18:18 by brel-baz          #+#    #+#             */
/*   Updated: 2017/11/08 03:23:51 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	less_s(t_env *env, t_id *id)
{
	if (id->s == NULL)
		id->s = "(null)";
	if (id->s[0] == '\0')
		env->len2 = env->width;
	else
		env->len2 = env->width - ft_strlen(id->s);
	if (env->fp == 1)
	{
		if (id->s[0] == '\0')
			env->len2 = env->width;
		else
			env->len2 = env->width - env->value;
		ft_putstr_len(id->s, env->value);
	}
	else
		ft_putstr(id->s);
	while (env->k < env->len2)
	{
		write(1, " ", 1);
		env->k++;
	}
	if (env->fp == 1 && id->s[0] != '\0')
		env->len += ft_strlen(id->s) + env->k - env->value;
	else
		env->len += ft_strlen(id->s) + env->k;
}

void	less_d(va_list ap, t_env *env, t_id *id)
{
	init_less_d(ap, env, id);
	if (id->d == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (id->d > 0 && env->flag_bis == 1)
		write(1, "+", 1);
	if (env->fp == 1)
		fp_is_true2(env);
	else
		ft_putstr(env->ptr);
	if (env->value > (int)ft_strlen(env->ptr))
		env->len2 = env->width - env->value - env->flag_bis;
	else
		env->len2 = env->width - ft_strlen(env->ptr) - env->flag_bis;
	while (env->k < env->len2)
	{
		write(1, " ", 1);
		env->k++;
	}
	env->len += ft_strlen(env->ptr) + env->flag2 + env->k + env->flag_bis;
	free(env->ptr);
}

void	less_u(va_list ap, t_env *env, t_id *id)
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
	env->len2 = env->width - ft_strlen(env->ptr);
	ft_putstr(env->ptr);
	while (env->k < env->len2)
	{
		write(1, " ", 1);
		env->k++;
	}
	env->len += ft_strlen(env->ptr) + env->k;
	free(env->ptr);
}

void	less_o(va_list ap, t_env *env, t_id *id)
{
	int fp;

	fp = 0;
	init_less_o(ap, env, id);
	if (env->fp == 1 && env->flag2 == 0)
	{
		fp = env->value - ft_strlen(env->ptr);
		ft_putstr_len2(fp, env);
		env->len2 -= fp;
		env->len++;
	}
	ft_putstr(env->ptr);
	while (env->k < env->len2)
	{
		write(1, " ", 1);
		env->k++;
	}
	env->len += ft_strlen(env->ptr) + env->k;
	free(env->ptr);
}

void	less_x(va_list ap, t_env *env, t_id *id)
{
	init_less_x(ap, env, id);
	if (env->zero == 1)
	{
		write(1, "0x", 2);
		env->len2 -= 2;
		env->len += 2;
	}
	if (id->x == 0)
	{
		write(1, "0", 1);
		env->len++;
	}
	else
	{
		ft_putstr(env->ptr);
		while (env->k < env->len2)
		{
			write(1, " ", 1);
			env->k++;
		}
		env->len += ft_strlen(env->ptr) + env->k;
		free(env->ptr);
	}
}
