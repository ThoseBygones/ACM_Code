#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1005

int a[MAXN];
int l[MAXN];
int r[MAXN];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int cnt=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",a+i);
            if(a[i]!=0)
                cnt++;
        }
        if(cnt==0)
            puts("NO");
        else
        {
            int num=0;
            l[0]=1;
            for(int i=1; i<=n; i++)
            {
                l[++num]=i;
                while(a[i]==0)
                    i++;
                if(!--cnt)
                    break;
                r[num]=i;
            }
            r[num]=n;
            puts("YES");
            printf("%d\n",num);
            for(int i=1; i<=num; i++)
                printf("%d %d\n",l[i],r[i]);
        }
    }
    return 0;
}
