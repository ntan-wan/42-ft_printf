/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:02:24 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/15 19:43:50 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	print_hexa_lower(va_list args)
{
	char	*num_base_lower;

	num_base_lower = "0123456789abcdef";
	ft_putnbr_base(va_arg(args, int), num_base_lower);
}
