#include <stdio.h>

int main()
{
    long long a,b,n,i = 1,j =1;
    scanf("%lld",&n);
    while(n > i)
    {
        j++;
        i+=j;
    }
    if(j%2)
    {
        a = i-n+1;
        b = n+j-i;
    }
    else
    {
        a = j+n-i;
        b = i-n+1;
    }
    if(n != 1)
        printf("%lld/%lld",a,b);
    else
        printf("1/1");
}

