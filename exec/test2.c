#include <stdio.h>

int main()
{
    int K;
    scanf("%d",&K);
    double Sn = 0;
    long long n = 0;
    while(K >= Sn)
    {
        n++;
        Sn = Sn + 1.0/n;
    }
    printf("%lld",n);
}
