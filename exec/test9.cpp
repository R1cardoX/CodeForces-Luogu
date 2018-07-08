#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
    string str;
    string s;
    cin>>str;  
    int flag = 0;  
    int pre = 0;
    stack<char> sp;
    string::iterator ite = str.begin();
    if(str.length() == 1)
    {
        s = str;
        cout<<s<<endl;
        return 0;
    }
    while(1)
    {
        if(ite == str.end() && pre == 0)
        {
            if(sp.size() == 1)
            {
                s += sp.top();
                sp.pop();
            }
            while(!sp.empty())
            {
                if(sp.top() == '0' && flag ==0)
                    sp.pop();
                else
                {
                    flag = 1;
                    s += sp.top();
                    sp.pop(); 
                }
            }     
            break;
        }
        else if(ite == str.end() && pre == 1)
        {
            while(!sp.empty())
            {
                s += sp.top();
                sp.pop();
            }
            break;
        }
        if(*ite >= '0' && *ite <= '9' && pre == 0)
        {
            sp.push(*ite);
            ite++;
            pre = 0;
        }
        else if(*ite == '%' || (*ite == '/' && pre == 0))
        {
            if(sp.size() == 1)
            {
                s += sp.top();
                sp.pop();
            }
            while(!sp.empty())
            {
                if(sp.top() == '0' && flag ==0)
                    sp.pop();
                else
                {
                    flag = 1;
                    s += sp.top();
                    sp.pop(); 
                }
            }     
            flag=0;
            s += *ite;
            ite++;
        }
        else if(*ite == '/' && pre == 1)
        {
            pre = 0;
            while(!sp.empty())
            {
                s += sp.top();
                sp.pop();
            }
        }
        else if(*ite >= '0' && *ite <= '9' && pre == 1)
        {
            if(flag == 0 && *ite == '0')
                ite++;
            else
            {
                flag = 1;
                sp.push(*ite);
                ite++;
            }
        }
        else if(*ite == '.')
        {
            pre = 1;
            if(sp.size() == 1)
            {
                s += sp.top();
                sp.pop();
            }
            while(!sp.empty())
            {
                if(sp.top() == '0' && flag ==0)
                    sp.pop();
                else
                {
                    flag = 1;
                    s += sp.top();
                    sp.pop(); 
                }
            }     
            flag=0;
            s += *ite;
            ite++;
        } 
    }
    if(s[s.length()-1] == '.')
    {
        s += '0';
    }
    string::size_type i = s.find('.');
    if(i != s.npos)
    {
        if(s[i+1] == '/')
            s.insert((int)i+1,"0");
    }
    if(s[0] == '/')
    {
        s.insert(0,"0");
    }
    cout<<s<<endl;
    return 0;
}
