#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > is_better(vector< vector<int> > num,int len)
{
    vector<int> n(len,0);
    for(size_t i=0;i<num.size();i++)
    {
        for(size_t j=0;j<num.size();j++)
        {
            for(size_t k=0;k<num.size();k++)
            {
                n.clear();
                n[num[i][0]] = 1;
                n[num[i][1]] = 1;
                n[num[j][0]] = 1;
                n[num[j][1]] = 1;
                if(n[num[k][0]] == 1 && n[num[k][1]] == 1 && i != j && i != k && j != k)
                    num.erase(num.begin()+k);
            }
        }
    }
    return num;
}

vector<int> get_min(vector< vector<int> > arr)
{
    int min = 2147483647;
    vector<int> m(3);
    for(size_t i=0;i<arr.size();i++)
    {
        for(size_t j=0;j<i;j++)
        {
            if(min > arr[i][j] && arr[i][j] != 0)
            {
                min = arr[i][j];
                m[0] = i;
                m[1] = j;
                m[2] = min;
            }
        }
    }
    return m;  
}

vector<int> connect_num(vector< vector<int> > arr)
{
    vector<int> num(arr.size());
    num[0] = 1;
    for(size_t i=0;i<num.size();i++)
    {
        if(arr[0][i] == 0)
            num[i] = 1;
    }
    for(size_t i = 0;i<arr.size();i++)
    {
        for(size_t j=0;j<arr.size();j++)
        {
            if(num[i] == 1 && num[j] == 0)
            {
                if(arr[i][j] == 0)
                {
                    num[j] = 1;
                }
            }
        }
    }
    return num;
}


bool is_pass(vector<int> num)
{
    for(auto val:num)
    {
        if(!val)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    vector< vector<int> > arr(n);
    for(int i=0;i<n;i++)
        arr[i].resize(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }    
    int money = 0;
    vector< vector<int> > min(n);
    vector<int> num;
    for(int i=0;i<n;i++)
        min[i].resize(3);
    int i = 0;
    vector< vector<int> > arr2;
    num = connect_num(arr);
    while(!is_pass(num))
    {
        min[i] = get_min(arr);        
        arr[min[i][0]][min[i][1]] = 0;
        arr[min[i][1]][min[i][0]] = 0;
        num = connect_num(arr);
        i++;
    }
    arr2 = is_better(min,n);
    cout<<arr2.size()<<endl;
    for(auto val:arr2)
    {
        cout<<val[0]+1<<" "<<val[1]+1<<endl;
        money += val[2];
    }
    cout<<money<<endl;
    return 0;
}
