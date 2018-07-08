#include <iostream>
#include <list>
#include <vector>
#include <string.h>
using namespace std;


class Func
{
public:
    long long search[35][35][35];
public:
    Func()
    {
        bzero(search,sizeof(search));    
    }
public:
    long long w(long long a,long long b,long long c)
    {
        long long cccc;
        if((a<30) && (b<30) && (c<30) && (a>0) && (b>0) && (c>0))
        {
            if(search[a][b][c] != 0)
            {
                cout<<a<<" "<<b<<" "<<c<<endl;
                return search[a][b][c];
            }
        }
        if( (a<=0) || (b<=0) || (c<=0))
        {
            return 1;
        }
        else if((a>20) || (b>20) || (c>20))
        {
            cccc = w(20,20,20);
            if((a<30) && (b<30) && (c<30) && (a>0) && (b>0) && (c>0))
                search[a][b][c] = cccc;
            return cccc;
        }
        else if((a<b) && (b<c))
        {
            cccc =  w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
            if((a<30) && (b<30) && (c<30) && (a>0) && (b>0) && (c>0))
                search[a][b][c] = cccc;
            return cccc;
        }
        else
        {
            cccc = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
            if((a<30) && (b<30) && (c<30) && (a>0) && (b>0) && (c>0))
                search[a][b][c] = cccc;
            return cccc;
        }
    }
};

int main()
{
    Func fun;
    vector<long long> var;
    list< vector<long long> > in;
    long long a,b,c;
    while(true)
    {
        cin>>a;
        cin>>b;
        cin>>c;
        if(a == -1 && b == -1 && c == -1)
            break;
        var.push_back(a);
        var.push_back(b);
        var.push_back(c);
        in.push_back(var);
        var.clear();
    }
    for(auto num : in)
    {
        cout<<"w("<<num[0]<<", "<<num[1]<<", "<<num[2]<<") = "<<fun.w(num[0],num[1],num[2])<<endl;
    }
}
