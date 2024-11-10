// #include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int test(int a , ...)
{
	va_list args;
	va_start(args, a);
	return a;
}

int main()
{
	int a = 122131232133;
	PRINT_ADDRESS(a);
	ft_printf("%p test sa\n" , &a);
	printf("%p st sa\n", &a);
}
