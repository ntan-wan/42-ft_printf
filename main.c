#include <stdio.h>
#include "includes/ft_printf.h"

int main() {
    int precision = 8;
    int biggerPrecision = 16;
    const char *greetings = "Hello world";

    printf("%d\n",printf("|%-c|\n", 'a'));
    printf("%d\n",ft_printf("|%-c|\n", 'a'));
    return 0;
}
