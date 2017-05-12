#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1005

int main()
{
    string a,b;
    cin >> a >> b;
    if(a==b)
        puts("-1");
    else
        cout << max(a.size(),b.size()) << endl;
    return 0;
}
