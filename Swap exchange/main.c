#include <assert.h>
#include <stddef.h>
#include <stdio.h>

void swap(int *a, int *b);
int exchange(int *value, int new);

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int exchange(int *value, int new)
{
    int old = *value;
    *value = new;
    return old;
}

int main()
{
  int x, y;

  x = 10;
  y = 20;
  swap(&x, &y);
  assert(x == 20);
  assert(y == 10);

  x = 100;
  y = exchange(&x, 200);
  assert(x == 200);
  assert(y == 100);

  // Wypisuje liczby Fibonacciego
  x = 1;
  y = 0;
  for (int i = 0; i < 10; ++i) {
    y = exchange(&x, x + y);
    printf("fib[%d] = %d\n", i, y);
  }
}
