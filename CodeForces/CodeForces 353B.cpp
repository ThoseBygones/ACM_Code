#include <iostream>
#define MAXN 205
using namespace std;

int a[MAXN],num[MAXN],heap[MAXN],vis[MAXN];

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=2*n; i++)
    {
        cin >> a[i];
        num[a[i]]++;
    }
    int cnt1=0,cnt2=0;
    for(int i=10; i<100; i++)
    {
        if(num[i])
        {
            if(num[i]>=2)
            {
                cnt1++;
                cnt2++;
            }
            else if(cnt1>cnt2)
            {
                cnt2++;
                heap[i]=2;
            }
            else
            {
                cnt1++;
                heap[i]=1;
            }
        }
    }
    cout << cnt1*cnt2 << endl;
    for(int i=1; i<=2*n; i++)
    {
        if(!vis[a[i]])
        {
            if(heap[a[i]])
                cout << heap[a[i]] << " ";
            else
                cout << "1 ";
            vis[a[i]]++;
        }
        else if(vis[a[i]]==1)
        {
            cout << "2 ";
            vis[a[i]]++;
        }
        else if(cnt1<n)
        {
            cout << "1 ";
            cnt1++;
        }
        else
        {
            cout << "2 ";
            cnt2++;
        }
    }
    cout << endl;
    return 0;
}
