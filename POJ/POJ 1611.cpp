#include<iostream>
#include<cstdio>
using namespace std;

int num[30010],fa[30010],rank[30010];

int find_set(int x)
{
    if(x!=fa[x])
        return find_set(fa[x]);
    return fa[x];
}

void merge_set(int x,int y)
{
    x=find_set(x);
    y=find_set(y);
    if(x==y)
        return;
    if(rank[x]>rank[y])
    {
        fa[y]=x;
        num[x]+=num[y];
    }
    else
    {
        fa[x]=y;
        if(rank[x]==rank[y])
            rank[y]++;
        num[y]+=num[x];
    }
}

int main()
{
    int n,m,a,x,y,v,i,j;
    while(scanf("%d%d",&n,&m))
    {
        if(m==0&&n==0)
            break;
        for(i=0;i<n;i++)
        {
            fa[i]=i;
            num[i]=1;
            rank[i]=0;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d",&a);
            scanf("%d",&x);
            for(j=1;j<a;j++)
            {
                scanf("%d",&y);
                merge_set(x,y);
                x=y;
            }
        }
        v=find_set(0);
        cout<<num[v]<<endl;
    }
    return 0;
}

//��д�Ĵ��룺
#include <iostream>
#include <cstring>
#define MAXN 30005
using namespace std;

int par[MAXN];  //��¼�ýڵ�ĸ��ڵ�
int rank[MAXN]; //��¼�ýڵ�Ľڵ�ȼ�
int n,m;

int findSet(int r)
{
    if(r==par[r])
        return r;
    return findSet(par[r]);
}

void mergeSet(int x,int y)
{
    int xx=findSet(x);
    int yy=findSet(y);
    if(rank[xx]==rank[yy])
        rank[yy]++; //���ڵ�ȼ���ͬ�������ָ��ߵ�
    if(rank[xx]>rank[yy])   //�ȼ��͵Ľڵ㲢���ȼ��ߵĽڵ���
        par[yy]=xx;
    else
        par[xx]=yy;
}

int main()
{
    while(cin >> n >> m)
    {
        if(n==0 && n==0)
            break;
        for(int i=0; i<n; i++)
        {
            rank[i]=0;
            par[i]=i;
        }
        for(int i=0; i<m; i++)
        {
            int num;
            cin >> num;
            int x;
            cin >> x;
            for(int j=1; j<num; j++)
            {
                int y;
                cin >> y;
                mergeSet(x,y);
            }
        }
        int source=findSet(0);
        int sum=0;
        for(int i=0; i<n; i++)
        {
            if(findSet(i)==source)
                sum++;
        }
        cout << sum << endl;
    }
    return 0;
}
