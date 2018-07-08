#include <stdio.h>

int z_in_zz(int z,int* zz,int c)
{
    for(int i=0;i<c;i++)
    {
        if(zz[i] == z)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int zz[100];
    int n;
    int a[100];
    int nCount = 0;
    int i,j,z,c=0;
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i = 0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j] > a[j+1])
            {
                a[j] ^= a[j+1];
                a[j+1] ^= a[j];
                a[j] ^= a[j+1];
            }
        }
    }
    for(i = 0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            for(z=j+1;z<n;z++)
            {
               if(((a[i] + a[j]) == a[z]))
               {
                    if(!z_in_zz(a[z],zz,c))
                    {
                        zz[c] = a[z];
                        c++;
                        nCount++;
                    }
               } 
            }
        }
    }
    printf("%d",nCount);
    return 0;
}
