#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

int main()
{
    int n,d;
    scanf("%d%d",&n,&d);
    int Min=0,Max=0;
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        Min+=x;
        Max+=x;
        if(!x)
        {
            if(Max<0)   //有检查且上限也无法达到正数，则必须存款
            {
                Min=0;
                Max=d;
                cnt++;
            }
            else
                Min=max(Min,0); //下限不能小于0
        }
        else
        {
            if(Min>d)   //下限都超过规定的上限
            {
                puts("-1");
                return 0;
            }
            Max=min(Max,d); //上限不能超规定的上限
        }
    }
    printf("%d\n",cnt);
    return 0;
}
