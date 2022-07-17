/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:20:25 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/16 11:20:16 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	print_hexa_upper(va_list args)
{
	char	*num_base;
	int	print_length;
	int	hexa;

	hexa = va_arg(args, int);
	print_length = 0;
	num_base = "0123456789ABCDEF";
	print_length = ft_putnbr_base_count(hexa, num_base);
	return (print_length);
}
