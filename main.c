#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include <limits.h>

int main()
{
    int d = INT_MIN;
    int a = ft_printf("%x\n", d);
    int b = printf("%x\n", d);
    printf("%d\n", a);
    printf("%d\n", b);
}
