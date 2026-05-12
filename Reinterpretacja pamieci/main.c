#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

void dump(void *memory, size_t size)
{
    printf("uint64_t:\n");
    for (size_t i = 0; i < size / sizeof(uint64_t); i++)
    {
        printf("%lu ", (unsigned long)((uint64_t *)memory)[i]);
    }

    printf("\nuint32_t:\n");
    for (size_t i = 0; i < size / sizeof(uint32_t); i++)
    {
        printf("%u ", ((uint32_t *)memory)[i]);
    }

    printf("\nuint16_t:\n");
    for (size_t i = 0; i < size / sizeof(uint16_t); i++)
    {
        printf("%hu ", ((uint16_t *)memory)[i]);
    }

    printf("\nuint8_t dziesietnie:\n");
    for (size_t i = 0; i < size / sizeof(uint8_t); i++)
    {
        printf("%hhu ", ((uint8_t *)memory)[i]);
    }

    printf("\nuint8_t heksadecymalnie:\n");
    for (size_t i = 0; i < size / sizeof(uint8_t); i++)
    {
        printf("%hhx ", ((uint8_t *)memory)[i]);
    }

    printf("\nfloat:\n");
    for (size_t i = 0; i < size / sizeof(float); i++)
    {
        printf("%f ", ((float *)memory)[i]);
    }

    printf("\ndouble:\n");
    for (size_t i = 0; i < size / sizeof(double); i++)
    {
        printf("%f ", ((double *)memory)[i]);
    }

    printf("\n\n");
}

int main()
{
    int x = 0x11223344;
    double pi = 3.14;

    dump("ala ma kota", 11);
    dump(&x, sizeof(x));
    dump(&pi, sizeof(pi));

    return 0;
}
