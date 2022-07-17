/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:41:18 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/16 09:24:52 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
//
#include <stdio.h>

int	ft_printf(const char *str, ...)
{	
	size_t	i;
	t_fmt	fmt;
	va_list	args;
	int	print_length;

	i = 0;
	fmt_init(&fmt);
	va_start(args, str);
	print_length = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			check_flags(str, &i, &fmt);
			fmt_update(str[i + 1], &fmt);
			print_length += fmt_operation(&fmt, args);
			fmt_reset(&fmt);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			print_length++;
			//write(1, &str[i], 1);
		}
		i++;
	}
	return (print_length);
}
