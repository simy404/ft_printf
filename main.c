#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include <limits.h>
int main()
{
    int ret;
    long ret2 = LONG_MAX;
    int ret3 = 0;
    ret = ft_printf("Hello, %d, %d!\n", ret2, ret3);
    printf("%d",ret2);
    printf("ret = %d\n", ret);
}

