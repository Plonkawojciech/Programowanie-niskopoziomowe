#include <stdio.h>
#include <stddef.h>

int* binary_search(int *low, int *high, int target)
{
    while (low <= high)
    {
        int *mid = low + (high - low) / 2;

        if (*mid == target)
        {
            return mid;
        }

        if (*mid < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return NULL;
}

int main()
{
    int xs[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 6;

    int *found = binary_search(xs, xs + 8, target);

    if (found)
    {
        printf("znaleziono: %d\n", *found);
    }
    else
    {
        printf("nie znaleziono\n");
    }

    return 0;
}
