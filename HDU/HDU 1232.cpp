#include<iostream>
#include<cstdio>
using namespace std;

int vil[1005];

int findx(int x)
{
    int root=x;
    while(root!=vil[root])
       root=vil[root];
    return root;
}

void merge(int x,int y)
{
    int setx,sety;
    setx=findx(x);
    sety=findx(y);
    if(setx!=sety)
        vil[setx]=sety;
}

int main()
{
    int i,n,m,a,b,count;
    while(scanf("%d",&n),n)
    {
        for(i=1;i<=n;i++)
            vil[i]=i;
        scanf("%d",&m);
        for(i=m;i>0;i--)
        {
            scanf("%d%d",&a,&b);
            merge(a,b);
        }
        count=-1;
        for(i=1;i<=n;i++)
            if(vil[i]==i)
            count++;
        cout<<count<<endl;
    }
    return 0;
}
