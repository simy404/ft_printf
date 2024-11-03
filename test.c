int	ft_printf(const char *format, ...);

#include <stdio.h>
#include <stdarg.h>

void check_va_list(int count, ...) {
    va_list args, args_copy;
    va_start(args, count);

    printf("Memory addresses as va_list progresses:\n");

    for (int i = 0; i < count; i++) {
        // va_list'i args_copy'ye kopyalayarak o anki konumunu gözlemleyebiliriz
        va_copy(args_copy, args);

        int value = va_arg(args, int);  // Değeri alıyoruz
        printf("Value of argument %d: %d\n", i + 1, value);

        // args_copy'nin adresini yazdırarak args'in bellekteki ilerleyişini gözlemleyin
        printf("va_list position after argument %d: %p\n", i + 1, (void*)args_copy);

        va_end(args_copy);  // args_copy'yi her seferinde sonlandırmamız gerekiyor
    }

    va_end(args);
}

// void test(int a, int b, int c, char f)
// {
// 	printf("d:%d, p:%p\n", a , &a);
// 	printf("d:%d, p:%p\n", b , &b);
// 	printf("d:%d, p:%p\n", c , &c);
// 		printf("d:%d, p:%p\n", f , &f);


// }
// int main() {
//     int a = 10, b = 20, c = 30, d = 40;
//     printf("d:%d, p:%p\n", a , &a );
// 	printf("d:%d, p:%p\n", b , &b);
// 	printf("d:%d, p:%p\n", c , &c);
// 	printf("d:%d, p:%p\n", d , &d);
// 	printf("TEST FUNC\n");


//     // test(1, 2, 3, 4);
//     //     return 0;

// }

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Heap'ten ardışık bellek blokları ayırıyoruz.
    int *ptr1 = (int *)malloc(sizeof(int));
    int *ptr2 = (int *)malloc(sizeof(int));
    int *ptr3 = (int *)malloc(sizeof(int));
    int *ptr4 = (int *)malloc(sizeof(int));

    // Heap'ten tahsis edilen bellek bloklarının adreslerini yazdırıyoruz.
    printf("Heap allocation addresses:\n");
    printf("ptr1: %p\n", (void*)ptr1);
    printf("ptr2: %p\n", (void*)ptr2);
    printf("ptr3: %p\n", (void*)ptr3);
    printf("ptr4: %p\n", (void*)ptr4);

    // Belleği serbest bırakıyoruz.
    free(ptr1);
    free(ptr2);
    free(ptr3);
    free(ptr4);

    return 0;
}
