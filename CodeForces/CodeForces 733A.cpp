#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char vowel[10]= {'A','E','I','O','U','Y'};
char alp[105];

int main()
{
    alp[0]='A';
    cin >> alp+1;
    int len=strlen(alp);
    alp[len]='A';
    int ans=0;
    int p=0;
    for(int i=1; i<=len; i++)
    {
        for(int j=0; j<6; j++)
        {
            if(alp[i]==vowel[j])
            {
                ans=max(ans,i-p);
                p=i;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
