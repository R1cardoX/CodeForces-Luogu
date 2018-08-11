#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define cv(x) cout<<(#x)<<":"; for(auto var:x) cout<<var<<" "; cout<<endl

vector<int> get_better(vector<int> dif,int k)
{
    vector<int> bet(k,0);
    vector<int> diff(dif.size(),0);
    int i,j;
    for(i=0;i<(int)bet.size();i++)
    {
        for(j=0;j<(int)dif.size();j++)
        {
            if(diff[j])
                break;
            if(dif[bet[i]] < dif[j])
                bet[i] = j;
        }
        diff[bet[i]] = 1;
    }
    return bet;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> dif(n);
    for(int i=0;i<n;i++)
        cin>>dif[i];
    vector<int> site = get_better(dif,k);
    sort(site.begin(),site.end()); 
    site.erase(site.begin());
    if(site.size() == 0)
    {
        cout<<dif.size();
        return 0;
    }
    else
    {
        
    }
    return 0;
}
