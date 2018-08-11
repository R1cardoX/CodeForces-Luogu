#include <iostream>
#include <vector>

using namespace std;
#define N 200005
#define cv(x) cout<<(#x)<<endl; for(auto var:x) cout<<x<<" "; cout<<endl;
vector<int> next_arr[N];

int a[N],b[N],g[N],c=1;

int get_next(int u,int &n)
{
    int next = 0;
    vector<int>::iterator ite = next_arr[u].begin();
    while( ite != next_arr[u].end() )
    {
        next = *ite;
        ite++;
        b[c]=next;
        a[next]=c++;
        g[u]++;
        g[u] += get_next(next,n);
    }
    return g[u];
}

int main()
{
    int n,q,k,commands,superior;
    cin>>n>>q;
    for(int i=0;i<n-1;i++)
    {
        cin>>superior;
        next_arr[superior].push_back(i+2);
    }
    a[1] = 0;
    b[0] = 1;
    get_next(1,n);
    for(int i=0;i<q;i++)
    {
        cin>>commands>>k;
        if(g[commands] < k-1)
            cout<<-1<<endl;
        else
            cout<<b[a[commands]+k-1]<<endl;;
    }
    return 0;
}
