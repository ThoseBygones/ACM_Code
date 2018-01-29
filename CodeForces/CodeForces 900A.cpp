#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

int main()
{
    int n;
    scanf("%d",&n);
    int x,y;
    int cnt1=0,cnt2=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&x,&y);
        if(x>0)
            cnt1++;
        else
            cnt2++;
    }
    if(cnt1>1 && cnt2>1)
        puts("No");
    else
        puts("Yes");
    return 0;
}
