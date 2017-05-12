#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 50005
#define MAXM 50005

char a[MAXN];    //模式串长度
char b[MAXM];    //主串长度
int next[MAXM]; //匹配失败记录
int n,m;
int lena,lenb;

void getNext()
{
    int i = 0;
    int j = -1;
    next[0] = -1;
    while(i<lena)
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

int KMP()
{
    int i = 0,j = 0;
    while(i<lenb)
    {
        if(j == -1 || a[j] == b[i])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    return j;
}

int main()
{
    while(~scanf("%s%s",a,b))
    {
        lena=strlen(a);
        lenb=strlen(b);
        getNext();
        int cnt=KMP();
        //printf("%d\n",cnt);
        for(int i=0; i<cnt; i++)
            printf("%c",a[i]);
        if(cnt)
            printf(" ");
        printf("%d\n",cnt);
    }
    return 0;
}
