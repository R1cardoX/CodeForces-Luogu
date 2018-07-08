#include <iostream>
#include <stdlib.h>
#include <list>
#include <vector>
using namespace std;

int main()
{
    int a;
    int e = 0;
    list<vector<int>> nNum;    
    int nCount = 0;
    scanf("%d",&a);
    vector<int> num(10);
    for(num[0] = 1;num[0]<=3;num[0]++)
    {
        for(num[1] = 1;num[1]<=3;num[1]++)
        {
            for(num[2] = 1;num[2]<=3;num[2]++)
            {
                for(num[3] = 1;num[3]<=3;num[3]++)
                {
                    for(num[4] = 1;num[4]<=3;num[4]++)
                    {
                        for(num[5] = 1;num[5]<=3;num[5]++)
                        {
                            for(num[6] = 1;num[6]<=3;num[6]++)
                            {
                                for(num[7] = 1;num[7]<=3;num[7]++)
                                {
                                    for(num[8] = 1;num[8]<=3;num[8]++)
                                    {
                                        for(num[9] = 1;num[9]<=3;num[9]++)
                                        {
                                            e=0;
                                            for(int j = 0;j<10;j++)
                                            {
                                                e += num[j]; 
                                            }
                                            if(e == a)
                                            {
                                                nNum.push_back(num);
                                                nCount++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<nCount<<endl;
    if(nCount != 0)
    {
        for(auto n:nNum)
        {
            for(auto var:n)
            {
                cout<<var<<" ";
            }
            cout<<endl;
        }
    }
    return 0;       
}
