#include <iostream>
#include <string>

using namespace std;

#define FOR(i,a,b) for(auto i=(a);i!=(b);i++)
#define FORR(i,a,b) for(auto i=(a);i!=(b);i--)

template <typename T>
inline void swap(T &a,T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void obtain_str(string &str)
{
    FOR(i,0,(int)str.size())
    {
        if(str[i]-str[i+1] == 1)
            ::swap(str[i],str[i+1]);
    }
}

int main()
{
    string str;
    cin>>str;
    string str1 = str;
    obtain_str(str);
    while(str1 != str)
    {
        str1 = str;
        obtain_str(str);
    }
    cout<<str;
    return 0;
}
