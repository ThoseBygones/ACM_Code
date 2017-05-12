#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 1000005

char a[MAXN];    //主串长度
int next[MAXN]; //匹配失败记录
int n,m;
int len;

void getNext()
{
    next[0]=next[1]=0;
    for(int i=1; i<len; i++)
    {
        int j=next[i];
        while(j && a[i]!=a[j])
            j=next[j];
        //next[i+1]=a[i]==a[j]?j+1:0;
        if(a[i]==a[j])
            next[i+1]=j+1;
        else
            next[i+1]=0;
    }
}

int main()
{
    while(~scanf("%s",a))
    {
        len=strlen(a);
        getNext();
        /*
        for(int i=0; i<=len; i++)
            printf("%d ",next[i]);
        puts("");
        */
        int ans=len-next[len];
        printf("%d\n",ans);
    }
    return 0;
}
