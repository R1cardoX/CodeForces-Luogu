#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define cv(x) cout<<(#x)<<":"; for(auto var:x) cout<<var<<" "; cout<<endl

struct ch
{
    int n;
    vector<int> count;
};

int get_power(int num)
{
    int i=0;
    while(num != 1)
    {
        num >>= 1;
        i++;
    }
    return i;
}

vector<int> get_power_vec(vector<int> nums)
{
    vector<int> power(33,0);
    vector<int>::iterator ite = nums.begin();
    while( ite != nums.end() )
    {
        power[get_power(*ite)]++;
        ite++;
    }
    return power;
}

int is_obtian(vector<int> nums,int rnum,map<int,ch> &mapvec)
{
    int nCount = 0;
    ch c;
    int num = rnum;
    c.count.resize(33);
    for(int i = num;i>1;i-=2)
    {
        map<int,ch>::iterator ite = mapvec.find(i);
        if(ite != mapvec.end())
        {
            c = mapvec[i];
            nCount += c.n;
            for(int j = 0;j<33;j++)
            {
                nums[j] -= c.count[j];
            }
            num -= i;
            break;
        }
    }
    for(int i = (int)nums.size()-1;i >= 1;i--)
    {
        if(nums[i] > 0 && num >= (1<<i))
        {
            nCount++;
            nums[i]--;
            num -= 1<<i;
            c.count[i]++;
            i++;
        }
    }
    if(num <= nums[0]) 
    {
        c.n = nCount + num;
        c.count[0] += num;
        mapvec[rnum]  = c;
    }
    return num <= nums[0] ? nCount + num : -1;
}

int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> nums(n);
    vector<int> querys(q);
    vector<int> p(33);
    map<int,ch> mapvec;   
    for(int i=0;i<n;i++)
        cin>>nums[i];
    for(int i=0;i<q;i++)
        cin>>querys[i];
    p = get_power_vec(nums);
    vector<int>::iterator ite = querys.begin();
    while( ite != querys.end() )
    {
        cout<<is_obtian(p,*ite,mapvec)<<endl;
        ite++;
    }
    return 0;
}
