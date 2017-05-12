#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

#define MAXN 505
#define INF 0x3f3f3f3f

map <string,int> mp;

int cap[MAXN][MAXN];    //��¼ͼ���ڽӾ���
int level[MAXN];    //��¼ͼ�и���Ĳ��
int n,m,k;    //��,��
int st,ed;  //Դ�㣬���

int bfs()
{
    queue <int> q;
    memset(level,-1,sizeof(level));
    level[st]=0;    //����������ͺ�������ѭ��
    q.push(st);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=0; v<=ed; v++)   //ע��˴������ж���(0,n+1�ǳ���Դ��,���)
        {
            if(level[v]==-1 && cap[u][v])   //�˴�Ӧ��cap[v][i]!=0,��Ϊdfs�ǿ��ܻ��ߴ��������Զ������������
            {
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }
    if(level[ed]!=-1)   //���Ĳ�β�����-1˵���ҵ�
        return 1;
    return 0;
}

int dfs(int u,int cur_flow)
{
    int tempf=cur_flow;
    if(u==ed)
        return cur_flow;
    for(int v=0; v<=ed; v++) //ע��˴������ж���
    {
        if(cap[u][v]>0 && level[u]+1==level[v])
        {
            int flow=dfs(v,min(tempf,cap[u][v]));
            cap[u][v]-=flow;
            cap[v][u]+=flow;
            tempf-=flow;
        }
    }
    return cur_flow-tempf;
}

int Dinic()
{
    int ans=0;
    while(bfs())    //һ��bfs�����ҵ���������·
        ans+=dfs(st,INF);
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        mp.clear();
        int cnt=1;  //���ַ�����Hashֵ�������ַ�����Ӧ���㣩
        char name[30];
        char type[30];
        st=0;   //����Դ��
        ed=MAXN-1; //���
        memset(cap,0,sizeof(cap));
        for(int i=1; i<=n; i++)
        {
            scanf("%s",type);
            mp[type]=cnt++;
            cap[st][mp[type]]=1;  //��ʾ������Ҫ�嵽��������Ĳ�ͷ���ͣ����ܴ�Դ������������
        }
        scanf("%d",&m);
        for(int i=1; i<=m; i++)
        {
            scanf("%s%s",name,type);
            mp[name]=cnt++;
            if(!mp[type])
                mp[type]=cnt++;
            cap[mp[type]][mp[name]]=1;
            cap[mp[name]][ed]=1;
        }
        scanf("%d",&k);
        for(int i=1; i<=k; i++)
        {
            char type2[30];
            scanf("%s%s",type,type2);
            if(!mp[type])
                mp[type]=cnt++;
            if(!mp[type2])
                mp[type2]=cnt++;
            cap[mp[type2]][mp[type]]=INF;    //��ģ��������򣺷������->��������ͷ->����������->����
        }
        int ans=Dinic();
        printf("%d\n",m-ans);
        if(t)
            puts("");
    }
    return 0;
}
