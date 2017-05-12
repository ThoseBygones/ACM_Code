#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#define MAXN 10005
using namespace std;

struct RoomNumber
{
    int num;
    int step;
};

bool vis[MAXN],prime[MAXN];
int s,e;

int bfs()
{
    queue <RoomNumber> q;
    memset(vis,false,sizeof(vis));
    if(s==e)
        return 0;
    vis[s]=1;
    RoomNumber next;
    next.num=s;
    next.step=0;
    q.push(next);
    while(!q.empty())
    {
        RoomNumber now;
        now=q.front();
        q.pop();
        for(int i=1; i<=1000; i*=10)    //遍历这个四位数的4位
        {
            for(int j=0; j<=9; j++) //遍历数字0~9
            {
                if(i==1000 && j==0) //最高位不能为0
                    continue;
                int temp = now.num / (i*10) * (i*10) + now.num%i + j*i; //对这个4位数字逐位搜索
                if(temp==e)
                    return now.step+1;
                if(prime[temp] && !vis[temp])
                {
                    vis[temp]=1;
                    next.num=temp;
                    next.step=now.step+1;
                    q.push(next);
                }
            }
        }
    }
    return -1;
}

int main()
{
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=0;
    for(int i=2; i<=MAXN; i++)
    {
        if(prime[i])
        {
            for(int j=i*i; j<=MAXN; j+=i)
                prime[j]=false;
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        cin >> s >> e;
        int ans=bfs();
        if(ans==-1)
            cout << "Impossible" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
