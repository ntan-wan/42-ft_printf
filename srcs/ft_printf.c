/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:41:18 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/18 01:34:04 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	fmt_process(va_list args, t_fmt *fmt, int *print_len)
{
	//check_flags(str, i, fmt);
	(*print_len) += fmt_operation(fmt, args);
	//fmt_reset(&fmt);
}

int	ft_printf(const char *str, ...)
{	
	size_t	i;
	va_list	args;
	int		print_len;
	t_fmt	fmt;

	i = 0;
	print_len = 0;
	//fmt_init(&fmt);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			fmt_init(&fmt);
			fmt_update(str[i + 1], &fmt);
			fmt_process(args, &fmt, &print_len);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			print_len++;
		}
		i++;
	}
	va_end(args);
	return (print_len);
}
