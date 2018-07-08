#include <stdio.h>
#include <stdlib.h>

#define MALLOC(X)    int *X = (int*)malloc(sizeof(int)*n);
#define SC(X)        scanf("%d %d %d %d",&a[X],&b[X],&g[X],&k[X])
int main()
{
    int n,x,y;
    int out = -1;
    scanf("%d",&n);
    MALLOC(a);
    MALLOC(b);
    MALLOC(g);
    MALLOC(k);
    for(int i=0;i<n;i++)
    {
        SC(i);
    } 
    scanf("%d %d",&x,&y);
    for(int i=0;i<n;i++)
    {
        if(x>=a[i] && x<=(g[i]+a[i]) && y>=b[i] && y<=(k[i]+b[i]))
            out = i+1;
    }
    printf("%d",out);
}
