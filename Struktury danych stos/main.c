#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct stack
{
    int *items;
    int count;
    int capacity;
};

void stkpush(struct stack *p, int value)
{
    if (p->count >= p->capacity)
    {
        int new_capacity = p->capacity * 2;

        if (new_capacity == 0)
        {
            new_capacity = 4;
        }

        int *new_items = realloc(p->items, sizeof(int) * new_capacity);

        if (new_items == NULL)
        {
            printf("Blad realloc\n");
            return;
        }

        p->items = new_items;
        p->capacity = new_capacity;
    }

    p->items[p->count] = value;
    p->count++;
}

int stkpop(struct stack *p)
{
    if (p->count == 0)
    {
        return 0;
    }

    p->count--;
    return p->items[p->count];
}

int stktop(struct stack p)
{
    if (p.count == 0)
    {
        return 0;
    }

    return p.items[p.count - 1];
}

int stklen(struct stack p)
{
    return p.count;
}

void stkfree(struct stack *p)
{
    free(p->items);
    p->items = NULL;
    p->count = 0;
    p->capacity = 0;
}

int main()
{
    struct stack s = {};

    stkpush(&s, 10);
    stkpush(&s, 20);
    stkpush(&s, 30);

    assert(stktop(s) == 30);
    assert(stklen(s) == 3);

    stkpop(&s);

    assert(stktop(s) == 20);
    assert(stklen(s) == 2);

    printf("top: %d\n", stktop(s));
    printf("len: %d\n", stklen(s));

    stkfree(&s);

    return 0;
}
