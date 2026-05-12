#include <stdio.h>

struct vec2
{
    float x;
    float y;
};

struct vec2 vec_add(struct vec2 a, struct vec2 b)
{
    struct vec2 wynik;

    wynik.x = a.x + b.x;
    wynik.y = a.y + b.y;

    return wynik;
}

void vec_move(struct vec2 *target, struct vec2 translation)
{
    target->x = target->x + translation.x;
    target->y = target->y + translation.y;
}

struct vec2 vec_sub(struct vec2 a, struct vec2 b)
{
    struct vec2 wynik;

    wynik.x = a.x - b.x;
    wynik.y = a.y - b.y;

    return wynik;
}

struct vec2 vec_mul(struct vec2 a, float scalar)
{
    struct vec2 wynik;

    wynik.x = a.x * scalar;
    wynik.y = a.y * scalar;

    return wynik;
}

void vec2_print(struct vec2 v)
{
    printf("(%f, %f)\n", v.x, v.y);
}

int main()
{
    struct vec2 a = {2.0, 3.0};
    struct vec2 b = {4.0, 5.0};
    struct vec2 wynik;

    wynik = vec_add(a, b);
    vec2_print(wynik);

    wynik = vec_sub(a, b);
    vec2_print(wynik);

    wynik = vec_mul(a, 2.0);
    vec2_print(wynik);

    vec_move(&a, b);
    vec2_print(a);

    return 0;
}
