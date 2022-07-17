/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:10:42 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/16 11:17:50 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	fmt_operation(t_fmt *fmt, va_list args)
{
	int	print_length;

	print_length = 0;
	if (fmt->c)
		print_length += print_c(args);
	else if (fmt->str)
		print_length += print_s(args);
	else if (fmt->ptr)
		print_length += print_ptr(args);
	else if (fmt->decimal || fmt->integer)
		print_length += print_decimal(args);
	else if (fmt->unsi)
		print_length += print_unsi(args);
	else if (fmt->hexa_lower)
		print_length += print_hexa_lower(args);
	else if (fmt->hexa_upper)
		print_length += print_hexa_upper(args);
	else if (fmt->percent)
		print_length += print_percent();
	return (print_length);
}
