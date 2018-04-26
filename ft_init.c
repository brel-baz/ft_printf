/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 01:40:27 by brel-baz          #+#    #+#             */
/*   Updated: 2017/11/05 02:07:02 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_x(va_list ap, t_env *env, t_id *id)
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
}

void	init_xx(va_list ap, t_env *env, t_id *id)
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
}

void	init_o(va_list ap, t_env *env, t_id *id)
{
	if (env->modifier == 1)
		ft_cast_oux(env->cast, ap, id);
	else if (env->modifier2 == 1)
		ft_cast_oux2(env->c, env->d, ap, id);
	else
		id->x = va_arg(ap, unsigned long long);
	if (id->x >= 0)
		env->ptr = ft_ub(id->x, 8);
	else if (id->x < 0)
		env->ptr = ft_itoa_base(id->x, 8, 1);
}

void	init_space_d(va_list ap, t_env *env, t_id *id)
{
	if (env->modifier == 1)
		ft_cast_d(env->cast, ap, id);
	else if (env->modifier2 == 1)
		ft_cast_dd(env->c, env->d, ap, id);
	else
		id->d = va_arg(ap, int);
	if (id->d >= 0)
		env->ptr = ft_ub(id->x, 10);
	else if (id->d < 0)
		env->ptr = ft_itoa_base(id->d, 10, 1);
}

void	init_more_d(va_list ap, t_env *env, t_id *id)
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
}
