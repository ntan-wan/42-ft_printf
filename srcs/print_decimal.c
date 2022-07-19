/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:08:06 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/19 15:32:53 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

/*
   Concerns all the flags except <hash> and <percision>.
   <plus> will cancel out <space> and <negative> will cancel out <zero>.

   Check for <space> and <plus> flags first and process it accordingly.

   Uses write function here for the purpose of increment of fmt->print_len
   each time a 'space' or '+' is printed out.

   <negative> and <zero> will affect the output if only combined 
   with <width> flag, provided <width> is greater than
   string length (number converted into string).
*/

int	print_decimal(t_fmt *fmt, int num)
{
	char	*num_c;
	int		space_count;

	num_c = ft_itoa(num);
	fmt->print_len = ft_strlen(num_c);
	if (fmt->space && !fmt->plus && num >= 0)
		fmt->print_len += write(1, " ", 1);
	if (fmt->plus && num >= 0)
		fmt->print_len += write(1, "+", 1);
	if (fmt->width > fmt->print_len)
	{
		space_count = fmt->width - fmt->print_len;
		fmt->print_len = fmt->width;
		if (fmt->negative)
		{
			ft_putstr_fd(num_c, 1);
			print_space(fmt, space_count);
		}
		else
		{
			print_space(fmt, space_count);
			ft_putstr_fd(num_c, 1);
		}
	}
	return (fmt->print_len);
}
