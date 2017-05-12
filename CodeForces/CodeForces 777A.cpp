#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1005
#define INF 0x3f3f3f3f

int shell[3];

int main()
{
    int n,x;
    scanf("%d",&n);
    n%=6;
    scanf("%d",&x);
    shell[x]=1;
    for(int i=n; i>=1; i--)
    {
        if(i%2)
            swap(shell[0],shell[1]);
        else
            swap(shell[1],shell[2]);
    }
    for(int i=0; i<=2; i++)
    {
        if(shell[i])
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
