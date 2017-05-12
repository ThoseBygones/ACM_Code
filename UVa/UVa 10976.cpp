#include <iostream>
using namespace std;

int main()
{
    int k;
    while(cin >> k)
    {
        int cnt=0;
        for(int i=k+1; i<=2*k; i++)
        {
            if((i*k)%(i-k)==0)
            {
                int temp=(i*k)/(i-k);
                if(temp>=i)
                    cnt++;
            }
        }
        cout << cnt << endl;
        for(int i=k+1; i<=2*k; i++)
        {
            if((i*k)%(i-k)==0)
            {
                int temp=(i*k)/(i-k);
                if(temp>=i)
                    cout << "1/" << k << " = 1/" << temp << " + 1/" << i << endl;
            }
        }
    }
    return 0;
}
