#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 1000005
#define MAXM 1000005

char a[MAXM];
int next[MAXM]; //Æ¥ÅäÊ§°Ü¼ÇÂ¼
int ans[MAXN];
int n,m;
int cnt;

void getNext(int len)
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

void KMP(int len)
{
    int t=len-1;
    cnt=0;
    while(t>-1)
    {
        if(a[t]==a[len-1])
            ans[cnt++]=len-t-1;
        t=next[t];
    }
}

int main()
{
    int t,kase=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        int len=strlen(a);
        getNext(len);
        KMP(len);
        printf("Case #%d: %d\n",kase++,cnt);
        for(int i=1; i<cnt; i++)
            printf("%d ",ans[i]);
        printf("%d\n",len);
    }
    return 0;
}
