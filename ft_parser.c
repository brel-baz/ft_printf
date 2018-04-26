/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 02:19:53 by brel-baz          #+#    #+#             */
/*   Updated: 2017/11/08 03:05:21 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_precision(const char *format, t_env *env)
{
	env->j = 0;
	env->value = 0;
	env->fp = 1;
	while (ft_isdigit(format[env->it + 2]) == 1)
	{
		env->value = (env->value * 10) + format[env->it + 2] - 48;
		env->j++;
		env->it++;
	}
	env->it++;
}

void	parse_width(const char *format, t_env *env)
{
	env->j = 0;
	env->zero = 0;
	env->width = 0;
	if (format[env->it + 1] == '0')
		env->zero = 1;
	while (ft_isdigit(format[env->it + 1]) == 1 || format[env->it + 1] == '+')
	{
		if (format[env->it + 1] == '+')
		{
			env->flag = '+';
			env->it++;
		}
		env->width = (env->width * 10) + format[env->it + 1] - 48;
		env->it++;
	}
	if (format[env->it + 1] == '.')
		parse_precision(format, env);
}

void	parse_flg1(const char *format, t_env *env)
{
	if (ft_is_modifier_2(format[env->it + 2], format[env->it + 3], env) == 1)
	{
		ft_is_modifier_2(format[env->it + 2], format[env->it + 3], env);
		env->it += 2;
	}
	if (ft_is_modifier(format[env->it + 2], env) == 1)
	{
		ft_is_modifier(format[env->it + 2], env);
		env->it++;
	}
	if (ft_isdigit(format[env->it + 2]) == 1)
	{
		env->j = 0;
		env->zero = 0;
		env->width = 0;
		if (format[env->it + 2] == '0')
			env->zero = 1;
		while (ft_isdigit(format[env->it + 2]) == 1)
		{
			env->width = (env->width * 10) + format[env->it + 2] - 48;
			env->it++;
		}
	}
}

void	parse_flg2(const char *format, t_env *env)
{
	if (format[env->it + 2] == '.')
	{
		env->j = 0;
		env->value = 0;
		env->fp = 1;
		while (ft_isdigit(format[env->it + 3]) == 1)
		{
			env->value = (env->value * 10) + format[env->it + 3] - 48;
			env->it++;
		}
		env->it++;
	}
	if (env->flag_more == 1)
		env->flag = '+';
	if (env->flag_more == 1 && env->flag_less == 1)
	{
		env->flag_bis = 1;
		env->flag = '-';
	}
}

void	parse_flg(const char *format, t_env *env, va_list ap, t_id *id)
{
	parse_flg1(format, env);
	parse_flg2(format, env);
	if (env->flag_less == 1 && env->flag == '#')
	{
		env->flag_bis = 1;
		env->flag = '-';
	}
	ft_flag(format[env->it + 2], ap, env, id);
	env->it++;
}
