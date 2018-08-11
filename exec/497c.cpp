#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_num(vector<int> arr1,vector<int> arr2)
{
    vector<int>::iterator ite1 = arr1.begin();
    vector<int>::iterator ite2 = arr2.begin();
    int count = 0;
    while(ite2 != arr2.end())
    {
        if(*ite1 < *ite2)
        {
            count++;
            ite1++;
            ite2++;
        }
        else
        {
            ite2++;
        }
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    vector<int> arr1 = arr;
    arr.erase(arr.begin());
    arr1.pop_back();
    cout<<get_num(arr1,arr);
}
