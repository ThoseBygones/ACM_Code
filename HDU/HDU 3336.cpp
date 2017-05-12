#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 200005
#define MOD 10007

char a[MAXN];    //������
int next[MAXN]; //ƥ��ʧ�ܼ�¼
int dp[MAXN];   //ǰi���ַ�����ɵĴ������ж��ٸ�ǰ׺
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
        for(int i=1; i<=n; i++) //�ַ����±�ȫ�����ƣ���1��ʼ����
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
