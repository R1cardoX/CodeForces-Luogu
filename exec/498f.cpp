#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int get_count(vector< vector<int> > arr)
{
    int nCount=0,i=0,j=0;
    int step = arr.size()+arr[0].size()-2;

    return nCount;
}


int main()
{
    int n,m;
    ll k;
    cin>>n>>m>>k;
    vector< vector<int> > arr(n);   
    for(int i=0;i<n;i++)
        arr[i].resize(m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
}
