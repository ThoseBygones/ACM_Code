#include <bits/stdc++.h>
using namespace std;

#define MAXN 300005

int vis[MAXN];  //����Ϣ�Ƿ񱻶���

queue <pair<int,int> > q[MAXN]; //first--��Ϣ���ĸ�app�����ģ�second--��Ϣ���ܵڼ�����Ϣ

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(vis,0,sizeof(vis));
    int cnt=0;  //��Ϣ���
    int ans=0;  //δ����Ϣ����
    int p=1;  //������Ϣ���ձ�ţ���һ��δ��������Ϣ���
    while(m--)
    {
        int op,val;
        scanf("%d%d",&op,&val);
        if(op==1)
        {
            q[val].push(make_pair(val,++cnt));
            ans++;
        }
        else if(op==2)
        {
            while(!q[val].empty())
            {
                int temp=q[val].front().second;
                if(!vis[temp])  //����Ϣδ����������δ������-1
                    ans--;
                vis[temp]=1;    //����Ϣ������
                q[val].pop();
            }
        }
        else
        {
            for(int i=p; i<=min(val,cnt); i++)
            {
                if(!vis[i])
                    ans--;
                vis[i]=1;
            }
            p=max(p,val);
        }
        printf("%d\n",ans);
    }
    return 0;
}
