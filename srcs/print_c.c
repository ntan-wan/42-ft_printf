/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:28:02 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/18 19:01:24 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

// Print character and return number of characters printed.
// print_space_count - print_len = to find out how many spaces left to
// fill up by "space" character.

int	print_c(t_fmt *fmt, int c)
{
	int	print_len;
	int	print_space_count;
	
	print_len = 1;
	print_space_count = 0;	
	if (fmt->width)
	{
		print_space_count = fmt->width - print_len;
		while (print_space_count--)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(c, 1);
	}
	if (fmt->negative)
	{
		ft_putchar_fd(c, 1);
		while (print_space_count--)
			ft_putchar_fd(' ', 1);
	}
	else
		ft_putchar_fd(c, 1);
	return (print_len + print_space_count);
}
