#include <bits/stdc++.h>
using namespace std;

int main()
{
    //cin.sync_with_stdio(false);
    srand((unsigned)time(NULL));
    int n,start,x;
    int val,nxt;
    cin >> n >> start >> x;
    int ans=-1;
    int pos=start;
    for(int i=0; i<1000; i++)
    {
        val=rand()*rand()%n+1;  //一个rand()能随机到的值太小，不足以覆盖0~1e9
        cout << "? " << val << endl;
        fflush(stdout);
        cin >> val >> nxt;
        if (val>ans && val<x)
        {
            ans=val;
            pos=nxt;
        }
    }
    for(int i=1; i<1000; i++)
    {
        if(pos==-1)
            break;
        cout << "? " << pos << endl;
        fflush(stdout);
        cin >> val >> nxt;
        if (val>=x)
        {
            cout << "! " << val << endl;
            return 0;
        }
        pos=nxt;
    }
    cout << "! -1" << endl;
    return 0;
}
