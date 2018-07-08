#include <stdio.h>

int main()
{
    int n,x,i,nCount = 0;
    scanf("%d %d",&n,&x);
    int c = 1;
    for(i=1;i<=n;i++)
    {
        while(i/c)
        {
            if(((i%(10*c))/c ) == x)
            {
                nCount++;
            }
            c *= 10;
        }
        c = 1;
    }
    printf("%d",nCount);
    return 0;
}   





