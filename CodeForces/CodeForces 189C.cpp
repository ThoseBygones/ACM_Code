#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int a[MAXN],b[MAXN];
int num[MAXN];  //a����ÿ��Ԫ�����b������ÿ��Ԫ�صı��

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=n; i++)
        scanf("%d",&b[i]);
    for(int i=1; i<=n; i++)
        num[b[i]]=i;    //���˳��
    int ans=0;
    for(int i=1; i<n; i++)
    {
        if(num[a[i]]>num[a[i+1]])
        {
            //cout << i << endl;
            ans=n-i;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
