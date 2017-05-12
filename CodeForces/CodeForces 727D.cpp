#include <iostream>
#include <string>
using namespace std;

string s[100005];
string sig[6]={"S","M","L","XL","XXL","XXXL"};
string dou[5]={"S,M","M,L","L,XL","XL,XXL","XXL,XXXL"};
int n,cnt[6];

int main()
{
    for(int i=0; i<6; i++)
        cin >> cnt[i];
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> s[i];
        for(int j=0; j<6; j++)
        {
            if(s[i]==sig[j])
            {
                cnt[j]--;
                break;
            }
        }
    }
    for(int i=0; i<6; i++)
    {
        if(cnt[i]<0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(s[j]!=dou[i])
                continue;
            //if(s[j]==dou[i])
            //{
                if(cnt[i]>0)
                {
                    cnt[i]--;
                    s[j]=sig[i];
                    continue;
                }
                if(cnt[i+1]>0)
                {
                    cnt[i+1]--;
                    s[j]=sig[i+1];
                    continue;
                }
                cout << "NO" << endl;
                return 0;
            //}
        }
    }
    cout << "YES" << endl;
    for(int i=0; i<n; i++)
        cout << s[i] << endl;
    return 0;
}
