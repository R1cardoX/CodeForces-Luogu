#include <iostream>
#include <string>

using namespace std;

bool is_three(long long num)
{
    if(num < 10)
        return num%3 ? false : true;
    return num%3 ? is_three(num/10): true;
}

int get_num(string s)
{
    long long num = 0;
    for(size_t i = 0;i < s.size();i++)
        num = s[s.size()-i-1] - '0' + (num<<3) + (num<<1);
    return num;
}

int main()
{
    string str;
    cin>>str;
    int count = 0;
    string::reverse_iterator ite = str.rbegin();
    string s;
    long long num;
    while( ite != str.rend() )
    {
        if(*ite == '0')
        {
            ite++;
            count++; 
            s.clear();
        }
        s.push_back(*ite);
        num = get_num(s);
        if(is_three(num))
        {
            count++; 
            s.clear();
        }
        ite++;
    }
    cout<<count<<endl;
    return 0;
}
