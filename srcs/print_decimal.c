/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:08:06 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/18 00:45:01 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	print_decimal(int num)
{
	char	*num_c;
	int		print_len;

	print_len = 0;
	num_c = ft_itoa(num);
	print_len += ft_strlen(num_c);
	ft_putstr_fd(num_c, 1);
	free(num_c);
	return (print_len);
}
