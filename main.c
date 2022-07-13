#include <stdio.h>
#include "includes/ft_printf.h"

int main (int ac, char **av)
{
	const char *str;

	ft_printf((const char *)av[1]);
	printf("%s\n",(const char *)av[1]);

	return (0);
}
