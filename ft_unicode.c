/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 18:01:36 by brel-baz          #+#    #+#             */
/*   Updated: 2018/04/24 16:50:08 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wchar_len(wchar_t ch)
{
	if (ch < (1 << 7))
		return (1);
	else if (ch < (1 << 11))
		return (2);
	else if (ch < (1 << 16))
		return (3);
	else if (ch < (1 << 21))
		return (4);
	else
		return (-1);
}

int		stru_len(wchar_t *str)
{
	int len_total;
	int len;
	int i;

	len = 0;
	len_total = 0;
	i = 0;
	while (str[i])
	{
		if ((len = wchar_len(str[i])) == -1)
			return (-1);
		len_total += len;
		i++;
	}
	return (len_total);
}

void	print_wchar(wchar_t ch)
{
	int a;
	int b;
	int c;
	int d;

	a = (240 + (ch >> 18));
	b = (128 + ((ch >> 12) & 63));
	c = (128 + ((ch >> 6) & 63));
	d = (128 + (ch & 63));
	if (ch < (1 << 7))
		write(1, &ch, 1);
	else if (ch < (1 << 11))
		print_wchar_0(a, b, ch);
	else if (ch < (1 << 16))
		print_wchar_01(a, b, c, ch);
	else if (ch < (1 << 21))
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, &c, 1);
		write(1, &d, 1);
	}
}

int		print_unicode_c(va_list ap, t_env *env, t_id *id)
{
	id->ch = va_arg(ap, wchar_t);
	if (wchar_len(id->ch) == -1)
		return (-1);
	print_wchar(id->ch);
	env->len += wchar_len(id->ch);
	return (0);
}

int		print_unicode_s(va_list ap, t_env *env, t_id *id)
{
	int		i;

	id->su = va_arg(ap, wchar_t *);
	if (id->su == NULL)
	{
		env->len += 6;
		write(1, "(null)", 6);
		return (0);
	}
	if (stru_len(id->su) == -1)
		return (-1);
	i = -1;
	while (id->su[++i])
		print_wchar(id->su[i]);
	env->len += stru_len(id->su);
	return (1);
}
