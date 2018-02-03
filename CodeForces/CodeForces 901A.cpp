#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define LL long long

int a[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<=n; i++)
        scanf("%d",&a[i]);
    bool flag=true;
    for(int i=0; i<n; i++)
    {
        if(a[i]>1 && a[i+1]>1)
            flag=false;
    }
    if(flag)
        puts("perfect");
    else
    {
        puts("ambiguous");
        int root=0;
        //打印第一种同构的情况
        for(int i=0; i<=n; i++) //逐层遍历
        {
            for(int j=1; j<=a[i]; j++)
                printf("%d ",root);
            root+=a[i];
        }
        puts("");
        //打印第二种同构的情况
        root=0;
        for(int i=0; i<=n; i++) //逐层遍历
        {
            if(i!=0 && a[i-1]!=1 && a[i]!=1)    //上一层不止一个结点，该层也不止一个结点
            {
                for(int j=1; j<=a[i]-1; j++)    //该层的结点不都连到上一层的最后一个结点（故意留一个）
                    printf("%d ",root);
                printf("%d ",root-1);   //故意留一个连到上一层的倒数第二个结点
            }
            else
            {
                for(int j=1; j<=a[i]; j++)
                    printf("%d ",root);
            }
            root+=a[i];
        }
    }
    return 0;
}
