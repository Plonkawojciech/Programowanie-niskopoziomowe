#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int global_zero = 0;
int global_value = 0x12345678;

void recurse(int n)
{
    static int static_value = 0x87654321;

    unsigned char local_array[1024];
    unsigned char *dynamic_array = malloc(1024);

    for (int i = 0; i < 1024; i++)
    {
        local_array[i] = i;
        dynamic_array[i] = i;
    }

    printf("wywolanie: %d\n", n);
    printf("adres funkcji recurse: %p\n", recurse);
    printf("adres local_array: %p\n", local_array);
    printf("adres dynamic_array: %p\n", dynamic_array);
    printf("adres global_zero: %p\n", &global_zero);
    printf("adres global_value: %p\n", &global_value);
    printf("adres static_value: %p\n", &static_value);
    printf("\n");

    Sleep(15000);

    recurse(n + 1);
}

int main()
{
    recurse(1);

    return 0;
}
