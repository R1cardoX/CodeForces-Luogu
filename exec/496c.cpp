#include <iostream>
#include <vector>
using namespace std;
#define IN(X) cin>>X


bool is_twos(int n)
{  
    int i;
    for(i=2;i<n;i <<= 1);    
    return (i ^ n) ? false:true;
}

int count(vector<int> num)
{
    int flag = 0;
    int size = 0;
    size_t s = num.size();
    for(register size_t i =0;i<s;i++)
    {
        for(register size_t j=0;j<s;j++)
        {
            if(is_twos(num[i]+num[j]) && (i ^ j))
            {
                flag = 1;
            }
        }
        if(flag == 0)
            size++;
        flag = 0;
    }
    return size;
}

int main()
{
    int n;
    IN(n);
    vector<int> num(n);
    for(register int i=0;i<n;i++)
    {
        IN(num[i]);
    }
    cout<<count(num);
}
