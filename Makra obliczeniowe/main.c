#include <stdio.h>

#define square(x) ((x) * (x))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define clamp(x, min, max) ((x) > (max) ? (max) : ((x) < (min) ? (min) : (x)))

int main()
{
    int x = 4;
    int y = 10;
    int i;

    printf("Dobre uzycie:\n");
    printf("square(4) = %d\n", square(4));
    printf("min(4, 10) = %d\n", min(4, 10));
    printf("max(4, 10) = %d\n", max(4, 10));
    printf("clamp(15, 0, 10) = %d\n", clamp(15, 0, 10));

    printf("\nZle uzycie:\n");

    i = 2;
    printf("square(i++) = %d\n", square(i++));
    printf("i = %d\n", i);

    i = 2;
    printf("min(i++, 10) = %d\n", min(i++, 10));
    printf("i = %d\n", i);

    i = 2;
    printf("max(i++, 10) = %d\n", max(i++, 10));
    printf("i = %d\n", i);

    i = 15;
    printf("clamp(i++, 0, 10) = %d\n", clamp(i++, 0, 10));
    printf("i = %d\n", i);

    printf("square(x + y) = %d\n", square(x + y));
    printf("square(x) / square(y) = %d\n", square(x) / square(y));

    return 0;
}
