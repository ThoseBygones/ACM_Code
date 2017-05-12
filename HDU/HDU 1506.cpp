#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

#define MAXN 100005

LL a[MAXN];
LL l[MAXN],r[MAXN]; //��¼ĳ��������ߣ��ұߣ���һ�������͵ľ��ε��±�
LL dp[MAXN];

int main()
{
    int n;
    while(~scanf("%d",&n),n)
    {
        for(int i=1; i<=n; i++)
            scanf("%I64d",&a[i]);
        l[1]=1;
        r[n]=n;
        for(int i=2; i<=n; i++) //��������ö���ѭ��ɨ����ܻᳬʱ������ö�̬�滮��ÿ�����ε�ǰһ�����ζ�Ӧ��l[i]ֵ����ÿ�����ε�ǰһ��������ߵ�һ�������͵ľ��ε��±꣩
        {
            int t=i;
            while(t>1 && a[t-1]>=a[i])
                t=l[t-1];
            l[i]=t;
        }
        for(int i=n-1; i>=1; i--)   //ÿ�����ε�ǰһ�����ζ�Ӧ��r[i]ֵ����ÿ�����εĺ�һ�������ұߵ�һ�������͵ľ��ε��±꣩
        {
            int t=i;
            while(t<n && a[t+1]>=a[i])
                t=r[t+1];
            r[i]=t;
        }
        LL ans=0;
        for(int i=1; i<=n; i++)
            ans=max(ans,(r[i]-l[i]+1)*a[i]);
        printf("%I64d\n",ans);
    }
    return 0;
}
