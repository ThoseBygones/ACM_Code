#include <iostream>
#include <algorithm>
using namespace std;

int a[10005],n;

int dfs(int l,int r,int k)
{
    if(l>r)
       return 0;
    if(r==l)
    {
        if(a[r]<=k)
          return 0;
        else
          return 1;
    }
    int m=min_element(a+l,a+r+1)-a;
    return min(r-l+1,dfs(l,m-1,a[m])+dfs(m+1,r,a[m])+a[m]-k);
}
int main()
{
    while(cin >> n)
    {
        for(int i=1;i<=n;i++)
            cin >> a[i];
        cout << dfs(1,n,0) << endl;
    }
    return 0;
}

