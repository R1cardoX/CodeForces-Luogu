#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,s;
    int a,b;
    scanf("%d %d\n%d %d",&n,&s,&a,&b);
    int *x = (int *)malloc(sizeof(int)*n);
    int *y = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
    for(int i = 0;i<n-1;i++)
    {
        for(int j = 0;j<n-i-1;j++)
        {
            if(y[j] > y[j+1])
            {
                y[j] ^= y[j+1];
                y[j+1] ^= y[j];
                y[j] ^= y[j+1];

                x[j] ^= x[j+1];
                x[j+1] ^= x[j];
                x[j] ^= x[j+1];
            }
        }
    }
    int nCount = 0;
    int i = 0;
    for(i = 0;i<n;i++)
    {
        if(x[i]<=(a+b))
        {
            s -= y[i];
            if(s < 0)
                break;
            nCount++;
        }
    }
    printf("%d",nCount);
}
