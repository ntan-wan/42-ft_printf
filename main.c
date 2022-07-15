#include <stdio.h>
#include "includes/ft_printf.h"

int main (int ac, char **av)
{
	char c;

	c = 'a';
	ft_printf((const char *)av[1], (const char *)av[2], (const char *)av[3], (const char *)av[4]);
	printf("\n");
	printf((const char *)av[1], (const char *)av[2], (const char *)av[3], (const char *)av[4]);
	return (0);
}
