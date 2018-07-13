#include <stdio.h>
#include<stdlib.h>

void swap(long long* a,long long *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}


long long Partition(long long* num,long long p,long long r)
{
    long long x = num[r];
    long long i = p-1;
    for(long long j=p;j<r;j++)
    {
        if(num[j]<=x)
        {
            i++;
            swap(&num[i],&num[j]);
        }
    }
    swap(&num[i+1],&num[r]);
    return i+1;
}

void QuickSort(long long* num,long long p,long long r)
{
    long long q;
    if(p<r)
    {
        q = Partition(num,p,r);
        QuickSort(num,p,q-1);
        QuickSort(num,q+1,r);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    long long * a=(long long *)malloc(sizeof(long long)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    QuickSort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%lld",a[i]);
    }

}
