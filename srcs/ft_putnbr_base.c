/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:46:39 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/15 19:39:44 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	length(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *base, int base_length)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base_length < 2)
		return (0);
	while (base[i] != '\0')
	{	
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base [i] > 126)
			return (0);
		else
			i++;
	}
	return (1);
}

void	ft_putnbr_base(unsigned long nbr, char *base)
{
	int				i;
	unsigned long	base_length;

	i = 0;
	base_length = length(base);
	if (check_base(base, base_length) == 1)
	{
		if (nbr >= base_length)
		{
			ft_putnbr_base(nbr / base_length, base);
			ft_putnbr_base(nbr % base_length, base);
		}
		else
			ft_putchar(base[nbr]);
	}
}
