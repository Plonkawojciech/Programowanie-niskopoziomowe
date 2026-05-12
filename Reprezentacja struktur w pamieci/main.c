#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

struct dobra
{
    int64_t a;
    int32_t b;
    int32_t c;
    int16_t d;
    int16_t e;
    int8_t f;
    int8_t g;
    int8_t h;
    int8_t i;
};

struct zla
{
    int8_t f;
    int64_t a;
    int8_t g;
    int32_t b;
    int8_t h;
    int32_t c;
    int8_t i;
    int16_t d;
    int16_t e;
};

int main()
{
    printf("Struktura dobra:\n");
    printf("sizeof: %lu\n", sizeof(struct dobra));
    printf("a: %lu\n", offsetof(struct dobra, a));
    printf("b: %lu\n", offsetof(struct dobra, b));
    printf("c: %lu\n", offsetof(struct dobra, c));
    printf("d: %lu\n", offsetof(struct dobra, d));
    printf("e: %lu\n", offsetof(struct dobra, e));
    printf("f: %lu\n", offsetof(struct dobra, f));
    printf("g: %lu\n", offsetof(struct dobra, g));
    printf("h: %lu\n", offsetof(struct dobra, h));
    printf("i: %lu\n", offsetof(struct dobra, i));

    printf("\nStruktura zla:\n");
    printf("sizeof: %lu\n", sizeof(struct zla));
    printf("f: %lu\n", offsetof(struct zla, f));
    printf("a: %lu\n", offsetof(struct zla, a));
    printf("g: %lu\n", offsetof(struct zla, g));
    printf("b: %lu\n", offsetof(struct zla, b));
    printf("h: %lu\n", offsetof(struct zla, h));
    printf("c: %lu\n", offsetof(struct zla, c));
    printf("i: %lu\n", offsetof(struct zla, i));
    printf("d: %lu\n", offsetof(struct zla, d));
    printf("e: %lu\n", offsetof(struct zla, e));

    printf("\nKolejnosc pol ma znaczenie.\n");
    printf("Najmniejszy rozmiar: %lu\n", sizeof(struct dobra));
    printf("Najwiekszy rozmiar: %lu\n", sizeof(struct zla));

    return 0;
}
