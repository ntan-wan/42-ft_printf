/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:41:18 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/18 10:39:12 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

// fmt_update = update struct fmt where it stores informations of what
// format specifier it is using.
// fmt_operation = runs particular operation based on the format specifier.

int	fmt_process(const char *str, size_t *ptr_i, va_list args)
{
	t_fmt	fmt;
	int		print_len;

	fmt_init(&fmt);
	fmt_update(str[(*ptr_i) + 1], &fmt);
	print_len = fmt_operation(&fmt, args);
	return (print_len);
}

int	ft_printf(const char *str, ...)
{	
	size_t	i;
	va_list	args;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += fmt_process(str, &i, args);
			i++;
		}
		else
			print_len += print_c(str[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}
