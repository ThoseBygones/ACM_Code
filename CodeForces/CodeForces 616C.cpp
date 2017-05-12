#include <cstdio>
#include <cstring>
#include <set>
#define MAXN 1005
using namespace std;

char maze[MAXN][MAXN],res[MAXN][MAXN];
int vis[MAXN][MAXN];
int num[MAXN*MAXN];
int n,m,k;
int cnt=1;
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

bool inMap(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
        return true;
    return false;
}

void dfs(int x,int y)
{
    if(vis[x][y])
        return ;
    vis[x][y]=cnt;  //vis����ʵ������������¼��ŵ�
    num[cnt]++; //ÿ�ҵ�һ����ͨ��"."������+1
    for(int i=0; i<4; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(inMap(nx,ny) && maze[nx][ny]=='.')
            dfs(nx,ny);
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<n; i++)
        scanf("%s",&maze[i]);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(maze[i][j]=='.' && !vis[i][j])   //����"."����ͨ�������
            {
                dfs(i,j);
                cnt++;  //cnt�������൱�ڸ���Щ��ͨ����
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(maze[i][j]=='.')
                res[i][j]='.';
            else
            {
                set <int> s;    //�ü���set���洢�������ظ�����
                set <int>::iterator it; //���������
                int ans=1;  //"*"�Լ�����ҲҪ��������
                for(int k=0; k<4; k++)  //ÿ��"*"���ĸ������"."����
                    s.insert(vis[i+dx[k]][j+dy[k]]);    //�򼯺��в�����ͨ����
                for(it=s.begin(); it!=s.end(); it++)    //����д��it<=s.end()����Ϊ��Ȼ������Ԫ�ر��Զ����򣬵��Ǳ�����ʱ�򲢲��Ǵ�ǰ�������
                    ans+=num[*it];  //it�Ǹ����������ģ�ָ�룬Ӧд��*it
                res[i][j]=(ans%10)+'0'; //
            }
        }
    }
    for(int i=0; i<n; i++)
        printf("%s\n",res[i]);
    return 0;
}
