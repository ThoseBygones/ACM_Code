#include <iostream>
using namespace std;

int c[100005];

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> c[i];
    int sum1=0,sum2=0;
    int cnt1=0,cnt2=0;
    int left=1,right=n;
    while(left<=right)
    {
        if(sum1<=sum2)
        {
            sum1+=c[left++];
            cnt1++;
        }
        else
        {
            sum2+=c[right--];
            cnt2++;
        }
    }
    cout << cnt1 << " " << cnt2 << endl;
    return 0;
}
