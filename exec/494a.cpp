#include <iostream>
#include <vector>

using namespace std;

int get_max(vector<int> count)
{
    int max = 0;
    for(auto var:count)
        if(max < var)
            max = var;
    return max;
}   

int main()
{
    int n;
    cin>>n;
    vector<int> num(n);
    vector<int> count(101,0);
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
        count[num[i]]++;
    }
    cout<<get_max(count);
    return 0;
}
