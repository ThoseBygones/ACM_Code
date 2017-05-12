#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 100005

char a[MAXN];    //主串长度
int next[MAXN]; //匹配失败记录
int n,m;
int len;
int ans;

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
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        len=strlen(a);
        getNext();
        ans=len-next[len];  //求循环节的长度
        if(ans!=len && len%ans==0)  //若存在循环节且不需要补节
            puts("0");
        else
        {
            int add=ans-next[len]%ans;
            printf("%d\n",add);
        }
    }
    return 0;
}
