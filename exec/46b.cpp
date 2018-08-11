#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define cv(x) cout<<(#x)<<endl; for(auto var:x) cout<<var<<" "; cout<<endl
#define max(a,b) ((a)>(b) ? (a) : (b)) 

int get_time(vector<int> arr)
{
    int time = 0;
    for(size_t i=1;i<arr.size();i += 2)
        time += arr[i] - arr[i-1];
    return time;
}

void get_max(vector<int> arr,vector<int> a,int &m,int k)
{
    vector<int> ar;
    vector<int>::iterator ite = arr.begin();
    while( ite != arr.end() )
    {
        ar = a;
        if(*ite%2 && a[*ite]+1 < k-1)
            ar.push_back(a[*ite]+1);
        else if(a[*ite+1] > 0)
            ar.push_back(a[*ite+1]-1);
        sort(ar.begin(),ar.end());
        int d = get_time(ar);
        m = max(m,d);
        ar.clear();
        ite++;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> arr(n),max_arr,min_arr,a(n+1);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    arr.push_back(0);
    arr.push_back(m);
    sort(arr.begin(),arr.end());
    int c = get_time(arr);
    for(int i=0;i<n+1;i++)
        a[i] = arr[i+1] - arr[i];
    int max_num = 0;
    int min_num = 0;
    for(int i=0;i<n+1;i++)
    {
        if(a[max_num] < a[i])
        {
            max_arr.clear();
            max_num = i;
            max_arr.push_back(i);
        }
        else if(a[max_num] == a[i])
        {
            max_arr.push_back(i);
        }
    }
    get_max(max_arr,arr,c,m);
    for(int i=0;i<n+1;i++)
    {
        if(a[min_num] > a[i] && a[min_num] > 1)
        {
            min_arr.clear();
            min_num = i;
            min_arr.push_back(i);
        }
        else if(a[min_num] == a[i])
        {
            min_arr.push_back(i);
        }
    }
    get_max(min_arr,arr,c,m);
    cout<<c;
    return 0;
}
