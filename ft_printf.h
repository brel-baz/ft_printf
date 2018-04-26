/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 03:13:37 by brel-baz          #+#    #+#             */
/*   Updated: 2018/04/24 16:39:26 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>
# include <fcntl.h>
# define BASE "0123456789abcdef"
# define BASE_UP "0123456789ABCDEF"
# define CONVERT "sSpdDioOuUxXcC"
# define FLAG "hljtzq"
# define WIDTH "0123456789"

typedef union	u_id
{
	wchar_t		ch;
	wchar_t		*su;
	char		c;
	long long	d;
	char		*s;
	long long	x;
}				t_id;

typedef struct	s_env
{
	int			flag_more;
	int			flag_less;
	int			i;
	int			j;
	int			k;
	int			it;
	int			len;
	int			len2;
	int			flag2;
	int			zero;
	char		flag;
	char		cast;
	char		c;
	char		d;
	char		*ptr;
	int			modifier;
	int			modifier2;
	int			width;
	int			value;
	int			fp;
	int			flag_bis;
}				t_env;

void			ft_convert(char c, va_list ap, t_env *env, t_id *id);
void			ft_convert2(char c, va_list ap, t_env *env, t_id *id);
void			ft_flag_hastag(char c, va_list ap, t_env *env, t_id *id);
void			ft_flag_space(char c, va_list ap, t_env *env, t_id *id);
void			ft_flag_more(char c, va_list ap, t_env *env, t_id *id);
char			*ft_itoa_base(long long value, long long b, int i);
char			*ft_itoa_base_up(long long value, long long base);
long long		ft_pow(long long nb, long long pow);
char			*ft_utoa(unsigned int n);
int				ft_is_convert(char c);
int				ft_is_flag(char c, t_env *env);
void			ft_flag_less(char c, va_list ap, t_env *env, t_id *id);
void			ft_flag(char c, va_list ap, t_env *env, t_id *id);
int				ft_is_modifier(char c, t_env *env);
int				ft_is_modifier_2(char c, char d, t_env *env);
void			ft_putstr_len(char *str, int len);
void			ft_putstr_len2(int len, t_env *env);
void			ft_putwidth(int len, t_env *env);
void			ft_c(va_list ap, t_env *env, t_id *id);
void			ft_d(va_list ap, t_env *env, t_id *id);
void			ft_u(va_list ap, t_env *env, t_id *id);
void			ft_uu(va_list ap, t_env *env, t_id *id);
void			ft_s(va_list ap, t_env *env, t_id *id);
void			ft_o(va_list ap, t_env *env, t_id *id);
void			ft_modulo(t_env *env);
void			ft_x(va_list ap, t_env *env, t_id *id);
void			ft_xx(va_list ap, t_env *env, t_id *id);
void			ft_p(va_list ap, t_env *env, t_id *id);
void			ft_flag_o(va_list ap, t_env *env, t_id *id);
void			ft_flag_x(va_list ap, t_env *env, t_id *id);
void			ft_flag_xx(va_list ap, t_env *env, t_id *id);
void			parse_precision(const char *format, t_env *env);
void			parse_width(const char *format, t_env *env);
void			parse_flg(const char *format, t_env *env, va_list ap, t_id *id);
void			parse_modifier2(const char *format, t_env *env);
void			parse_modifier(const char *format, t_env *env);
void			ft_cast_d(char c, va_list ap, t_id *id);
void			ft_cast_uu(char c, va_list ap, t_id *id);
void			ft_cast_oux(char c, va_list ap, t_id *id);
void			ft_cast_dd(char c, char d, va_list ap, t_id *id);
void			ft_cast_oux2(char c, char d, va_list ap, t_id *id);
char			*ft_ub(unsigned long long value, unsigned long long b);
char			*ft_ubu(unsigned long long value, unsigned long long b);
void			init_x(va_list ap, t_env *env, t_id *id);
void			init_d(va_list ap, t_env *env, t_id *id);
void			init_xx(va_list ap, t_env *env, t_id *id);
void			init_o(va_list ap, t_env *env, t_id *id);
void			init_space_d(va_list ap, t_env *env, t_id *id);
void			init_more_d(va_list ap, t_env *env, t_id *id);
void			init_less_d(va_list ap, t_env *env, t_id *id);
void			init_less_o(va_list ap, t_env *env, t_id *id);
void			init_less_x(va_list ap, t_env *env, t_id *id);
void			init_less_xx(va_list ap, t_env *env, t_id *id);
void			space_d(va_list ap, t_env *env, t_id *id);
void			space_u(va_list ap, t_env *env, t_id *id);
void			space_diup(va_list ap, t_env *env, t_id *id, char c);
void			more_d(va_list ap, t_env *env, t_id *id);
void			convertor_d(t_env *env);
void			prec_is_nul(t_env *env);
void			less_s(t_env *env, t_id *id);
void			less_d(va_list ap, t_env *env, t_id *id);
void			less_u(va_list ap, t_env *env, t_id *id);
void			less_o(va_list ap, t_env *env, t_id *id);
void			less_x(va_list ap, t_env *env, t_id *id);
void			less_modulo(t_env *env);
void			less_c(va_list ap, t_env *env, t_id *id);
void			less_xx(va_list ap, t_env *env, t_id *id);
void			fp_is_true2(t_env *env);
void			parse_format(const char *s, t_env *env, va_list ap, t_id *id);
int				print_unicode_c(va_list ap, t_env *env, t_id *id);
int				print_unicode_s(va_list ap, t_env *env, t_id *id);
void			print_wchar_0(int a, int b, wchar_t ch);
void			print_wchar_01(int a, int b, int c, wchar_t ch);
#endif
