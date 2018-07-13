#include <iostream>
#include <vector>

using namespace std;

vector<int> get_high(vector<int> num)
{
    vector<int> relase(num.size());
    int j=0;
    for(size_t i=1;i<num.size();i++)
    {
        if(num[i] == 1)
        {
            relase[j] = num[i-1];
            j++;
        }
    } 
    relase[j] = num.back();
    vector<int>::iterator ite = relase.begin();
    while(ite != relase.end())
    {
        if(*ite == 0)
        {
            ite = relase.erase(ite);
            continue;
        }
        ite++;
    }
    return relase;
}

int main()
{
    int n;
    cin>>n;
    vector<int> num(n);
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    vector<int> nn = get_high(num);
    cout<<nn.size()<<endl;
    for(auto val:nn)
    {
        cout<<val<<" ";
    }
}
