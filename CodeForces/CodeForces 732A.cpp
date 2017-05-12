#include <iostream>
using namespace std;

int main()
{
    int k,r,cnt=1;
    cin >> k >> r;
    while(cnt*k%10!=r && cnt*k%10!=0)
        cnt++;
    cout << cnt << endl;
    return 0;
}
