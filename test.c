#include <stdio.h>
#include "includes/ft_stdio.h"

int	ft_printf(const char *str, ...);

int main (int ac, char **av)
{
	const char *str;

	str = "dfddf";
	//printf("%S\n", str); 
	if (is_format_specifier((const char *)av[1]))
		printf("is format specifier\n");
	else
		printf("not format specifier");
	return (0);
}
