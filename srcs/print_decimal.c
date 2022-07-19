/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:08:06 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/20 02:19:22 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

/*
   Concerns all the flags except <hash>.
   <plus> will cancel out <space> and <negative> will cancel out <zero>.

   Check for <space> and <plus> flags first and process it accordingly.

   Uses write function here for the purpose of increment of fmt->print_len
   each time a 'space', '-' or '+' is printed out.

   <negative> and <zero> will affect the output if only combined 
   with <width> flag, provided <width> is greater than
   string length (number converted into string).

   <percision> = the unsign number (converted from the number) must be at least
   n(percision) digit. '0' will fill up addtional slots.

   print_prefix :
   <space>      = print ' ' before postive number.
   <positive>   = print '+' before positive number.
   <percision>  = print '0' before number if number of digit in unsigned version
                  is lesser than <percision>.
   <zero> || <percision> = print '-' before number if the number is negative.
   return value = pointer to int or unsigned int in string format.

   ft_uitoa is used to convert unsigned int to character(listed in print_unsi).
   When num is negative + percision or zero flag are raised, the outcome will
   look like this : ("%.4d", -14) -> -0014
   Therefore my printing order is "-", "00", "14".I need unsigned int in the end.

   Double reverse unsigned int, -1 -> 4294967295, -4294967295 -> 1
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

int	calc_num_len(unsigned int unsi_num)
{
	int	len;

	len = 0;
	if (unsi_num == 0)
		return (1);
	while (unsi_num > 0)
	{
		len++;
		unsi_num /= 10;
	}
	return (len);
}

char	*print_prefix(t_fmt *fmt, int num)
{
	char			*rtn;
	unsigned int	unsi_num;
	int				unsi_num_len;
	int				space_count;

	unsi_num = absolute(num);
	unsi_num_len = calc_num_len(unsi_num);
	if (fmt->space && !fmt->plus && num >= 0)
		fmt->print_len += write(1, " ", 1);
	if (fmt->plus && num >= 0)
		fmt->print_len += write(1, "+", 1);
	if ((fmt->zero || fmt->percision) && num < 0)
	{
		fmt->print_len += write(1, "-", 1);
		rtn = ft_uitoa(unsi_num);
	}
	else
		rtn = ft_itoa(num);
	if (fmt->percision > unsi_num_len)
	{
		space_count = fmt->percision - unsi_num_len;
		while (space_count--)
			fmt->print_len += write(1, "0", 1);
	}
	return (rtn);
}

int	print_decimal(t_fmt *fmt, int num)
{
	char	*num_c;
	int		space_count;

	num_c = print_prefix(fmt, num);
	fmt->print_len += ft_strlen(num_c);
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
	else
		ft_putstr_fd(num_c, 1);
	free(num_c);
	return (fmt->print_len);
}
