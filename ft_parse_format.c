/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 03:26:37 by brel-baz          #+#    #+#             */
/*   Updated: 2017/10/27 22:28:13 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_format1(const char *format, t_env *env)
{
	if (ft_isdigit(format[env->it + 1]) == 1)
		parse_width(format, env);
	if (format[env->it + 1] == '.')
		parse_precision(format, env);
	if (ft_is_modifier_2(format[env->it + 1], format[env->it + 2], env) == 1)
	{
		ft_is_modifier_2(format[env->it + 1], format[env->it + 2], env);
		env->it += 2;
	}
	if (ft_is_modifier(format[env->it + 1], env) == 1)
	{
		ft_is_modifier(format[env->it + 1], env);
		env->it++;
	}
}

void	parse_format2(const char *format, t_env *env, va_list ap, t_id *id)
{
	if (ft_is_flag(format[env->it + 1], env) == 1 &&
		ft_is_flag(format[env->it + 2], env) == 1)
	{
		while (ft_is_flag(format[env->it + 1], env) == 1)
		{
			if (format[env->it + 1] == '+')
				env->flag_more = 1;
			if (format[env->it + 1] == '-')
				env->flag_less = 1;
			env->it++;
		}
		env->it--;
	}
	if (ft_is_flag(format[env->it + 1], env) == 1)
		parse_flg(format, env, ap, id);
	else if (ft_is_convert(format[env->it + 1]) == 1)
		ft_convert(format[env->it + 1], ap, env, id);
	env->it++;
}

void	parse_format(const char *format, t_env *env, va_list ap, t_id *id)
{
	if (format[env->it + 1] == '\0')
		return ;
	parse_format1(format, env);
	parse_format2(format, env, ap, id);
}
