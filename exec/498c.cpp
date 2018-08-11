#include <iostream>
#include <vector>

using namespace std;

#define cn(x) cout<<(#x)<<":"<<x<<endl;
typedef long long ll;

ll get_better(vector<int> arr)
{
    int i=0;
    int j=(int)arr.size()-1;
    ll a=0;
    ll b=0;
    ll sum=0;
    while(i <= j)
    {
        if(a<=b)
        {
            a+=arr[i];
            i++;
        }
        else
        {
            b+=arr[j];
            j--;
        }
        if(a == b)
            sum = a;
    }
    return sum;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<get_better(arr);
    return 0;
}
