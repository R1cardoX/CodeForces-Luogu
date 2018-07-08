#include <stdio.h>
#include <stdlib.h> 
int main()
{
    int n;
    char str[51];
    scanf("%d\n%s",&n,str);
    char *s = (char*)malloc(sizeof(str));
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] + n > 'z')
            s[i] = str[i] + n - 'z' + 'a' - 1;
        else
            s[i] = str[i] + n; 
        i++;
    }
    printf("%s",s);
}
