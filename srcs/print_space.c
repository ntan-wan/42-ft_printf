/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:54:25 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/19 14:59:01 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	print_space(t_fmt *fmt, int space_count)
{
	char	space;

	space = ' ';
	if (fmt->zero)
		space = '0';
	while (space_count--)
		ft_putchar_fd(space, 1);
}
