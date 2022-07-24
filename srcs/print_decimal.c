/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:08:06 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/24 10:48:43 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

/*
   
*/

unsigned int	absolute(int num)
{
	unsigned int	unsi_num;

	unsi_num = num;
	if (num < 0)
	{
		unsi_num = -unsi_num;
		return (unsi_num);
	}
	else
		return (unsi_num);
}

int	calc_num_len(int num, int base)
{
	int	count;

	count = 0;
	if (num <= 0)
		++count;
	while (num && ++count)
		num /= base;
	return (count);
}

char	*unsi_num_c_alloc(int num)
{
	char	*rtn;
	int	unsi_num;

	unsi_num = absolute(num);
	rtn = ft_uitoa(unsi_num);
	return (rtn);
}

int	print_decimal(t_fmt *fmt, int num)
{
	int	num_len;
	char	*unsi_num_c;
	int	unsi_num_c_len;

	num_len = 0;
	unsi_num_c = "";
	if (num != 0 || !fmt->dot || fmt->percision)
	{
		num_len = calc_num_len(num, 10);
		unsi_num_c = unsi_num_c_alloc(num);
	}
	unsi_num_c_len = (int)ft_strlen(unsi_num_c);
	if (fmt->percision > unsi_num_c_len)
		fmt->pad = fmt->percision - unsi_num_c_len;
	if (fmt->width > fmt->pad + num_len)
		fmt->offset = fmt->width - fmt->pad - num_len;
	if ((fmt->space || fmt->plus) && num >= 0 && ++fmt->print_len && fmt->offset)
		--fmt->offset;
	fmt->print_len += fmt->offset + fmt->pad + num_len;
	if (fmt->zero && !fmt->dot)
	{
		fmt->pad = fmt->offset;
		fmt->offset = 0;
	}
	if (fmt->negative)
	{
		print_prefix_nbr(fmt, num, unsi_num_c);
		while (fmt->offset--)	
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
		print_prefix_nbr(fmt, num, unsi_num_c);
	}
	if (num != 0 || !fmt->dot || fmt->percision)
		free(unsi_num_c);
	return (fmt->print_len);
}
