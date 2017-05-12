#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 1000005
#define MAXM 10005

char a[MAXM];    //主串长度
char b[MAXN];    //模式串长度
int next[MAXM]; //匹配失败记录
int n,m;
int lena,lenb;

void getNext()
{
    int i = 0;
    int j = -1;
    memset(next,0,sizeof(next));
    next[0] = -1;
    while(i<lenb)
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
    int cnt = 0;
    while(i<lena)
    {
        if(b[j] == a[i] || j == -1) //如果字母相等，两串指针均右移
        {
            i++;
            j++;
        }
        else
            j = next[j];    //j回移值上一次匹配失败的位置（回移尽可能短的路程）
        if(j == lenb)
        {
            cnt++;
            j = 0;
        }
    }
    return cnt;
}

int main()
{
    int ans;
    while(~scanf("%s",a))
    {
        if(a[0]=='#')
            break;
        scanf("%s",b);
        lena=strlen(a);
        lenb=strlen(b);
        if(lena<lenb)
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
