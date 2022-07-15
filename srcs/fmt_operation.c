/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:10:42 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/15 19:31:24 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	fmt_operation(t_fmt *fmt, va_list args)
{
	if (fmt->c)
		print_c(args);
	else if (fmt->str)
		print_s(args);
	else if (fmt->ptr)
		print_ptr(args);
	else if (fmt->decimal || fmt->integer)
		print_decimal(args);
	else if (fmt->unsi)
		print_unsi(args);
	else if (fmt->hexa_lower)
		print_hexa_lower(args);
	else if (fmt->hexa_upper)
		print_hexa_upper(args);
	else if (fmt->percent)
		print_percent();
}
