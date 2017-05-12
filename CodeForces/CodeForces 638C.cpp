#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 200010

vector <int> edge[MAXN],id[MAXN],ans[MAXN];
int n;
int maxt;

void dfs(int x,int fa,int t)
{
    int tempt=0;
    for(int i=0; i<edge[x].size(); i++)
    {
        if(edge[x][i]==fa)  //反向边不遍历
            continue;
        tempt++;
        if(tempt==t)
            tempt++;
        ans[tempt].push_back(id[x][i]);
        dfs(edge[x][i],x,tempt);
    }
    maxt=max(maxt,tempt);
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        id[u].push_back(i);
        edge[v].push_back(u);
        id[v].push_back(i);
    }
    dfs(1,0,0);
    printf("%d\n",maxt);
	for(int i=1; i<=maxt; i++)
	{
		printf("%d",ans[i].size());
		for(int j=0; j<ans[i].size(); j++)
            printf(" %d",ans[i][j]);
		printf("\n");
	}
	return 0;
}


/*
vector <int> vec[2000100],len[2000100],des[2000100];
int mx;
void work(int s,int pre,int tim)
{
	int tt=0;
	for (int k=0;k<des[s].size();k++)
	{
		if (des[s][k]==pre) continue;
		tt++;if (tt==tim) tt++;
		vec[tt].push_back(len[s][k]);
		work(des[s][k],s,tt);
	}
	mx=max(mx,tt);
}
int main()
{
	int n;scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		des[u].push_back(v);len[u].push_back(i);
		des[v].push_back(u);len[v].push_back(i);
	}
	work(1,0,0);
	printf("%d\n",mx);
	for (int i=1;i<=mx;i++)
	{
		printf("%d ",vec[i].size());
		for (int k=0;k<vec[i].size();k++) printf("%d ",vec[i][k]);
		printf("\n");
	}
}
*/
