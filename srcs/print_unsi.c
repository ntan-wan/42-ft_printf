/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:59:45 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/20 10:59:53 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

// Created ft_num_len to count number of digits in order to allocate appropriate
// memory to it.

// Created uitoa instead of using itoa because itoa does not accept
// unsgined int.

// uitoa starts placing character from the end of the 'array' first, gradually
// moving to the start of the 'array'. "% 10" is used to get the remainder,
// i.e, get the last digit of the number first.

int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len++;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	if (n == 0)
		num[0] = '0';
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (num);
}

void	print_prefix_unsi(t_fmt *fmt, unsigned int unsi_num)
{
	int		unsi_num_len;
	int		space_count;

	unsi_num_len = ft_num_len( unsi_num);
	if (fmt->space && !fmt->plus)
		fmt->print_len += write(1, " ", 1);
	if (fmt->plus)
		fmt->print_len += write(1, "+", 1);
	if (fmt->percision > unsi_num_len)
	{
		space_count = fmt->percision - unsi_num_len;
		while (space_count--)
			fmt->print_len += write(1, "0", 1);
	}
}

int	print_unsi(t_fmt *fmt, unsigned int unsi_num)
{
	char	*unsi_num_c;
	int		space_count;
	
	print_prefix_unsi(fmt, unsi_num);
	unsi_num_c = ft_uitoa(unsi_num);
	fmt->print_len += ft_strlen(unsi_num_c);
	if (fmt->width > fmt->print_len)
	{
		space_count = fmt->width - fmt->print_len;
		fmt->print_len = fmt->width;
		if (fmt->negative)
		{
			ft_putstr_fd(unsi_num_c, 1);
			print_space(fmt, space_count);
		}
		else
		{
			print_space(fmt, space_count);
			ft_putstr_fd(unsi_num_c, 1);
		}
	}
	else
		ft_putstr_fd(unsi_num_c, 1);
	free(unsi_num_c);
	return (fmt->print_len);
}
