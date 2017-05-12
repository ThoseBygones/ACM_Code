#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 1000005

char a[MAXN];    //主串长度
int next[MAXN]; //匹配失败记录
int n,m;

void getNext()
{
    int i = 0;
    int j = -1;
    memset(next,0,sizeof(next));
    next[0] = -1;
    while(i<n)
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

void KMP()
{
    int p;
    for(int i=2; i<=n; i++)
    {
        p=i-next[i];
        if(i%p==0 && i/p>1)
            printf("%d %d\n",i,i/p);
    }
}

int main()
{
    int kase=1;
    while(~scanf("%d",&n),n)
    {
        scanf("%s",a);
        getNext();
        printf("Test case #%d\n",kase++);
        KMP();
        puts("");
    }
    return 0;
}
