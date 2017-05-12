#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 400005
#define MAXM 400005

char a[MAXM];
int next[MAXM]; //匹配失败记录
int ans[MAXN];
int n,m;
int len;

void getNext()
{
    int i = 0;
    int j = -1;
    memset(next,0,sizeof(next));
    next[0] = -1;
    while(i<len)
    {
        if(j == -1 || a[i] == a[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

int main()
{
    while(~scanf("%s",a))
    {
        len=strlen(a);
        getNext();
        int cnt=0;
        int temp=next[len-1];
        while(temp!=-1)
        {
            if(a[temp]==a[len-1])
                ans[cnt++]=temp+1;
            temp=next[temp];
        }
        /*第二种写法
        int temp=next[len];
        while(temp!=0)
        {
            ans[cnt++]=temp;
            temp=next[temp];
        }
        */
        for(int i=cnt-1; i>=0; i--)
            printf("%d ",ans[i]);
        printf("%d\n",len);
    }
    return 0;
}
