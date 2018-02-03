#include <bits/stdc++.h>
using namespace std;

#define MAXN 105
#define LL long long

int tp[MAXN];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        for(int j=a; j<b; j++)
            tp[j]=1;
    }
    bool flag=true;
    for(int i=0; i<m; i++)
    {
        if(!tp[i])
        {
            flag=false;
            break;
        }
    }
    if(flag)
        puts("YES");
    else
        puts("NO");
    return 0;
}
