/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:41:18 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/07/15 10:37:28 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
//
#include <stdio.h>

//
void  print(void *content)
{
	printf("%s\n", (char *)content);
}
int	ft_printf(const char *str, ...)
{	

	t_list	*head;
	char	c;
	size_t	i;
	
	i = 0;
	head = NULL;
	while (str[i] != '0')
	{	
		//c = str[i];
		ft_lstadd_back(&head, ft_lstnew(str));
		i++;
	}
	ft_lstiter(head, &print);

	return (0);











	/*size_t	i;
	t_fmt	fmt;

	i = 0;
	fmt_init(&fmt);
	while (str[i])
	{
		if (str[i++] == '%')
		{
			//need reset fmt here for next iteration
			while (str[i] && !(ft_strchr("cspdiuxX%", str[i])))
			{
				if (flag_check_bonus(str[i]))
					fmt_update_bonus(str[i], &fmt);
				else
				{
					fmt_reset(&fmt);
					break ;
				}
				i++;
			}
			fmt_update(str[i], &fmt);
			fmt_operation(&fmt);
		}
		i++;
	}
	//
	printf("char = %d\n", fmt.c);
	printf("str = %d\n", fmt.str);
	printf("ptr = %d\n", fmt.ptr);
	printf("decimal = %d\n", fmt.decimal);
	printf("integer = %d\n", fmt.integer);
	printf("uni = %d\n", fmt.unsi);
	printf("hexa_low = %d\n", fmt.hexa_lower);
	printf("hexa_upper = %d\n", fmt.hexa_upper);
	printf("percent = %d\n", fmt.percent);
	printf("negative = %d\n", fmt.negative);
	printf("zero = %d\n", fmt.zero);
	printf("dot = %d\n", fmt.dot);
	printf("hash = %d\n", fmt.hash);
	printf("space = %d\n", fmt.space);
	printf("plus = %d\n", fmt.plus);
	return (0);*/
}
