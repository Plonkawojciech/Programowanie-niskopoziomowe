#include <stdio.h>
#include "custom_math.h"

int main()
{
    printf("min: %d\n", min(4, 10));
    printf("max: %d\n", max(4, 10));
    printf("clamp: %d\n", clamp(15, 0, 10));
    printf("gcd: %d\n", gcd(48, 18));

    return 0;
}
