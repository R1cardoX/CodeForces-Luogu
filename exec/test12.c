#include <stdio.h>
#include <stdlib.h>

long max(long *num,int len)
{
    for(int i=0;i < len;i++)
    {
        if(num[0] < num[i])
        {
            num[0] ^= num[i];
            num[i] ^= num[0];
            num[0] ^= num[i];
        }
    }
    return num[0];
}

int main()
{
    int n,k;
    long num[20];
    scanf("%d %d",&n,&k);
    int *nNum = (int *)malloc(sizeof(int)*5000000);
    int i,j;
    for(i = 0;i<n;i++)
    {
        scanf("%ld",&num[i]);
    }
    long n_max = max(num,n);
    for(i = 0;i<=n_max;i++)
    {
        nNum[i] = 1;
    }
    nNum[0] = nNum[1] = 0;
    for(i = 2;i<=n_max;i++)
    {
        if(!nNum[i])
            continue;
        for(j = i*i;j<=n_max;j += i)
        {
            nNum[j] = 0;
        }
    }
    nNum[1] = 1;
    int nCount = 0;
    for(i = 0;i<n;i++)
    {
        if(nNum[num[i]])
        {
            nCount++;
        }
    }
    int cc = 1;
    for(i = 1;i<nCount;i++)
    {
        cc = cc*(cc+1);
    }
    int kk = 1;
    for(i = 1;i<k;i++)
    {
        kk = kk*(kk+1);
    }
    printf("%d %d\n",cc,kk);
    printf("%d",cc/kk);
    free(nNum);
}
