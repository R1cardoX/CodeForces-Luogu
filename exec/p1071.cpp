#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str[3];
    for(int i = 0;i<3;i++)
    {
        cin>>str[i];
    }
    vector<int> arr1('z'+1,0);    
    for(int i = 0;i<(int)str[0].size();i++)
    {
        arr1[str[0][i]] = str[1][i];
    }
    for(int i = 0;i<(int)str[0].size();i++)
    {
        if(arr1[str[0][i]] != str[1][i])
        {
            cout<<"Failed"<<endl;
            return 0;
        }
    }
    for(int i = 0;i<(int)str[1].size();i++)
    {
        if(arr1[str[1][i]] != str[0][i] && arr1[str[1][i]] != 0)
        {
            cout<<"Failed"<<endl;
            return 0;
        }
    }
    for(auto s:str[0])
    {
        if((int)(str[1].find(s)) == -1)
        {
            cout<<"Failed"<<endl;
            return 0;
        }
    }
    int n;
    for(auto s:str[2])
    {
        n = str[0].find(s);
        if(n == -1)
        {
            cout<<"Failed"<<endl;
        }
        else
        {
            cout<<str[1][n];
        }
    }
    cout<<endl;
}
