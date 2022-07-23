/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:08:06 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/23 17:41:13 by ntan-wan         ###   ########.fr       */
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

   (listed in print_unsi)
   ft_uitoa :
   Convert unsigned int to character.
   When num is negative + percision or zero flag are raised, the outcome will
   look like this : ("%.4d", -14) -> -0014
   Therefore my printing order is "-", "00", "14".I need unsigned int in the end.

   (listed in print_unsi)
   ft_num_len :
   Count the number of digits of the number.

   absolute :
   Absolute the number.
   Double reverse unsigned int, e.g : -1 
   -1 -> 4294967295, -4294967295 -> 1 .
   
   zero dot+percision 
   (print_len - pads && space -> prefix order) percision > str_len
  
   prefix -> space -> prefix -> str -> space.
   1. prefix -> space -> str
   2. prefix -> str -> space
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

/*char	*print_prefix(t_fmt *fmt, int num)
{
	char			*rtn;
	unsigned int	unsi_num;
	int				unsi_num_len;
	int				space_count;

	unsi_num = absolute(num);
	unsi_num_len = ft_num_len(unsi_num, 10);
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
}*/

/*int	print_decimal(t_fmt *fmt, int num)
{
	char	*num_c;
	int		space_count;
	
	num_c = "";
	if (fmt->zero && fmt->dot)
		fmt->zero = 0;
	if (num != 0 || fmt->percision || !fmt->dot)
	{
		num_c = print_prefix(fmt, num);
		fmt->print_len += ft_strlen(num_c);
	}
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
	
	if (num != 0 || fmt->percision || !fmt->dot)
		free(num_c);
	return (fmt->print_len);
}*/

#include <stdio.h>
char	*num_c_alloc(t_fmt *fmt, int num)
{
	char	*rtn;
	int		unsi_num;
	//
	//printf("|%d|", fmt->percision);
	//printf("|%d|", fmt->zero);
	unsi_num = absolute(num);
	if ((fmt->zero || fmt->percision) && num < 0)
		rtn = ft_uitoa(unsi_num);
	else
		rtn = ft_itoa(num);
	//
//	printf("|%s|", rtn);
	return (rtn);
}

//
void	print_prefix(t_fmt *fmt, int num)
{
	unsigned int	unsi_num;
	int				unsi_num_len;
	int				space_count;

	//
	//printf("im'm inside");
	unsi_num = absolute(num);
	unsi_num_len = ft_num_len(unsi_num, 10);
	if (fmt->space && !fmt->plus && num >= 0)
		fmt->print_len += write(1, " ", 1);
	if (fmt->plus && num >= 0)
		fmt->print_len += write(1, "+", 1);
	//
	
//	printf("|%d|", fmt->zero);
//	printf("|%d|", fmt->percision);
	//printf("|%d|", num);
	if ((fmt->zero || fmt->percision) && num < 0)
		fmt->print_len += write(1, "-", 1);
	if (fmt->percision > unsi_num_len)
	{
		space_count = fmt->percision - unsi_num_len;
		while (space_count--)
			fmt->print_len += write(1, "0", 1);
	}
}
//

int	print_decimal(t_fmt *fmt, int num)
{
	char	*num_c;
	int		space_count;
	
	num_c = "";
	if (num != 0 || fmt->percision || !fmt->dot)
	{
		num_c = num_c_alloc(fmt, num);
		fmt->print_len += ft_strlen(num_c);
	}
	if (fmt->percision > (int)ft_strlen(num_c))
		fmt->pads = fmt->percision - (int)ft_strlen(num_c);
		//
	if (fmt->plus || fmt->space || num < 0)
		fmt->sign_space = 1;
		//
	if (fmt->zero && fmt->dot)
		fmt->zero = 0;
	//printf("|%d|", fmt->percision);
	//printf("|%d|", fmt->print_len);
	//printf("|%d|", fmt->width);
	////////////////////////////////////
	if (!((fmt->percision > fmt->print_len) && (fmt->width > fmt->print_len)))
	{
		
		print_prefix(fmt, num);
		//
		if (num < 0)
			fmt->width++;
	}

		//printf("percision |%d|\n", fmt->percision);
		//printf("print_len |%d|\n", fmt->print_len);
		//printf("width |%d|\n", fmt->width);
	if (fmt->width > fmt->print_len)
	{
		
		space_count = fmt->width - fmt->print_len - fmt->pads - fmt->sign_space;
		fmt->print_len = fmt->width - fmt->pads - fmt->sign_space;
		//
		if (!fmt->negative)
			print_space(fmt, space_count);
		if (fmt->percision > (int)ft_strlen(num_c))
		{
			print_prefix(fmt, num);
			if (fmt->percision > fmt->width)
				fmt->print_len += (fmt->percision - fmt->width);
		}
		
		//
		//printf("width |%d|\n", fmt->width);
		//printf("print_len |%d|\n", fmt->print_len);
		//printf("pads |%d|\n", fmt->pads);
		//printf("sign_space |%d|\n", fmt->sign_space);

		if ((int)ft_strlen(num_c) + fmt->pads + fmt->sign_space > fmt->width)	
			fmt->print_len += fmt->sign_space;
		ft_putstr_fd(num_c, 1);
		if (fmt->negative)
			print_space(fmt, space_count);
	}
	else
		ft_putstr_fd(num_c, 1);
	if (num != 0 || fmt->percision || !fmt->dot)
		free(num_c);
	return (fmt->print_len);
}
