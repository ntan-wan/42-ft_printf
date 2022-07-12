/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:41:18 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/12 17:42:03 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_stdio.h"
#include "libft/libft.h"

int	ft_printf(const char *str, ...)
{	
	if (is_format_specifier(str))
	{
		return (1);
	}	
	else
		ft_putstr_fd((char *)str, 1);
	return (0);
}
