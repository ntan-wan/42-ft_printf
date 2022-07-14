/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_update_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:33:57 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/14 15:38:17 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	fmt_update_bonus(char c, t_fmt *fmt)
{
	if (c == '-')
		fmt->negative = 1;
	else if (c == '0')
		fmt->zero = 1;
	else if (c == '.')
		fmt->dot = 1;
	else if (c == '#')
		fmt->hash = 1;
	else if (c == ' ')
		fmt->space = 1;
	else if (c == '+')
		fmt->plus = 1;
}
