#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *begin, int *end)
{
    while (begin < end)
    {
        swap(begin, end);
        begin++;
        end--;
    }
}

int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8};

    reverse(nums, nums + 7);

    for (int i = 0; i < 8; i++)
    {
        printf("%d ", nums[i]);
    }

    printf("\n");

    return 0;
}
