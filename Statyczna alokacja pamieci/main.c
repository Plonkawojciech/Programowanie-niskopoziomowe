#include <stdio.h>

int globalna1 = 10;
int globalna2 = 20;

void funkcja1()
{
    int lokalna1 = 30;
    int lokalna2 = 40;

    static int statyczna1 = 50;
    static int statyczna2 = 60;

    char znak1 = 'A';
    char znak2 = 'B';

    printf("adres lokalna1: %p\n", &lokalna1);
    printf("adres lokalna2: %p\n", &lokalna2);
    printf("adres statyczna1: %p\n", &statyczna1);
    printf("adres statyczna2: %p\n", &statyczna2);
    printf("adres znak1: %p\n", &znak1);
    printf("adres znak2: %p\n", &znak2);
}

void funkcja2()
{
    printf("adres funkcja2: %p\n", funkcja2);
}

int main()
{
    printf("adres globalna1: %p\n", &globalna1);
    printf("adres globalna2: %p\n", &globalna2);
    printf("adres funkcja1: %p\n", funkcja1);
    printf("adres funkcja2: %p\n", funkcja2);

    funkcja1();
    funkcja2();

    return 0;
}
