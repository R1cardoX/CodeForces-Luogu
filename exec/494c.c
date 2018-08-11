#include <stdio.h>
#include <stdlib.h>


double get_best(int* arr,int n,int k)
{
    double m_aver = 0;
    int i;
    for(i=0;i<n-k+1;i++)
    {
        double num = 0;
        for(int j=i;j<i+k;j++)
            num += arr[j];
        num /= (double)k;
        if(m_aver < num) m_aver = num;
    }
    return m_aver;
}

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int* arr = (int*)malloc(sizeof(int)*n);
    double average = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        average += arr[i];
    }

    average /= (double)n;
    double best = get_best(arr,n,k);
    printf("%0.15f",best > average ? best : average);
}
