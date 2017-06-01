#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[15];
int sta[2];
bool flag;

void dfs(int val,int mark)
{
    int temp=sta[mark];
    int cnt=0;
    while(temp)
    {
        temp>>=1;
        cnt++;
    }
    if((sta[mark]+(1<<(a[val]-1))) >= sta[mark]+(1<<(cnt-1)))
    {
        //cout << mark << " " << sta[mark] << endl;
        sta[mark]+=1<<(a[val]-1);
        //cout << mark << " " << sta[mark] << endl;
        if(val+1<=10)
        {
            dfs(val+1,0);
            dfs(val+1,1);
        }
        else
        {
            flag=true;
            return ;
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(sta,0,sizeof(sta));
        for(int i=1; i<=10; i++)
            scanf("%d",&a[i]);
        flag=false;
        dfs(1,0);
        dfs(1,1);
        if(flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
