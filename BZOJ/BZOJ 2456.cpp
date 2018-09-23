/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-09-21
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: BZOJ
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int pre=0;
    int cnt=1;
    scanf("%d",&pre);
    for(int i=1; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        if(pre==x)
            cnt++;
        else
        {
            cnt--;
            if(!cnt)
            {
                pre=x;
                cnt++;
            }
        }
    }
    printf("%d\n",pre);
    return 0;
}
