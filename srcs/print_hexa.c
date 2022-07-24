/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:02:24 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/24 15:14:25 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

/*
   convert_hexa :
   Convert unsigned int to hexadecimal. 
   First, determine which base you want to use. Next, allocate approriate memory 
   with the help of hexa_len. After that, place the character obtained into the
   'array' starting from the back. For example :
   1234 -> 4D2
        -> | | |2|
		-> | |D|2|
		-> |4|D|2|
*/

char	*convert_hexa(t_fmt *fmt, unsigned int unsi_num)
{
	int		hexa_len;
	char	*hexa_c;
	char	*base;

	base = "0123456789abcdef";
	if (fmt->hexa_upper)
		base = "0123456789ABCDEF";
	hexa_len = calc_unsi_num_len(unsi_num, 16);
	hexa_c = (char *)malloc(sizeof(char) * (hexa_len + 1));
	if (!hexa_c)
		return (0);
	if (unsi_num == 0)
		hexa_c[0] = '0';
	hexa_c[hexa_len] = '\0';
	while (unsi_num != 0)
	{
		hexa_c[hexa_len - 1] = base[unsi_num % 16];
		unsi_num /= 16;
		hexa_len--;
	}
	return (hexa_c);
}

/*void	print_prefix_hexa(t_fmt *fmt, char *hexa_c)
{
	int		hexa_len;
	int		space_count;
	char	*hash_prefix;

	hash_prefix = "0x";
	if (fmt->hexa_upper)
		hash_prefix = "0X";
	hexa_len = ft_strlen(hexa_c);
	if (fmt->space && !fmt->plus)
		fmt->print_len += write(1, " ", 1);
	if (fmt->hash && hexa_c[0] != '0')
		fmt->print_len += write(1, hash_prefix, 2);
	if (fmt->plus)
		fmt->print_len += write(1, "+", 1);
	if (fmt->percision > hexa_len)
	{
		space_count = fmt->percision - hexa_len;
		while (space_count--)
			fmt->print_len += write(1, "0", 1);
	}
}

int	print_hexa(t_fmt *fmt, unsigned int num)
{
	char	*hexa_c;
	int		space_count;

	hexa_c = convert_hexa(fmt, num);
	print_prefix_hexa(fmt, hexa_c);
	fmt->print_len += ft_strlen(hexa_c);
	if (fmt->width > fmt->print_len)
	{
		space_count = fmt->width - fmt->print_len;
		fmt->print_len = fmt->width;
		if (fmt->negative)
		{
			ft_putstr_fd(hexa_c, 1);
			print_space(fmt, space_count);
		}
		else
		{
			print_space(fmt, space_count);
			ft_putstr_fd(hexa_c, 1);
		}
	}
	else
		ft_putstr_fd(hexa_c, 1);
	free(hexa_c);
	return (fmt->print_len);
}*/

void	print_prefix_hexa(t_fmt *fmt, char *hexa_c)
{
	//
	if (fmt->hash && hexa_c[0] != '0')
	{
		if (fmt->hexa_lower)
			fmt->print_len += write(1, "0x", 2);
		else if (fmt->hexa_upper)
			fmt->print_len += write(1, "0X", 2);
	}
	while (fmt->pad-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(hexa_c, 1);
}

int	print_hexa(t_fmt *fmt, unsigned int unsi_num)
{
	char	*hexa_c;
	int	hexa_c_len;
	int	hexa_len;
	
	hexa_c = "";
	hexa_len = 0;
	if (unsi_num != 0 || !fmt->dot || fmt->percision)
	{
		hexa_c = convert_hexa(fmt, unsi_num);
		hexa_len = calc_unsi_num_len(unsi_num, 16);
	}
	hexa_c_len = (int)ft_strlen(hexa_c);
	if (fmt->hash && fmt->width)
		fmt->width -= 2;
	if (fmt->percision > hexa_c_len)
		fmt->pad = fmt->percision - hexa_c_len;
	if (fmt->width > fmt->pad + hexa_len)
		fmt->offset = fmt->width - fmt->pad - hexa_len;
	fmt->print_len += fmt->offset + fmt->pad + hexa_len;
	if (fmt->zero && !fmt->dot)
	{
		fmt->pad = fmt->offset;
		fmt->offset = 0;
	}
	if (fmt->negative)
	{
		print_prefix_hexa(fmt, hexa_c);
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
		print_prefix_hexa(fmt, hexa_c);
	}
	if (unsi_num != 0 || !fmt->dot || fmt->percision)
		free(hexa_c);
	return (fmt->print_len);
}
