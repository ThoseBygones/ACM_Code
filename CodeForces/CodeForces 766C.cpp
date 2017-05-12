#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1005
#define MOD 1000000007
#define INF 0x3f3f3f3f

int a[30];  //每个子串中每个字母能出现的最多次数
int dpD[MAXN];   //dpD[i]为前i个字符的所有分割方案数
int dpM[MAXN];  //dpM[i]为前i个字符分割后形成的最小段数
char str[MAXN];

bool check(int l,int r)
{
    int len=r-l+1;
    for(int i=l; i<=r; i++) //预处理保证每个字符出现次数符合要求
    {
        if(a[str[i]-'a']<len)
            return false;
    }
    return true;
}

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",str+1);
    for(int i=0; i<26; i++)
        scanf("%d",&a[i]);
    memset(dpD,0,sizeof(dpD));
    memset(dpM,INF,sizeof(dpM));
    dpD[0]=1;
    dpM[0]=0;
    int maxlen=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            if(check(j,i))
            {
                dpD[i]=(dpD[i]%MOD+dpD[j-1]%MOD)%MOD;   //dp最多方案数
                dpM[i]=min(dpM[i],dpM[j-1]+1);  //dp最小段数
                if(dpD[j-1])
                    maxlen=max(maxlen,i-j+1);   //记录最大子串长度
            }
        }
    }
    /*for(int i=0; i<=n; i++)
        printf("%d ",dpM[i]);
    puts("");*/
    printf("%d\n%d\n%d\n",dpD[n],maxlen,dpM[n]);
    return 0;
}
