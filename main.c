#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include <limits.h>

int main()
{
    int d = INT_MIN;
    int a = ft_printf("%s\n", 0);
    int b = printf("%s\n", 0);
    printf("%d\n",a);
    printf("%d\n",b);

}
