#include <stdio.h>
#include <stdlib.h>

#define CV(x) printf("\n"); for(int j =0;j<n;j++) printf("%d %d\n",x[j][0],x[j][1])

void swap(int* a,int* b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}   

int is_larger(const int* pre,int** num)
{
    if((*num)[0] < (*num)[1])
        swap(&(*num)[0],&(*num)[1]);
    if((*num)[0] <= pre[1])
        swap(&(*num)[0],&(*num)[1]);
    return (*num)[1] > pre[1] ?  0: 1;
}

int main()
{
    int n;
    int **arr;
    scanf("%d",&n);
    arr = (int**)malloc(sizeof(int*)*n);
    int i;
    for(i =0;i<n;i++)
        arr[i] = (int*)malloc(sizeof(int)*2);
    for(i =0;i<n;i++)
    {
        for(int j = 0;j<2;j++)
            scanf("%d",&arr[i][j]);
    }
    i=1;
    if(arr[0][0] > arr[0][1])
        swap(&arr[0][0],&arr[0][1]);
    while( i < n)
    {
        if(is_larger(arr[i-1],&arr[i]))
            i++;
        else
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
