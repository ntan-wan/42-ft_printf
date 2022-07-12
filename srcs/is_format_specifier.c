/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_format_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:22:36 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/12 16:22:37 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_stdio.h"

int	is_format_specifier(const char *str)
{
	size_t	i;
	size_t	j;
	char	*conver;

	i = 0;
	j = 0;
	conver = "cspdiuxX%";
	while (str[i])
	{
		if (str[i] == '%')
		{
			while (conver[j])
			{
				if (str[i + 1] == conver[j])
					return (1);
				j++;
			}
		}
		i++;
	}
	return (0);
}
