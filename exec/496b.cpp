#include <iostream>
#include <string>

using namespace std;

#define in(X) cin>>X

int is_better(string a,string b)
{
    if(a.back() != b.back())
        return a.size() + b.size();
    string::reverse_iterator a_rite = a.rbegin(); 
    string::reverse_iterator b_rite = b.rbegin(); 
    int i = 0;
    while(a_rite != a.rend() || b_rite != b.rend())
    {
        if(*a_rite == *b_rite)
        {
            a_rite++;
            b_rite++;
            i++;
        }
        else
        {
            break;
        }
    }
    return a.size() + b.size() - 2*i;
}


int main()
{
    string a;
    string b;
    in(a);
    in(b);
    cout<<is_better(a,b); 
    return 0;
}
