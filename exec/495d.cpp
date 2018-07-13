#include <iostream>
#include <vector>

using namespace std;

#define CV(x) cout<<(#x)<<":"; for(auto var:x) cout<<var<<" "; cout<<endl

int get_x(vector<int> num)
{
    vector<int> arr(num.size(),0);
    vector<int> pre_arr(num.size(),0);
    int i = 1;
    while(1)
    {
        pre_arr = arr;
        for(int n=i;n<=i*2;n++)
            arr[n] += 4;
        for(size_t j = 0;j<num.size();j++)
            if(num[j] < arr[j])
            {
                CV(pre_arr);
                CV(arr);
                CV(num);
                return i;
            }
        i++;
    }
}

vector<int> make_count(vector<int> num,int max)
{
    vector<int> count(max+1,0);
    for(auto var:num)
        count[var]++;
    return count;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);    
    int max = 0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i] > max)
            max = a[i];
    }
    cout<<get_x(make_count(a,max));
}
