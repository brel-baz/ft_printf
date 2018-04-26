/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_less2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 04:50:11 by brel-baz          #+#    #+#             */
/*   Updated: 2017/11/03 02:58:24 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_less_xx(va_list ap, t_env *env, t_id *id)
{
	if (env->modifier == 1)
		ft_cast_oux(env->cast, ap, id);
	else if (env->modifier2 == 1)
		ft_cast_oux2(env->c, env->d, ap, id);
	else
		id->x = va_arg(ap, unsigned int);
	if (id->x >= 0)
		env->ptr = ft_ubu(id->x, 16);
	else if (id->x < 0)
		env->ptr = ft_itoa_base_up(id->x, 16);
	env->len2 = env->width - ft_strlen(env->ptr);
	while (env->k < env->len2)
	{
		write(1, " ", 1);
		env->k++;
	}
}

void	less_modulo(t_env *env)
{
	env->len2 = env->width - 1;
	write(1, "%", 1);
	while (env->k < env->len2)
	{
		write(1, " ", 1);
		env->k++;
	}
	env->len += env->k + 1;
}

void	less_c(va_list ap, t_env *env, t_id *id)
{
	id->c = (char)va_arg(ap, int);
	env->len2 = env->width - 1;
	write(1, &id->c, 1);
	while (env->k < env->len2)
	{
		write(1, " ", 1);
		env->k++;
	}
	env->len += 1 + env->k;
}

void	less_xx(va_list ap, t_env *env, t_id *id)
{
	init_less_xx(ap, env, id);
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
		env->len += ft_strlen(env->ptr);
		free(env->ptr);
	}
}
