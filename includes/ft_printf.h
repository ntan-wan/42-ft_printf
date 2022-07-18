/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 09:18:31 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/18 10:46:08 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}	t_fmt;

void	fmt_init(t_fmt *fmt);

void	fmt_update(char c, t_fmt *fmt);

void	fmt_update_bonus(char c, t_fmt *fmt);

int		fmt_operation(t_fmt *fmt, va_list args);

int		print_c(int c);

int		print_s(char *str);

int		print_ptr(unsigned long ptr);

int		print_decimal(int num);

int		print_hexa(unsigned int hexa, t_fmt *fmt);

int		print_percent(void);

int		print_unsi(unsigned int unsi);

void	check_flags(const char *str, size_t *ptr_i, t_fmt *fmt);

#endif
