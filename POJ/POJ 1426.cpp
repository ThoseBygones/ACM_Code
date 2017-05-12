//dfs解决：
#include <iostream>
#define LL long long
#define UL unsigned long long
using namespace std;

int n;
bool flag;

void dfs(UL num,int cnt)
{
    if(flag)
        return ;
    if(num%n==0)
    {
        cout << num << endl;
        flag=true;
        return ;
    }
    if(cnt==19)
        return ;
    dfs(num*10,cnt+1);
    dfs(num*10+1,cnt+1);
}

int main()
{
    while(cin >> n,n)
    {
        flag=false;
        dfs(1,0);
    }
    return 0;
}


//bfs解决：
#include <iostream>
#define LL long long
#define MAXN 1000005
using namespace std;

int n;
LL que[MAXN];

LL bfs()
{
    int head=0,rear=0;
    que[rear++]=1;
    while(1)
    {
        LL temp=que[head++];
        if((temp*10)%n==0)
            return temp*10;
        if((temp*10+1)%n==0)
            return temp*10+1;
        que[rear++]=temp*10;
        que[rear++]=temp*10+1;
    }
    return -1;
}

int main()
{
    while(cin >> n,n)
        cout << bfs() << endl;
    return 0;
}
