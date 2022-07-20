/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 09:18:31 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/20 10:56:11 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   <limits.h> is used in print_decimal. It uses the declration of INT_MIN.
*/
#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>

# include <stddef.h>

int		ft_printf(const char *str, ...);

int		flag_check_bonus(char c);

typedef struct s_fmt
{
	va_list	args;
	int		c;
	int		print_len;
	int		str;
	int		ptr;
	int		decimal;
	int		integer;
	int		unsi;
	int		hexa_lower;
	int		hexa_upper;
	int		percent;
	int		negative;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		percision;
}	t_fmt;

void	fmt_init(t_fmt *fmt);

void	fmt_update(char c, t_fmt *fmt);

void	fmt_update_flags(char c, t_fmt *fmt);

int		fmt_operation(t_fmt *fmt, va_list args);

int		print_c(t_fmt *fmt, int c);

int		print_s(t_fmt *fmt, char *str);

int		print_ptr(unsigned long ptr);

int		print_decimal(t_fmt *fmt, int num);

int		print_hexa(t_fmt *fmt, unsigned int hexa);

int		print_percent(t_fmt *fmt);

int		print_unsi(t_fmt *fmt, unsigned int unsi);

// ft_uitoa is listed in print_unsi.
char	*ft_uitoa(unsigned int n);

void	print_space(t_fmt *fmt, int space_count);

#endif
