#include <stdio.h>
#include "includes/ft_printf.h"

int main() {
    int precision = 8;
    int biggerPrecision = 16;
    const char *greetings = "Hello world";

    printf("%d\n",printf("|%-10s|\n", "12345"));
    printf("%d\n",ft_printf("|%10.3s|\n", "12345"));
    return 0;
}
