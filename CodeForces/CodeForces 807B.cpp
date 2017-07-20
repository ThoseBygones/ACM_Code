#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define LL long long
#define MAXN 1005
#define INF 0x3f3f3f3f
#define MOD 1000000007

int p,x,y;

bool check(int val)
{
    int x=(val/50)%475;
    for(int i=0; i<25; i++)
    {
        x=(x*96+42)%475;
        if(x+26==p)
            return true;
    }
    return false;
}

int main()
{
    scanf("%d%d%d",&p,&x,&y);
    int ans=0;
    if(x<y)
        ans+=(y-x+99)/100;
    x+=ans*100;
    int temp=x;
    while(temp>=y)
    {
        if(check(temp))
        {
            printf("%d\n",ans);
            return 0;
        }
        temp-=50;
    }
    int cnt=0;
    while(true)
    {
        if(check(x+cnt*50))
            break;
        cnt++;
    }
    ans=ans+(cnt+1)/2;
    printf("%d\n",ans);
    return 0;
}
