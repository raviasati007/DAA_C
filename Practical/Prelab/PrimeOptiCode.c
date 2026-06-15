#include<stdio.h>
#include<time.h>
int main()
{
    clock_t start,end;
    double cpu_time_used;
    unsigned long long int i, prime, n;
    start = clock();
    unsigned long long int pr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,71,73,79,83,89,97};
    
    for(i = 0;i< 24;i++)
    {
        printf("%llu ",pr[i]);
    }
    for(i = 101;i<100000;i++)
    {
        prime =1;
    for ( n = 0; n < 24; n++)
        {
        if(i%pr[n] == 0)
            {
                prime =0;
                break;
            }
        }
        if(prime)
        {
            printf("%llu ",i);
        }
    }
    end = clock();
    cpu_time_used = ((double)(end -start))/CLOCKS_PER_SEC;
    printf("\n\n%f secs\n\n",cpu_time_used);
    return 0;
}

