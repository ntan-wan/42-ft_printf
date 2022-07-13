#include <stdio.h>
#include "ft_printf.h"

int	ft_printf(const char *str, ...);

int main (int ac, char **av)
{
	const char *str;

	ft_printf((const char *)av[1]);

	return (0);
}
