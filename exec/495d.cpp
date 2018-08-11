#include <iostream>
#include <vector>

using namespace std;

#define CV(x) cout<<(#x)<<":"; for(auto var:x) cout<<var<<" "; cout<<endl
#define CK(x) cout<<(#x)<<":"<<x<<endl;
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
                return i;
            }
        i++;
    }
}

int get_y(int x,int a,int b,int max)
{
    return a+b-x-max; 
}

vector<int> get_matrix(int n,int i)
{
    vector<int> matrix(2,0);
    for(int k=i;k<=n;k++)
        for(int j=i;j<=n;j++)
            if(j*k == n)
            {
                matrix[0] = k;
                matrix[1] = j;
                return matrix;
            }
    return matrix;
}

vector<int> make_count(vector<int> num,int max)
{
    vector<int> count(max+1,0);
    for(auto var:num)
        count[var]++;
    return count;
}
bool is_good(vector<int> num,vector<int> nnew)
{
    for(size_t i=1;i<nnew.size();i++)
    {
        if(num[i] != nnew[i])
            return false;
    }
    return true;
}

vector<int> get_new(int x,int y,int a,int b,int max)
{
    vector<int> nnew(max+1,0);
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
        {
            int num = 0;
            i>x ? num += i-x:num += x-i;
            j>y ? num += j-y:num += y-j;
            nnew[num]++;
        }
    return nnew;
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
    vector<int> count = make_count(a,max);
    int x = get_x(count);
    vector<int> matrix = get_matrix(n,x*2-1);   
    int y = get_y(x,matrix[0],matrix[1],max);
    if(is_good(count,get_new(x,y,matrix[0],matrix[1],max)))
    {
         cout << matrix[0] << " " << matrix[1] <<endl;
         cout << x <<" "<< y <<endl;
    }
    else cout<<-1<<endl;
    return 0;
}
