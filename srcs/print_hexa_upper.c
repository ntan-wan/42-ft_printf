/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:20:25 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/15 19:44:28 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	print_hexa_upper(va_list args)
{
	char	*num_base;

	num_base = "0123456789ABCDEF";
	ft_putnbr_base(va_arg(args, int), num_base);
}
