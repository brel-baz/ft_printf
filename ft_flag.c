/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 04:57:49 by brel-baz          #+#    #+#             */
/*   Updated: 2017/11/08 03:01:27 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_flag(char c, t_env *env)
{
	if (c == '#')
	{
		env->flag = '#';
		return (1);
	}
	else if (c == ' ')
	{
		env->flag = ' ';
		return (1);
	}
	else if (c == '+')
	{
		env->flag = '+';
		return (1);
	}
	else if (c == '-')
	{
		env->flag = '-';
		return (1);
	}
	else
		return (0);
}

void	ft_flag_hastag(char c, va_list ap, t_env *env, t_id *id)
{
	if (env->flag != '#')
		return ;
	if (c == 'o' || c == 'O')
		ft_flag_o(ap, env, id);
	else if (c == 'x')
		ft_flag_x(ap, env, id);
	else if (c == 'X')
		ft_flag_xx(ap, env, id);
	else if (c == 'c')
		ft_c(ap, env, id);
}

void	ft_flag_space(char c, va_list ap, t_env *env, t_id *id)
{
	int flag;
	int len;

	flag = 0;
	len = 0;
	if (env->flag != ' ')
		return ;
	if (c == '%')
	{
		write(1, "%", 1);
		env->len++;
	}
	if (c == 'c')
	{
		len = 0;
		id->c = (char)va_arg(ap, int);
		len = env->width - 1;
		ft_putwidth(len, env);
		write(1, &id->c, 1);
		env->len += 1 + env->i;
	}
	space_diup(ap, env, id, c);
}

void	ft_flag_more(char c, va_list ap, t_env *env, t_id *id)
{
	if (env->flag != '+')
		return ;
	if (c == 'd' || c == 'i')
		more_d(ap, env, id);
	if (c == 'u')
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
	if (c == 'p')
		ft_p(ap, env, id);
}

void	ft_flag(char c, va_list ap, t_env *env, t_id *id)
{
	ft_flag_hastag(c, ap, env, id);
	ft_flag_space(c, ap, env, id);
	ft_flag_more(c, ap, env, id);
	ft_flag_less(c, ap, env, id);
}
