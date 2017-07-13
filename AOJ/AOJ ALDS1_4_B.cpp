#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100005

int a[MAXN];
int n;

bool bi_search(int val)
{
    int left=0;
    int right=n;
    while(left<=right)
    {
        int mid=(left+right)>>1;
        if(a[mid]==val)
            return true;
        else if(a[mid]<val)
            left=mid+1;
        else
            right=mid-1;
    }
    return false;
}

int main()
{
    int q,val;
    int cnt=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&val);
        if(bi_search(val))
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
