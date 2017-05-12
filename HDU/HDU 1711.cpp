#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 1000005
#define MAXM 10005

int a[MAXN];    //主串长度
int b[MAXM];    //模式串长度
int next[MAXM]; //匹配失败记录
int n,m;

void getNext()
{
    int i = 0;
    int j = -1;
    next[0] = -1;
    while(i<m)
    {
        if(j == -1 || b[i] == b[j])
        {
            i++;
            j++;
            if(b[i] == b[j])
                next[i] = next[j];
            else
                next[i] = j;
        }
        else
            j = next[j];
    }
}

int KMP()
{
    int i = 0,j = 0;
    while(i<n)
    {
        if(a[i] == b[j])
        {
            if(j == m-1)
                return i-j+1;
            i++;
            j++;
        }
        else
        {
            j = next[j];
            if(j == -1)
            {
                i++;
                j = 0;
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(int i=0; i<m; i++)
            scanf("%d",&b[i]);
        if(n<m)
            printf("-1\n");
        else
        {
            getNext();
            printf("%d\n",KMP());
        }
    }
    return 0;
}
