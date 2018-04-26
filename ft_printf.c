/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 05:11:15 by brel-baz          #+#    #+#             */
/*   Updated: 2018/04/24 16:48:34 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_env(t_env *env)
{
	env->len = 0;
	env->len2 = 0;
	env->flag2 = 0;
	env->flag = '0';
	env->it = 0;
	env->width = 0;
	env->value = 0;
	env->zero = 0;
	env->fp = 0;
	env->k = 0;
}

void	init_env2(t_env *env)
{
	env->fp = 0;
	env->flag_more = 0;
	env->flag_less = 0;
}

void	free_env(t_env *env, t_id *id, va_list ap)
{
	free(env);
	free(id);
	va_end(ap);
}

int		ft_printf(const char *format, ...)
{
	int		len;
	va_list ap;
	t_env	*env;
	t_id	*id;

	va_start(ap, format);
	if (!(env = (t_env*)malloc(sizeof(t_env))) ||
	!(id = (t_id*)malloc(sizeof(t_id))))
		return (0);
	init_env(env);
	while (format[env->it])
	{
		init_env2(env);
		if (format[env->it] == '%')
			parse_format(format, env, ap, id);
		else
		{
			write(1, &format[env->it], 1);
			env->len++;
		}
		(format[env->it] == '\0' ? env->it += 0 : env->it++);
	}
	len = env->len;
	free_env(env, id, ap);
	return (len);
}
