#include <stdio.h>

void recurse(int n)
{
    int zmienna = 0;

    if (n <= 0)
    {
        return;
    }

    printf("n = %d, adres zmiennej = %p\n", n, &zmienna);

    recurse(n - 1);
}

int main()
{
    recurse(10);

    printf("\nAdresy zmiennych lokalnych zmieniaja sie malejaco.\n");
    printf("U mnie jedno wywolanie zajmuje okolo 48 bajtow.\n");

    return 0;
}
