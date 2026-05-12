#include <stdio.h>
#include <stdlib.h>

struct da
{
    int capacity;
    int count;
    int *items;
};

void da_reserve(struct da *a, int capacity)
{
    if (capacity < a->count)
    {
        a->count = capacity;
    }

    int *nowe = realloc(a->items, sizeof(int) * capacity);

    if (nowe == NULL)
    {
        printf("Blad realloc\n");
        return;
    }

    a->items = nowe;
    a->capacity = capacity;
}

void da_free(struct da *a)
{
    free(a->items);
    a->items = NULL;
    a->count = 0;
    a->capacity = 0;
}

void da_append(struct da *a, int element)
{
    if (a->count >= a->capacity)
    {
        int nowa_pojemnosc = a->capacity * 2;

        if (nowa_pojemnosc == 0)
        {
            nowa_pojemnosc = 16;
        }

        da_reserve(a, nowa_pojemnosc);
    }

    a->items[a->count] = element;
    a->count++;
}

int main()
{
    int capacity = 16;
    int count = 0;
    int *tablica = malloc(sizeof(int) * capacity);

    if (tablica == NULL)
    {
        printf("Blad malloc\n");
        return 1;
    }

    for (int i = 1; i <= 32000; i++)
    {
        if (count >= capacity)
        {
            capacity = capacity * 2;
            int *nowa = realloc(tablica, sizeof(int) * capacity);

            if (nowa == NULL)
            {
                printf("Blad realloc\n");
                free(tablica);
                return 1;
            }

            tablica = nowa;
        }

        tablica[count] = i;
        count++;
    }

    printf("Czesc 1: count = %d, capacity = %d\n", count, capacity);

    free(tablica);

    struct da a;
    a.capacity = 0;
    a.count = 0;
    a.items = NULL;

    for (int i = 1; i <= 32000; i++)
    {
        da_append(&a, i);
    }

    printf("Czesc 2: count = %d, capacity = %d\n", a.count, a.capacity);

    da_free(&a);

    return 0;
}
