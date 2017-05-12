#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define LL long long
using namespace std;

int a[2000005];

bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    int num;
    while(~scanf("%d",&num))
    {
        for(int i=0; i<num; i++)
            scanf("%d",&a[i]);
        sort(a,a+num,cmp);
        LL ans=0;
        for(int i=0; pow(4,i)<=num; i++)
        {
            for(int j=0; j<pow(4,i); j++)
                ans+=a[j];
        }
        cout << ans << endl;
    }
}
