#include <stdio.h>


int main()
{
    int a[4] = {0};
    scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3]);
    if(a[3] > a[1])
    {
        printf("%d %d",a[2]-a[0],a[3]-a[1]);
    }
    else
    {
        printf("%d %d",a[2]-a[0]-1,a[3]+60-a[1]);
    }

}
