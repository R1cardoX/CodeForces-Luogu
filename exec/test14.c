#include <stdio.h>
#include <stdlib.h>

int fun(long long n)
{
    int flag = 1;
    long long c =1;
    while(n/(c*10))
    {
        c *= 10;
    }
    while(c)
    {
        if((n/c) != (n%10))
            flag = 0;
        n = (n%c)/10;
        c = c/100;
    }
    return flag;
}

int main()
{
    long long a,b;
    scanf("%lld %lld",&a,&b);
    int *nNum = (int*)malloc(sizeof(int)*(b+1));
    for(long long i = 0;i<=b;i++)
    {
        nNum[i] = 1;
    }
    nNum[0] = nNum[1] = 0;
    for(long long i = 2;i<=b;i++)
    {
        if(!nNum[i])
            continue;
        for(long long j = i*i;j<=b;j+=i)
        {
            nNum[j] = 0;
        }
    }
    for(long long i=a;i<=b;i++)
    {
        if(nNum[i])
            if(fun(i))
                printf("%lld\n",i);
    }
    free(nNum);
    return 0;
}
