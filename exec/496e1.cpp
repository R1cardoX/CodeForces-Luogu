#include <iostream>
#include <vector>
using namespace std;

inline int middle_num(vector<int> n,int site)
{
    int flag = 0;
    int nCount = 0;
    for(int i=site;i>=0;i--)
        for(int j=site;j<(int)n.size();j++)
        {
            for(int z=i;z<=j;z++)
                flag += n[z];
            if(((~(j-i)&1) && flag == -1) || (((j-i)&1) && flag == 0))
                nCount++;
            flag = 0;
        }
    return nCount;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> num(n);
    vector<int> nn(n,0);
    int site;
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
        if(!(num[i]^m))
            site = i;
        num[i] > m ? nn[i] = 1 : nn[i] = -1;
    }
    cout<<middle_num(nn,site);
}
