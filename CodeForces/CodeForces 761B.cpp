#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 105

int a[MAXN];
int b[MAXN];
int disa[MAXN];
int disb[MAXN];

int main()
{
    int n,l;
    scanf("%d%d",&n,&l);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=n; i++)
        scanf("%d",&b[i]);
    for(int i=1; i<n; i++)
        disa[i]=a[i+1]-a[i];
    for(int i=1; i<n; i++)
        disb[i]=b[i+1]-b[i];
    disa[n]=l-a[n]+a[1];
    disb[n]=l-b[n]+b[1];
    /*for(int i=1; i<=n; i++)
        cout << disa[i] << " ";
    cout << endl;
    for(int i=1; i<=n; i++)
        cout << disb[i] << " ";
    cout << endl;*/
    bool flag;
    for(int i=1; i<=n; i++)
    {
        flag=true;
        for(int j=1; j<=n; j++)
        {
            int p1=j;
            int p2=j+i;
            if(p2>n)
                p2-=n;
            if(disa[p1]!=disb[p2])
            {
                flag=false;
                break;
            }
        }
        if(flag)
            break;
    }
    if(flag)
        puts("YES");
    else
        puts("NO");
    return 0;
}
