#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 200005
#define INF 0x3f3f3f3f

int a[MAXN];
char t[MAXN];
int pos[MAXN];
char p[MAXN];

int main()
{
    scanf("%s",t);
    scanf("%s",p);
    int len1=strlen(t);
    int len2=strlen(p);
    for(int i=0; i<len1; i++)
    {
        int temp;
        scanf("%d",&temp);
        a[i]=temp-1;
        pos[a[i]]=i;
    }
    /*for(int i=0; i<len; i++)
        printf("%d ",a[i]);
    puts("");
    */
    int l=0,r=len1-1;
    int mid;
    while(l<=r) //二分删除的数字数量
    {
        int k=0;
        mid=(l+r)/2;
        for(int i=0; i<len1 && k<len2; i++)
        {
            if(pos[i]>=mid && t[i]==p[k])
                k++;
        }
        if(k==len2)
            l=mid+1;
        else
            r=mid-1;
    }
    printf("%d\n",l-1);
    return 0;
}
