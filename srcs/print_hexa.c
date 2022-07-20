/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:02:24 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/20 08:42:55 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

// ft_hexa_len and ft_put_hexa are the same as ft_ptr_len and ft_put_ptr in 
// print_ptr.
// The only difference is the data type parameter,
// i.e,unsigned int (hexa) vs unsigned long (ptr).
// ft_put_hexa is a recursive function. The purpose of minus 10 is to align
// number "10" with character 'a/A'.

int	ft_hexa_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hexa(unsigned int num, t_fmt *fmt)
{
	if (num >= 16)
	{
		ft_put_hexa(num / 16, fmt);
		ft_put_hexa(num % 16, fmt);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (fmt->hexa_lower)
				ft_putchar_fd((num - 10 + 'a'), 1);
			else if (fmt->hexa_upper)
				ft_putchar_fd(num - 10 + 'A', 1);
		}
	}
}

int	print_hexa(t_fmt *fmt, unsigned int hexa)
{
	int	print_len;

	print_len = 0;
	ft_put_hexa(hexa, fmt);
	print_len += ft_hexa_len(hexa);
	return (print_len);
}
