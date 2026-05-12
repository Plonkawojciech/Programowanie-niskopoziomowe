#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int porownaj(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;

    return x - y;
}

void wypisz_tablice(int tablica[], int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        printf("%d ", tablica[i]);
    }

    printf("\n");
}

int main()
{
    int rozmiar = 10;
    int statyczna[10];
    int *dynamiczna = malloc(sizeof(int) * rozmiar);

    srand(time(NULL));

    for (int i = 0; i < rozmiar; i++)
    {
        statyczna[i] = rand() % 100;
        dynamiczna[i] = rand() % 100;
    }

    printf("Tablica statyczna przed sortowaniem:\n");
    wypisz_tablice(statyczna, rozmiar);

    printf("Tablica dynamiczna przed sortowaniem:\n");
    wypisz_tablice(dynamiczna, rozmiar);

    printf("\nAdres tablicy statycznej: %p\n", statyczna);
    printf("Adres tablicy dynamicznej: %p\n", dynamiczna);

    printf("\nsizeof(statyczna): %lu\n", sizeof(statyczna));
    printf("sizeof(dynamiczna): %lu\n", sizeof(dynamiczna));

    qsort(statyczna, rozmiar, sizeof(int), porownaj);
    qsort(dynamiczna, rozmiar, sizeof(int), porownaj);

    printf("\nTablica statyczna po sortowaniu:\n");
    wypisz_tablice(statyczna, rozmiar);

    printf("Tablica dynamiczna po sortowaniu:\n");
    wypisz_tablice(dynamiczna, rozmiar);

    free(dynamiczna);

    return 0;
}
