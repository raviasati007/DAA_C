#include <stdio.h>
#include <time.h>

int main()
{
    int n, i, j;
    clock_t start, end;
    double cpu_time_used;

    printf("Program To Find Prime Numbers Up To n\n");
    printf("Enter The Number To Find Prime Numbers: ");
    scanf("%d", &n);

    // Start measuring time
    start = clock();

    int prime[n + 1];

    for (i = 2; i <= n; i++)
    {
        prime[i] = i;
    }

    i = 2;
    while ((i * i) <= n)
    {
        if (prime[i] != 0)
        {
            for (j = 2; j < n; j++)
            {
                if (prime[i] * j > n)
                {
                    break;
                }
                else
                {
                    prime[prime[i] * j] = 0;
                }
            }
        }
        i++;
    }

    printf("Prime numbers up to %d are:\n", n);
    for (i = 2; i <= n; i++)
    {
        if (prime[i] != 0)
        {
            printf("%d ", prime[i]);
        }
    }

    // End measuring time
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nExecution Time: %f seconds\n", cpu_time_used);

    return 0;
}

