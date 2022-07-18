/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:28:02 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/18 10:48:54 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

// Print character and return number of character printed.

int	print_c(int c)
{
	int	print_len;

	print_len = 1;
	ft_putchar_fd(c, 1);
	return (print_len);
}
