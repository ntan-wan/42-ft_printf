/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:52:29 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/21 08:53:43 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

/*
   Concern <negative>, <percision> and <width> flags only.

   <percision> only = if <percision> is lesser than str_len, number 
   of characters will be printed out up to <percision> only.

   <width> only = if <width> is greater than str_len, 'spaces' will be 
   printed out to fill up the empty slot first, 'characters' will then
   be printed out later.

   <negative> only = 'characters' will be printed out first, then
   'spaces', if any.
   
   Find out the str_len first as this will be compared with <percision>.
   After comparison, we now know how many characters will be printed out,
   i.e either up to <percision> only or the full length of the string.

   If there is <width> and is greater than str_len, we know we need to print
   'spaces' to fill up all the additional slots.

   <negative> flags in simple words, is use to determine the order of
   'spaces' and 'characters'. For example :
   <width> = 'spaces' first, 'characters' next.
   <negative> + <width> = 'characters' first, 'spaces' next.

   If <width> is greater than str_len, we set fmt->print_len = fmt->width as
   number of printable charaters = width (common sense).

   If no flags or <percision> only, we use the last statement to print
   out characters.

   dot_percision_check :
   <dot> only = meaning maximum characters can be printed out is 0.
   <dot + percision> = only n(percision) characters can be printed out.
   If characters is more than <percision>, the extra characters will be trimmed.
*/

void	print_spaces(int space_count)
{
	while (space_count--)
		ft_putchar_fd(' ', 1);
}

void	dot_percision_check(t_fmt *fmt, int str_len)
{
	if (fmt->dot && !fmt->percision)
		fmt->print_len = 0;
	else if (fmt->percision && fmt->percision < str_len)
		fmt->print_len = fmt->percision;
}

void	and_negative_flag_s(t_fmt *fmt, char *str)
{
	int	space_count;

	space_count = fmt->width - fmt->print_len;
	if (fmt->negative)
	{
		write(1, str, fmt->print_len);
		print_spaces(space_count);
	}
	else
	{
		print_spaces(space_count);
		write(1, str, fmt->print_len);
	}
	fmt->print_len = fmt->width;
}

int	print_s(t_fmt *fmt, char *str)
{
	int	str_len;

	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	fmt->print_len = str_len;
	dot_percision_check(fmt, str_len);
	if (fmt->width > str_len)
		and_negative_flag_s(fmt, str);
	else
		write(1, str, fmt->print_len);
	return (fmt->print_len);
}
