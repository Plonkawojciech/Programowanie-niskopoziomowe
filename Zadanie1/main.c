#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;
    int w_kole = 0;
    int w_kwadracie = 0;

    printf("Podaj liczbe iteracji: ");
    scanf("%d", &n);

    srand(time(NULL));

    while (n > 0)
    {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;

        if (x * x + y * y <= 1)
        {
            w_kole++;
        }

        w_kwadracie++;
        n--;
    }

    printf("Przyblizenie liczby Pi: %f\n", (4.0 * w_kole) / w_kwadracie);

    return 0;
}
