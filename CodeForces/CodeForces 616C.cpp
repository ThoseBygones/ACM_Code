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
    vis[x][y]=cnt;  //vis数组实际上是用来记录编号的
    num[cnt]++; //每找到一个连通的"."，数量+1
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
            if(maze[i][j]=='.' && !vis[i][j])   //搜索"."的连通块的数量
            {
                dfs(i,j);
                cnt++;  //cnt的作用相当于给这些连通块编号
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
                set <int> s;    //用集合set来存储，避免重复计算
                set <int>::iterator it; //定义迭代器
                int ans=1;  //"*"自己本身也要计入总数
                for(int k=0; k<4; k++)  //每个"*"的四个方向的"."数量
                    s.insert(vis[i+dx[k]][j+dy[k]]);    //向集合中插入连通块编号
                for(it=s.begin(); it!=s.end(); it++)    //不能写成it<=s.end()，因为虽然礼盒里的元素被自动排序，但是遍历的时候并不是从前往后遍历
                    ans+=num[*it];  //it是个（迭代器的）指针，应写成*it
                res[i][j]=(ans%10)+'0'; //
            }
        }
    }
    for(int i=0; i<n; i++)
        printf("%s\n",res[i]);
    return 0;
}
