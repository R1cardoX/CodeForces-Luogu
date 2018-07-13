#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int *num = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n+1;i++)
    {
        scanf("%d",&num[i]);
        if(num[i] == 0)
            continue;
        if(i>0 && num[i]>0)
            printf("+");
        if(i == n)
        {
            printf("%d",num[i]);
            continue;
        }
        if(num[i] != 1 && num[i] != -1)
            printf("%d",num[i]);
        else if(num[i] == -1)
            printf("-");
        if((n-i) == 1)
            printf("x");
        else if(n != i)
            printf("x^%d",n-i);
    }    
    free(num);
}
