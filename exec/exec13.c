#include <stdio.h>


int get_all_num(int n)
{
    int c = 10;
    int count = 0;
    int num[10] = {6,2,5,5,4,5,6,3,7,6};
    while(n/c)
    {
        count +=  num[(n/c)%(10*c)];
        c *= 10;
    }
    count += num[n%10];
    return count;
}


int main()
{
    int n;
    int nCount=0;
    scanf("%d",&n);
    for(int i=0;i<=1111;i++)
    {
        for(int j=0;j<=1111;j++)
        {
            if((get_all_num(i)+get_all_num(j)+get_all_num(i+j)==(n-4)))
            {
                nCount++;
            }
        }
    }
    printf("%d",nCount);
    return 0;
}
