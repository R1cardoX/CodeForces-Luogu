#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *a = (char*)malloc(sizeof(char)*14);
    scanf("%s",a);
    a[13] = '\0';
    int nNum = 0;
    int c=1;
    for(int i=0;i<11;i++)
    {
        if(a[i] == '-')
        {
            continue;
        }
        nNum += (a[i]-'0')*c;
        c++;
    }
    if(nNum%11 + '0' == a[12] || (a[12] == 'X' && nNum%11==10))
    {
        printf("Right");
    }
    else
    {
        if(nNum%11 == 10)
            a[12] = 'X';
        else
            a[12] = nNum%11+'0';
        printf("%s",a);
    }
    return 0;
}
