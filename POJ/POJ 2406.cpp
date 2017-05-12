#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 1000005

char a[MAXN];    //模式串长度
int next[MAXN]; //匹配失败记录
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
        if(a[0]=='.')
            break;
        len=strlen(a);
        getNext();
        int ans=1;
        int sum=len-next[len];
        if(len%sum==0)
            ans=len/sum;
        printf("%d\n",ans);
    }
    return 0;
}
