#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int cnt1=0,cnt2=0;
    for(int i=0; i<n; i++)
    {
        int temp;
        scanf("%d",&temp);
        temp==100?cnt1++:cnt2++;
    }
    puts(cnt1&1 || (!cnt1 && cnt2&1)?"NO":"YES");
    return 0;
}
