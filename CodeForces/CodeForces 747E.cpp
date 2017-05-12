#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1000005

struct Chat
{
    int l;
    int r;
};  //字段的区间

vector <Chat> ans[MAXN];

char str[MAXN];
int len;
int depth;  //树的深度
int p;

int getNum(int s)
{
    int val=0;
    p=s;
    while(str[p]!=',' && p<len)
    {
        val=val*10+str[p]-'0';
        p++;
    }
    return val;
}

void dfs(int d)
{
    depth=max(depth,d);
    if(str[p]==',')
        p++;
    Chat temp;
    temp.l=p;
    while(str[p]!=',' && p<len)
        p++;
    temp.r=p-1;
    ans[d].push_back(temp);
    int num=getNum(p+1);
    while(num--)
        dfs(d+1);
}

void display(Chat x)
{
    for(int i=x.l; i<=x.r; i++)
        printf("%c",str[i]);
    //printf(" ");
}

int main()
{
    scanf("%s",str);
    len=strlen(str);
    depth=0;
    p=0;
    while(p<len)
        dfs(1);
    printf("%d\n",depth);
    for(int i=1; i<=depth; i++)
    {
        for(int j=0; j<ans[i].size()-1; j++)
        {
            display(ans[i][j]);
            printf(" ");
        }
        display(ans[i][ans[i].size()-1]);
        puts("");
    }
    return 0;
}
