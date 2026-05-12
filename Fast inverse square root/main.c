#include <stdio.h>
#include <math.h>
#include <stdint.h>

float Q_rsqrt(float number)
{
    union
    {
        float f;
        int32_t i;
    } conv;

    float x2;
    float y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;

    conv.f = y;
    conv.i = 0x5f3759df - (conv.i >> 1);
    y = conv.f;

    y = y * (threehalfs - (x2 * y * y));

    return y;
}

int main()
{
    float liczby[] = {1.0F, 2.0F, 4.0F, 9.0F, 16.0F, 25.0F, 100.0F};

    for (int i = 0; i < 7; i++)
    {
        float n = liczby[i];
        float szybkie = Q_rsqrt(n);
        float normalne = 1.0F / sqrtf(n);
        float roznica = szybkie - normalne;

        if (roznica < 0)
        {
            roznica = -roznica;
        }

        printf("n = %f\n", n);
        printf("Q_rsqrt: %f\n", szybkie);
        printf("1 / sqrt: %f\n", normalne);
        printf("roznica: %f\n\n", roznica);
    }

    return 0;
}
