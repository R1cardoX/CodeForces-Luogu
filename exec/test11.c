#include <stdio.h>


long nNum[1000] = {0};
long fun(int n)
{
    long nCount = 1;
    if(nNum[n] != 0)
        nCount += nNum[n];
    else
    {
        for(int i = n/2;i>0;i--)
        {
            if(nNum[i] != 0)
                nCount += nNum[i];
            else
                nCount += fun(i);
        }
        nNum[n] = nCount;
    }
    return nCount;
}


int main()
{
    int n;
    scanf("%d",&n);
    printf("%ld",fun(n));
}
