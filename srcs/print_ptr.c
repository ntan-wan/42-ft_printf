/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:17:22 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/15 16:54:10 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	print_ptr(va_list args)
{
	ft_putstr_fd("0x", 1);
	ft_putnbr_base(va_arg(args, unsigned long), "0123456789abcdef");
}
