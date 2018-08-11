#include <iostream>
#include <string>

using namespace std;

bool is_vowel(char o)
{
    char vowel[] = {'a','o','u','i','e'};
    for(auto chr:vowel)
    {
        if(chr == o)
            return true;
    }
    return false;
}

bool is_right(string s)
{
    string::iterator ite = s.begin();
    while( ite != s.end())
    {
        if(!is_vowel(*ite) && *ite != 'n')
        {
            if(!is_vowel(*(++ite)))
                return false;
            else ite--;
        }
        ite++;
    }
    return  true;
}

int main()
{
    string s;
    cin>>s;
    is_right(s) ? cout<<"YES" : cout<<"NO";
}
