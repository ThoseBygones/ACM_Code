#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 200005
#define MOD 10007

char a[MAXN];    //串长度
int next[MAXN]; //匹配失败记录
int dp[MAXN];   //前i个字符所组成的串共含有多少个前缀
int n,m;

void getNext()
{
    int i = 0;
    int j = -1;
    memset(next,0,sizeof(next));
    next[0] = -1;
    while(i<n)
    {
        if(j == -1 || a[i] == a[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",a);
        getNext();
        int ans=0;
        dp[0]=0;
        for(int i=1; i<=n; i++) //字符串下标全部后移，从1开始计数
            dp[i]=1;
        for(int i=1; i<=n; i++)
        {
            dp[i]=dp[next[i]]+1;
            ans+=dp[i]%MOD;
        }
        printf("%d\n",ans%MOD);
    }
    return 0;
}
