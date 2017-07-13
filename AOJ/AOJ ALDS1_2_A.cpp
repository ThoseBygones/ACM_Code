#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105

int cnt;

void bubble_sort(int a[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=n-1; j>=i+1; j--)
        {
            if(a[j]<a[j-1])
            {
                swap(a[j],a[j-1]);
                cnt++;
            }

        }
    }
}

int main()
{
    int a[MAXN];
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    cnt=0;
    bubble_sort(a,n);
    for(int i=0; i<n-1; i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n-1]);
    printf("%d\n",cnt);
    return 0;
}
