#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 105

int main()
{
    string str[2];
    int n;
    string kill,rep;
    cin >> str[0] >> str[1];
    scanf("%d",&n);
    cout << str[0] << " " << str[1] << endl;
    for(int i=1; i<=n; i++)
    {
        cin >> kill >> rep;
        for(int i=0; i<2; i++)
        {
            if(str[i]==kill)
            {
                str[i]=rep;
                break;
            }
        }
        cout << str[0] << " " << str[1] << endl;
    }
    return 0;
}
