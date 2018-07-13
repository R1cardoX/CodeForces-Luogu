#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
    string msg[7];
    vector<int> num;
    string key[] = {"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
    int i=0;
    for(i = 0;i<7;i++)
    {
        cin>>msg[i];
    }
    for(auto m:msg)
    {
        i = 1;
        for(auto nn:key)
        {
            if(m == nn)
            {
                    num.push_back(i*i);
                    break;
            }
            else if(m == "a")
            {
                    num.push_back(1);
                    break;
            }
            else if(m == "both")
            {
                    num.push_back(4);
                    break;
            }
            else if(m == "another")
            {
                    num.push_back(9);
                    break;
            }
            else if(m == "first")
            {
                    num.push_back(1);
                    break;
            }
            else if(m == "second")
            {
                    num.push_back(4);
                    break;
            }
            else if(m == "third")
            {
                    num.push_back(9);
                    break;
            }
            i++;
        }
    }
    sort(num.begin(),num.end());    
    int flag = 0;
    if(num.size() == 0)
    {
        cout<<0;
        return 0;
    }
    for(auto n:num)
    {
        if(flag == 0)
        {
            cout<<n;    
            flag = 1;
            continue;
        }
        if(n<10)
            cout<<"0";
        cout<<n;
    }
    return 0;
}
