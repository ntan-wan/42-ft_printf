/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:02:15 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/15 17:02:16 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	check_flags(const char *str, size_t *ptr_i, t_fmt *fmt)
{
	size_t	next_c;

	next_c = (*ptr_i) + 1;
	while (str[next_c] && !(ft_strchr("cspdiuxX%", str[next_c])))
	{
		if (flag_check_bonus(str[next_c]))
			fmt_update_bonus(str[next_c], fmt);
		else
		{
			fmt_reset(fmt);
			break ;
		}
		(*ptr_i)++;
	}
}
