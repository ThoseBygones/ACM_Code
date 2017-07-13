#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 1000005

int cnt;
int a[MAXN];
int n;
vector <int> v;

void insertion_sort(int n,int m)
{
    for(int i=m+1; i<=n; i++)
    {
        int temp=a[i];
        int j=i-m;
        while(j>0 && a[j]>temp)
        {
            a[j+m]=a[j];
            j-=m;
            cnt++;
        }
        a[j+m]=temp;
    }
}

void shell_sort(int n)
{
    for(int i=1; i<=n; i=2*i+1)
        v.push_back(i);
    for(int i=v.size()-1; i>=0; i--)
        insertion_sort(n,v[i]);
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    cnt=0;
    shell_sort(n);
    printf("%d\n",v.size());
    for(int i=v.size()-1; i>0; i--)
        printf("%d ",v[i]);
    printf("%d\n",v[0]);
    printf("%d\n",cnt);
    for(int i=1; i<=n; i++)
        printf("%d\n",a[i]);
    return 0;
}
