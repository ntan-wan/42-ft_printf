#include <stdio.h>
#include "includes/ft_printf.h"

int main (int ac, char **av)
{
	const char *str;

	ft_printf((const char *)av[1], "OK!");
	//printf("%0+ydrf\n",45.234);

	return (0);
}
