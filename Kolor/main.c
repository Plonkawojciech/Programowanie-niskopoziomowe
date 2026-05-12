#include <stdio.h>
#include <stdint.h>

union color
{
    uint32_t value;

    struct
    {
        uint8_t red;
        uint8_t blue;
        uint8_t green;
        uint8_t alpha;
    };
};

union color grayscale(union color c)
{
    uint8_t srednia = (c.red + c.green + c.blue) / 3;

    c.red = srednia;
    c.green = srednia;
    c.blue = srednia;

    return c;
}

void css(union color c)
{
    printf("#%02hhx%02hhx%02hhx%02hhx\n", c.red, c.green, c.blue, c.alpha);
}

int main()
{
    union color c;
    union color szary;

    c.value = 0xffff00ff;

    printf("value: %x\n", c.value);
    printf("red: %hhu\n", c.red);
    printf("green: %hhu\n", c.green);
    printf("blue: %hhu\n", c.blue);
    printf("alpha: %hhu\n", c.alpha);

    css(c);

    szary = grayscale(c);
    css(szary);

    return 0;
}
