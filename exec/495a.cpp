#include <iostream>
#include <vector>

using namespace std;

#define CV(X) cout<<(#X)<<":"; for(auto val:X) cout<<val<<" "; cout<<endl

int n_build(vector<int> des,int d)
{
    int num = 0;
    for(auto val:des)
    {
        if(val > 2*d)
            num += 2;
        else if(val == 2*d)
            num++;
    }
    return num + 2;
}

int main()
{
    int n,d;
    cin>>n>>d;
    vector<int> x(n);
    vector<int> des(n-1);
    for(int i = 0 ; i < n;i++)
    {
        cin>>x[i];
    }
    for(int i=0;i<n-1;i++)
        des[i] = x[i+1] - x[i];
    CV(x);
    CV(des);
    cout<<n_build(des,d);
    return 0;
}
