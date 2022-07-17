/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:52:29 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/16 12:53:18 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	print_s(va_list args)
{
	int		print_length;
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		str = "(null)";
		ft_putstr_fd(str, 1);
		return (6);
	}
	print_length = 0;
	print_length = string_length(str);
	ft_putstr_fd(str, 1);
	va_end(args);
	return (print_length);
}
