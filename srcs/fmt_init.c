/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 22:13:08 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/14 12:49:39 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	fmt_init(t_fmt *fmt)
{
	fmt->c = 0;
	fmt->str = 0;
	fmt->ptr = 0;
	fmt->decimal = 0;
	fmt->integer = 0;
	fmt->unsi = 0;
	fmt->hexa_lower = 0;
	fmt->hexa_upper = 0;
	fmt->percent = 0;
	fmt->negative = 0;
	fmt->zero = 0;
	fmt->dot = 0;
	fmt->hash = 0;
	fmt->space = 0;
	fmt->plus = 0;
}
