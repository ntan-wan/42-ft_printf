#include <stdio.h>
#include "includes/ft_printf.h"
#include <limits.h>
int main() {
    int precision = 8;
    int biggerPrecision = 16;
    const char *greetings = "Hello world";

    printf("%d\n",printf("|%2.20d|\n", 42000));
    printf("%d\n",printf("|%.20d|\n", 42000));
    printf("%d\n",printf("|%+042d|\n", 42000));
    printf("%d\n",ft_printf("|%042.20d|\n", 42000));
    printf("%d\n",ft_printf("|%.20d|\n", 42000));
    printf("%d\n",ft_printf("|%+042d|\n", 42000));
    //printf("%d\n",ft_printf("|%-.d|\n", 0)); return 0;

/*TEST(27, print(" %-11p %-12p ", INT_MIN, INT_MAX));
	TEST(28, print(" %-13p %-14p ", ULONG_MAX, -ULONG_MAX));*/
}
