/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:59:45 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/18 00:20:45 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

// Created ft_num_len to count number of digits in order to allocate appropriate
// memory to it.

// Created uitoa instead of using itoa because itoa does not accept
// unsgined int.

int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len++;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	if (n == 0)
		num[0] = '0';
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (num);
}

int	print_unsi(unsigned int unsi_num)
{
	char		*unsi_num_c;
	int			print_len;

	print_len = 0;
	unsi_num_c = ft_uitoa(unsi_num);
	print_len += ft_num_len(unsi_num);
	ft_putstr_fd(unsi_num_c, 1);
	free(unsi_num_c);
	return (print_len);
}
