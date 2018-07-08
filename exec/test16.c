#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int *nNum = (int*)malloc(sizeof(int)*(n+1));
    for(int i = 0;i<=n;i++)
    {
        nNum[i] = 1;
    }
    nNum[0] = nNum[1] = 0;
    for(int i = 2;i<=n;i++)
    {
        if(!nNum[i])
            continue;
        for(int j = i*i;j<=n;j+=i)
        {
            nNum[j] = 0;
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int z=0;z<=n;z++)
            {
                if(nNum[i]&&nNum[j]&&nNum[z]&&(i+j+z == n))
                {
                    printf("%d %d %d",i,j,z);
                    free(nNum);
                    return 0;
                }
            }
        }
    }
    free(nNum);
    return 0;
}
