#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[100005],b[100005],c[100005];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<n-1;i++)
            cin >> b[i];
        for(int i=0;i<n-2;i++)
            cin >> c[i];

        sort(a,a+n);
        sort(b,b+n-1);
        sort(c,c+n-2);

        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
            {
                cout << a[i] << endl;
                break;
            }
        }
        for(int i=0;i<n-1;i++)
        {
            if(b[i]!=c[i])
            {
                cout << b[i] << endl;
                break;
            }
        }
    }
    return 0;
}
