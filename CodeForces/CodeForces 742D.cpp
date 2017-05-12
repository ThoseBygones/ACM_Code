#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1005
#define INF 0x3f3f3f3f

int w[MAXN],b[MAXN];
int fa[MAXN];
int n,m,wei;
int gw[MAXN],gb[MAXN];  //ÿ��group��weight/beauty�ܺ�
int dp[MAXN];   //dp[i]�൱�ڿռ�Ϊi�ı��������ɵ����beauty

vector <int> v[MAXN];

int findset(int x)
{
    if(x!=fa[x])
        return fa[x]=findset(fa[x]);
    return fa[x];
}

void unionset(int x,int y)
{
    int xx=findset(x);
    int yy=findset(y);
    if(xx!=yy)
        fa[xx]=yy;
}

int main()
{
    scanf("%d%d%d",&n,&m,&wei);
    memset(dp,0,sizeof(dp));
    memset(gw,0,sizeof(gw));
    memset(gb,0,sizeof(gb));
    for(int i=1; i<=n; i++) //UF-set��ʼ��
        fa[i]=i;
    for(int i=1; i<=n; i++)
        scanf("%d",w+i);
    for(int i=1; i<=n; i++)
        scanf("%d",b+i);
    for(int i=1; i<=m; i++) //UF-set
    {
        int u,v;
        scanf("%d%d",&u,&v);
        unionset(u,v);
    }
    for(int i=1; i<=n; i++)
    {
        int temp=findset(i);    //find root
        v[temp].push_back(i);   //ÿ��������Щ��
        gw[temp]+=w[i]; //�ۼ�ÿ���weight
        gb[temp]+=b[i]; //�ۼ�ÿ���beauty
    }
    for(int i=1; i<=n; i++) //����������
    {
        if(v[i].size()==0)  //��root����û��
            continue;
        for(int j=wei; j>0; j--)  //ת��Ϊ�������⣬������Ϊwei��01����
        {
            if(j>=gw[i]) //�����ռ仹���������������װ���beauty�᲻�����
                dp[j]=max(dp[j],dp[j-gw[i]]+gb[i]);
            for(int k=0; k<v[i].size(); k++)    //ÿ����Ҫôѡһ��Ҫôȫѡ���ȿ���ֻѡһ�������
            {
                if(j>=w[v[i][k]])    //�����ﻹ��ʣ��ռ�
                    dp[j]=max(dp[j],dp[j-w[v[i][k]]]+b[v[i][k]]);
            }
        }
    }
    printf("%d\n",dp[wei]);
    return 0;
}
