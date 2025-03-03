#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int i;
    int n = 500; // Number of random numbers to generate
    int range_min = 0; // Minimum value for random numbers
    int range_max = 1000; // Maximum value for random numbers

    // Seed the random number generator
    srand(time(NULL));

    // Generate and print 500 random numbers
    for (i = 0; i < n; i++)
    {
        int random_num = range_min + rand() % (range_max - range_min + 1);
        printf("%d ", random_num);
    }

    printf("\n");
    return 0;
}