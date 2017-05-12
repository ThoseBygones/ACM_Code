#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 1000005
#define MAXM 10005

char a[MAXM];    //模式串长度
char b[MAXN];    //主串长度
int next[MAXM]; //匹配失败记录
int n,m;
int lena,lenb;

void getNext()
{
    int i = 0;
    int j = -1;
    memset(next,0,sizeof(next));
    next[0] = -1;
    while(i<lena)
    {
        if(j == -1 || a[i] == a[j])
        {
            i++;
            j++;
            if(a[i] == a[j])
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
    int cnt = 0;
    while(i<lenb)
    {
        if(a[j] == b[i] || j == -1) //如果字母相等，两串指针均右移
        {
            i++;
            j++;
        }
        else
            j = next[j];    //j回移值上一次匹配失败的位置（回移尽可能短的路程）
        if(j == lena)
        {
            cnt++;
            j = next[j];
        }
    }
    return cnt;
}

int main()
{
    int t;
    scanf("%d",&t);
    int ans;
    while(t--)
    {
        scanf("%s",a);
        scanf("%s",b);
        lena=strlen(a);
        lenb=strlen(b);
        if(n<m)
            puts("0");
        else
        {
            getNext();
            ans=KMP();
        }
        printf("%d\n",ans);
    }
    return 0;
}
