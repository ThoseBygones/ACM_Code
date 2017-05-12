#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 100005

char a[MAXN];    //��������
int next[MAXN]; //ƥ��ʧ�ܼ�¼
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
        ans=len-next[len];  //��ѭ���ڵĳ���
        if(ans!=len && len%ans==0)  //������ѭ�����Ҳ���Ҫ����
            puts("0");
        else
        {
            int add=ans-next[len]%ans;
            printf("%d\n",add);
        }
    }
    return 0;
}
