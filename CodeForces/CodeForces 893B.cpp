#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

int a[]={1,6,28,120,496,2016,8128,32640,130816};

int main()
{
    int n;
    scanf("%d",&n);
    int ans;
    for(int i=0; i<9; i++)
    {
        if(n%a[i]==0)
            ans=a[i];
    }
    printf("%d\n",ans);
    return 0;
}
