#include <stdio.h>

int main()
{
    int a[10];
    int high;
    int i;
    int nCount = 0;
    for(i = 0;i<10;i++)
    {
        scanf("%d ",&a[i]);
    }
    scanf("%d",&high);
    for(i=0;i<10;i++)
    {
        if(high >= a[i])
        {
            nCount++;
        }
        else
        {
            if((high+30) >= a[i])
            {
                nCount++;
            }
        }
    }
    printf("%d",nCount);
}
