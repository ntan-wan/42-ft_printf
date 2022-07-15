/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:41:18 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/15 17:04:52 by ntan-wan         ###   ########.fr       */
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

	i = 0;
	fmt_init(&fmt);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			check_flags(str, &i, &fmt);
			fmt_update(str[i + 1], &fmt);
			fmt_operation(&fmt, args);
			fmt_reset(&fmt);
			i++;
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	return (0);
}
