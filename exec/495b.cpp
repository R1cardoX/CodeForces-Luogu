#include <iostream>
#include <vector>

using namespace std;

#define CV(x) cout<<(#x)<<":"; for(auto var:x) cout<<var<<" "; cout<<endl

int get_count(vector<int> num,size_t site)
{
    int flag = 0;
    int count = 0;
    vector<bool> c(100000+1,false);
    for(size_t i = site + 1;i<num.size();i++)
    {
        if(!c[num[i]])
        {
            c[num[i]] = true;
            //cout<<num[i]<<" ";
            flag = num[i];
            count++;
        }
    }
    return count;
}

int get_num(vector<int> num)
{
    int count = 0;
    vector<bool> c(100000+1,false);
    for(size_t i=0;i<num.size() - 1;i++)
    {
        if(!c[num[i]]) 
        {
            c[num[i]] = true;
            //cout<<"match:"<<i<<" "<<num[i]<<" ";
            count += get_count(num,i);
            //cout<<endl;
        }
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i =0;i<n;i++)
        cin>>a[i];
    cout<<get_num(a);
}
