/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 09:18:31 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/15 19:36:14 by ntan-wan         ###   ########.fr       */
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
	int	c;
	int	str;
	int	ptr;
	int	decimal;
	int	integer;
	int	unsi;
	int	hexa_lower;
	int	hexa_upper;
	int	percent;
	int	negative;
	int	zero;
	int	dot;
	int	hash;
	int	space;
	int	plus;
}	t_fmt;

void	fmt_init(t_fmt *fmt);

void	fmt_reset(t_fmt *fmt);

void	fmt_update(char c, t_fmt *fmt);

void	fmt_update_bonus(char c, t_fmt *fmt);

void	fmt_operation(t_fmt *fmt, va_list args);

void	print_c(va_list args);

void	print_s(va_list args);

void	print_ptr(va_list args);

void	print_decimal(va_list args);

void	print_hexa_lower(va_list args);

void	print_hexa_upper(va_list args);

void	print_percent(void);

void	print_unsi(va_list args);

void	ft_putnbr_base(unsigned long nbr, char *base);

void	check_flags(const char *str, size_t *ptr_i, t_fmt *fmt);

#endif
