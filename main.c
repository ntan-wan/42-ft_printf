#include <stdio.h>
#include "includes/ft_printf.h"
#include <limits.h>
int main() {
    int precision = 8;
    int biggerPrecision = 16;
    const char *greetings = "Hello world";

    printf("%d\n",printf("|%d|\n", 0));
    printf("%d\n",ft_printf("|%d|\n", 0));
    //printf("%d\n",ft_printf("|%-.d|\n", 0)); return 0;

/*TEST(27, print(" %-11p %-12p ", INT_MIN, INT_MAX));
	TEST(28, print(" %-13p %-14p ", ULONG_MAX, -ULONG_MAX));*/

//	EST(1, print(" %d ", 0));
//TEST(25, print(" %d ", LONG_MIN));
//	TEST(30, print(" %-1d ", 0));
//		TEST(11, print(" %.2d ", -1));
}
