/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 02:49:11 by brel-baz          #+#    #+#             */
/*   Updated: 2018/04/24 16:43:49 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_convert(char c)
{
	int i;

	i = 0;
	while (CONVERT[i])
	{
		if (c == CONVERT[i] || c == '%')
			return (1);
		i++;
	}
	return (0);
}

int		ft_is_modifier(char c, t_env *env)
{
	int i;

	env->modifier = 0;
	i = 0;
	while (FLAG[i])
	{
		if (c == FLAG[i])
		{
			env->cast = FLAG[i];
			env->modifier = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_is_modifier_2(char c, char d, t_env *env)
{
	env->modifier2 = 0;
	if ((c == 'h' && d == 'h') || (c == 'l' && d == 'l'))
	{
		env->c = c;
		env->d = d;
		env->modifier2 = 1;
		return (1);
	}
	else
		return (0);
}

void	ft_putwidth(int len, t_env *env)
{
	env->i = 0;
	while (env->i < len)
	{
		if (env->zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		env->i++;
	}
}

void	ft_convert(char c, va_list ap, t_env *env, t_id *id)
{
	if (c == '%')
		ft_modulo(env);
	if (c == 'c')
		ft_c(ap, env, id);
	if (c == 'd' || c == 'i')
		ft_d(ap, env, id);
	if (c == 'u')
		ft_u(ap, env, id);
	if (c == 'U')
		ft_uu(ap, env, id);
	if (c == 's')
		ft_s(ap, env, id);
	if (c == 'o' || c == 'O')
		ft_o(ap, env, id);
	if (c == 'x')
		ft_x(ap, env, id);
	if (c == 'X')
		ft_xx(ap, env, id);
	if (c == 'p')
		ft_p(ap, env, id);
	else
		ft_convert2(c, ap, env, id);
}
