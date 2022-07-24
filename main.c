#include <stdio.h>
#include "includes/ft_printf.h"
#include <limits.h>
int main() {
    int precision = 8;
    int biggerPrecision = 16;
    const char *greetings = "Hello world";

    //printf("%d\n",ft_printf("|%-.d|\n", 0)); return 0;

/*TEST(27, print(" %-11p %-12p ", INT_MIN, INT_MAX));
	TEST(28, print(" %-13p %-14p ", ULONG_MAX, -ULONG_MAX));*/

//	EST(1, print(" %d ", 0));
//TEST(25, print(" %d ", LONG_MIN));
//	TEST(30, print(" %-1d ", 0));
//		TEST(11, print(" %.2d ", -1));
//printf("%d\n",printf("|%-4.5d%d%4d%-10d-d5%-.3d|\n", 3, 4, 5, 6, 7));
//printf("%d\n",ft_printf("|%-4.5d%d%4d%-10d-d5%-.3d|\n", 3, 4, 5, 6, 7));
//rintf("%d\n",printf("|%01.0d|\n", -4));
//printf("%d\n",ft_printf("|%01.0d|\n", -4));
//printf("%d\n",printf("|%-15.5d|\n", 5000));
//printf("%d\n",ft_printf("|%-15.5d|\n", 5000));
// str_len less than width and percision && percision more than width 
// pads + print_len + sign+spacejJm

printf("%d\n", ft_printf("|%01.2d|\n", -4));
printf("%d\n", printf("|%01.2d|\n", -4));
}
