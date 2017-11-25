#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int main()
{
    int n;
    scanf("%d",&n);
    int cur=0;
    for(int i=0; i<n; i++)
    {
        int s,d;
        scanf("%d%d",&s,&d);
        while(s<=cur)
            s+=d;
            cur=s;
    }
    printf("%d\n",cur);
    return 0;
}
