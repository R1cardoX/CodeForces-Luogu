#include <iostream>
#include <string>
#include <vector>

using namespace std;

void erase_some(string &str)
{
    string::iterator ite = str.begin();
    while(ite != str.end() )
    {
        if(*ite != 'X' && *ite != 'M' && *ite != 'S' && *ite != 'L')
            ite = str.erase(ite);
        else
            ite++;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<string>  str1(n);  
    vector<string>  str2(n);  
    for(int i=0;i<n;i++)
    {
        cin>>str1[i];
        erase_some(str1[i]); 
    }
    for(int i=0;i<n;i++)
    {
        cin>>str2[i];
        erase_some(str2[i]); 
    }
    vector<string>::iterator ite1 = str1.begin();
    vector<string>::iterator ite2 = str2.begin();
    while(ite1 != str1.end())
    {
        ite2 = str2.begin();
        while(ite2 != str2.end())
        {
            if(*ite1 == *ite2)
            {
                ite1 = str1.erase(ite1);
                ite2 = str2.erase(ite2);
                break;
            }
            else
                ite2++;
        }
        if(ite2 == str2.end())
            ite1++;
    }
    cout<<str2.size();
    return 0;
}
