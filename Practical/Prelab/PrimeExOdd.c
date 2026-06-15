#include<stdio.h>
#include <time.h>
void main()
{
    int n,i,fact,j;
    clock_t t; 
    double time_taken;
    printf("Enter the Number");
    scanf("%d",&n);
    printf("Prime Numbers are: \n");
    
    t = clock(); 
    for(i=1; i<=n; i=i+2)
    {
        fact=0;
        for(j=1; j<=n; j++)
        {
            if(i%j==0)
                fact++;
        }
        if(fact==2)
            printf("%d " ,i);
    } 
    
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n\nTotal Time->%f",time_taken);
  
}
