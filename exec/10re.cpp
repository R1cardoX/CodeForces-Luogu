#include <iostream>
#include <string>

using namespace std;

bool is_complie(string s,string p)
{
    int i,j=0;
    for(i=0;i<(int)s.size();i++)
    {
        if(s[i] == p[j] || p[j] == '.')
        {
            j++;
            continue;
        }
        else if(p[j] == '*')
        {
            if(j-1 < 0)
                return false;
            if(s[i] == p[j-1] || p[j-1] == '.')
            {
                j++;
                continue;
            }
            if(j+1 >= (int)p.size())
                return false;
            if(s[i] == p[j+1] || p[j+1] == '.')
            {
                j += 2;
                continue;
            }
        }
        else
        {
            if(p[j+1] == '*')
            {
                j++;
                continue;
            }
            return false;
        }
    }
    return true;
}


int main()
{
    string s;
    string p;
    cin>>s;
    cin>>p;
    cout<<is_complie(s,p);
}
