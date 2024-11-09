#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
int main()
{
// 	  int custom_ret, original_ret;
// // 1. F_DECIMAL 'd'
//     custom_ret = ft_printf("Custom: %d\n", 42);
//     original_ret = printf("Original: %d\n", 42);
//     printf("Return Values: Custom = %d, Original = %d\n\n", custom_ret, original_ret);

//     //2. F_UNSIGNED 'u'
//     custom_ret = ft_printf("Custom: %u\n", UINT_MAX);
//     original_ret = printf("Original: %u\n", UINT_MAX);
//     printf("Return Values: Custom = %d, Original = %d\n\n", custom_ret, original_ret);

//     // 3. F_HEX_UPPER 'X'
//     custom_ret = ft_printf("Custom: %X\n", -4294967297);
//     original_ret = printf("Original: %X\n", -4294967297);
//     printf("Return Values: Custom = %d, Original = %d\n\n", custom_ret, original_ret);

//     // 4. F_HEX_LOWER 'x'
//     custom_ret = ft_printf("Custom: %x\n", 0);
//     original_ret = printf("Original: %x\n", 0);
//     printf("Return Values: Custom = %d, Original = %d\n\n", custom_ret, original_ret);

//     // 5. F_PERCENT '%'
//     custom_ret = ft_printf("Custom: %%\n");
//     original_ret = printf("Original: %%\n");
//     printf("Return Values: Custom = %d, Original = %d\n\n", custom_ret, original_ret);

//     // 6. F_CHAR 'c'
//     custom_ret = ft_printf("Custom: %c\n", 'A');
//     original_ret = printf("Original: %c\n", 'A');
//     printf("Return Values: Custom = %d, Original = %d\n\n", custom_ret, original_ret);

//     // 7. F_STRING 's'
//     custom_ret = ft_printf("Custom: %s\n", "Hello, World!");
//     original_ret = printf("Original: %s\n", "Hello, World!");
//     printf("Return Values: Custom = %d, Original = %d\n\n", custom_ret, original_ret);

//     // 8. F_POINTER 'p'
//     int num = 42;
//     custom_ret = ft_printf("Custom: %p\n", (void *)0);
//     original_ret = printf("Original: %p\n", (void *)0);
//     printf("Return Values: Custom = %d, Original = %d\n\n", custom_ret, original_ret);

//     // 9. F_INT 'i'
//     custom_ret = ft_printf("Custom: %i\n", -42);
//     original_ret = printf("Original: %i\n", -42);
//     printf("Return Values: Custom = %d, Original = %d\n\n", custom_ret, original_ret);
char b = 'a';
    ft_printf("%d\n",ft_printf("%d",INT_MIN));
    printf("\n");
    printf("\n");
    printf("\n");
    printf("%d\n",printf("%d",INT_MIN));
    long c = INT_MIN * -1;
    printf("%ld",c);
}