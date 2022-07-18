/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:52:29 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/18 18:46:08 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	print_s(t_fmt *fmt, char *str)
{
	int	space_count;
	int	str_len;

	space_count = 0;
	str_len = ft_strlen(str);
	if (!str)
		str = "(null)";
	if (fmt->width && (fmt->width > str_len))
		space_count = fmt->width - str_len;
	if (fmt->dot || fmt->percision)
	{
		if (fmt->width)
			space_count = fmt->width - fmt->percision;
		if (str_len > fmt->percision)
			str_len = fmt->percision;
	}
	if (fmt->negative)
	{
		//fmt->percision
		//ft_putstr_fd(str, 1);
		write(1, str, str_len);
		while (space_count--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (space_count--)
			ft_putchar_fd(' ', 1);
		write(1, str, str_len);
		//ft_putstr_fd(str, 1);
	}
	return (str_len + space_count);
}
