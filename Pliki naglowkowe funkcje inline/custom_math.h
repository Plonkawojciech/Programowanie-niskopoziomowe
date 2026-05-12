#ifndef CUSTOM_MATH_H
#define CUSTOM_MATH_H

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define clamp(x, min, max) ((x) > (max) ? (max) : ((x) < (min) ? (min) : (x)))

static inline int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

#endif
