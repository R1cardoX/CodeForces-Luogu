#include <stdio.h>

int main()
{
    double m;
    double h = 2;
    double c = 0;
    int n = 0;
    scanf("%lf",&m);
    while(m > c)
    {
        n++;
        c += h;
        h *= 0.98;
    }
    printf("%d",n);
}
