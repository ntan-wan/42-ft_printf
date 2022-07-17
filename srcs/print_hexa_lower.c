/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:02:24 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/17 14:54:28 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	print_hexa_lower(va_list args)
{
	char	*num_base_lower;
	int	print_length;
	int	hexa;

	hexa = va_arg(args, unsigned int);
	print_length = 0;
	num_base_lower = "0123456789abcdef";
	print_length = ft_putnbr_base_count(hexa, num_base_lower);
	return (print_length);
}
