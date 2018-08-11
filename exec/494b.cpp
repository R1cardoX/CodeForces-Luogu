#include <iostream>

using namespace std;

int main()
{
    int a,b,x;
    cin>>a>>b>>x;
    int flag = 0;
    if(a>b)
        flag=1;
    while(a>0||b>0||x>0)
    {
        if(x>0)
        {
            if(flag == 1)
            {
                cout<<0;
                a--;
                x--;
                flag = 0;
            }
            else
            {
                cout<<1;
                b--;
                x--;
                flag = 1;
            }
        }
        else
        {
            if(flag == 0)
            {
                while(a)
                {
                    cout<<0;
                    a--;
                }
                while(b)
                {
                    cout<<1;
                    b--;
                } 
                x--;
            }
            else
            {
                while(b)
                {
                    cout<<1;
                    b--;
                } 
                while(a)
                {
                    cout<<0;
                    a--;
                }
                x--;
            }
        }
    }
}
