#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 1000005
#define MAXM 10005

char a[MAXM];    //ģʽ������
char b[MAXN];    //��������
int next[MAXM]; //ƥ��ʧ�ܼ�¼
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
        if(a[j] == b[i] || j == -1) //�����ĸ��ȣ�����ָ�������
        {
            i++;
            j++;
        }
        else
            j = next[j];    //j����ֵ��һ��ƥ��ʧ�ܵ�λ�ã����ƾ����̵ܶ�·�̣�
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
