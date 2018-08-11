#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

#define cv(x) cout<<(#x)<<":"; for(auto var:x) cout<<var<<" "; cout<<endl
#define gd(x) get_divisor(integers[i][x])

vector<int> get_divisor(int num)
{
    vector<int> divisor;
    for(int i=1;i<=num;i++)
    {
        if((num/i)*i == num)
           divisor.push_back(i); 
    }
    return divisor;
}

int get_rlt(vector<int> a,vector<int> b,vector<int> c)
{
    int count=0;
    for(size_t i=0;i<a.size();i++)
    {
        for(size_t j=0;j<b.size();j++)
        {
            for(size_t z=0;z<c.size();z++)
            {
                if(a[i]&&b[j]&&c[z])
                {
                    cout<<a[i]<<" "<<b[j]<<" "<<c[z]<<endl;
                    count++;
                }
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    vector< array<int,3> > integers(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            cin>>integers[i][j];
    for(int i=0;i<n;i++)
    {
        sort(integers[i].begin(),integers[i].end());
        cout<<get_rlt(gd(0),gd(1),gd(2))<<endl;
    }
    return 0;
}
