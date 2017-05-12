#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 500005

string hashtag[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        cin >> hashtag[i];
    for(int i=n-2; i>=0; i--)
    {
        if(hashtag[i]<=hashtag[i+1])
            continue;
        int len1=hashtag[i].length();
        int len2=hashtag[i+1].length();
        for(int j=1; j<len1; j++)
        {
            if(hashtag[i][j]>hashtag[i+1][j] || j>=len2)
            {
                hashtag[i]=hashtag[i].substr(0,j);
                break;
            }
        }
    }
    for(int i=0; i<n; i++)
        cout << hashtag[i] << endl;
    return 0;
}
