#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
    string str;
    int sign = 0;
    cin>>str;
    stack<char> sp;
    string::iterator ite = str.begin();
    while( ite != str.end())
    {
        if(*ite == '-')
        {
            ite++;
            sign = 1;
        }
        sp.push(*ite);
        ite++;
    }    
    int flag = 0;
    if(sign)
        cout<<"-";
    while(!sp.empty())
    {
        if(flag == 0 && sp.top() == '0')
            sp.pop();
        else
        {
            flag = 1;
            cout<<sp.top();
            sp.pop();
        }
    }
    return 0;
}
