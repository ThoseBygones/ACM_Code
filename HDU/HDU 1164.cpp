#include<iostream>
using namespace std;

int prime[1005];

int main()
{
    int n;
    while(cin >> n)
    {
        int i=2,j=0;
        while(i<=n)
        {
            if(n%i==0)
            {
                n/=i;
                prime[j++]=i;
                i=2;
            }
            else
                i++;
        }
        for(int k=0; k<j; k++)
        {
            if(k==j-1)
                cout << prime[k] << endl;
            else
                cout << prime[k] << '*';
        }
    }
    return 0;
}
