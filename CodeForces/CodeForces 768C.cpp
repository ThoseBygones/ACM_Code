#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 100005

int a[MAXN];
int cnt[2][MAXN];

int main()
{
    int n,k,x;
    scanf("%d%d%d",&n,&k,&x);
    /*for(int i=1; i<=n; i++)
        scanf("%d",a+i);
    sort(a+1,a+n+1);
    for(int i=1; i<=k; i++)
    {
        for(int j=1; j<=n; j+=2)
            a[j]=(a[j]^x);
        sort(a+1,a+n+1);
    }
    for(int i=1; i<=n; i++)
        printf("%d ",a[i]);
    puts("");
    */
    for(int i=1; i<=n; i++)
    {
        int temp;
        scanf("%d",&temp);
        cnt[0][temp]++;
    }
    for(int i=1; i<=k; i++)
    {
        int e=0;
        for(int j=0; j<3005; j++)
        {
            while(cnt[(i-1)%2][j])
            {
                if(e%2)
                {
                    cnt[i%2][(j^x)]+=cnt[(i-1)%2][j]/2;
                    cnt[i%2][j]+=cnt[(i-1)%2][j]-cnt[(i-1)%2][j]/2;
                }
                else
                {
                    cnt[i%2][(j^x)]+=(cnt[(i-1)%2][j]+1)/2;
                    cnt[i%2][j]+=cnt[(i-1)%2][j]-(cnt[(i-1)%2][j]+1)/2;
                }
                e+=cnt[(i-1)%2][j];
                cnt[(i-1)%2][j]=0;
            }
        }
        //system("pause");
    }
    int Max,Min;
    for(int i=3004; i>=0; i--)
    {
        if(cnt[k%2][i])
        {
            Max=i;
            break;
        }
    }
    for(int i=0; i<3005; i++)
    {
        if(cnt[k%2][i])
        {
            Min=i;
            break;
        }
    }
    //printf("%d %d\n",a[n],a[1]);
    printf("%d %d\n",Max,Min);
    return 0;
}
