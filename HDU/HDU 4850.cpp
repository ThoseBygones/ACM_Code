//构造欧拉回路
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <map>
using namespace std;

#define MAXN 500005
#define INF 0x3f3f3f3f
#define PII pair
#define MP make_pair
#define LL long long
#define PB push_back
#define MOD 1000000007

int a[MAXN];
int vis[30][30][30][30];

int main()
{
    int cnt=0;
    for(int i=0; i<26; i++)
    {
        for(int j=0; j<4; j++)
            a[cnt++]=i;
    }
    for(int i=0; i<cnt-3; i++)
        vis[a[i]][a[i+1]][a[i+2]][a[i+3]]=1;
    bool flag=true;
    while(flag)
    {
        flag=false;
        for(int i=0; i<26; i++)
        {
            if(!vis[a[cnt-3]][a[cnt-2]][a[cnt-1]][i])
            {
                vis[a[cnt-3]][a[cnt-2]][a[cnt-1]][i]=1;
                a[cnt++]=i;
                flag=true;
            }
        }
    }
    int n;
    while(~scanf("%d",&n))
    {
        if(n>cnt)
            puts("Impossible");
        else
        {
            for(int i=0; i<n; i++)
                printf("%c",a[i]+'a');
            puts("");
        }
    }
    return 0;
}
