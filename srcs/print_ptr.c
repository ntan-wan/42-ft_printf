/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:17:22 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/18 11:00:06 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

// ft_ptr_len & ft_put_ptr are the same as ft_hexa_len
// ft_put_hexa. The difference is the data type of
// the parameter.
// ft_put_hexa is a recursive function. The purpose of
// minus 10 is to align number "10" with character 'a/A'.

int	ft_ptr_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(unsigned long num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	print_ptr(unsigned long ptr)
{
	int	print_len;

	print_len = write(1, "0x", 2);
	if (ptr == 0)
		print_len += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		print_len += ft_ptr_len(ptr);
	}
	return (print_len);
}
