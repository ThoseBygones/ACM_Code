#include <iostream>
#include <cstring>
using namespace std;

char tot[100005],a[105],b[105];

int main()
{
    cin >> tot >> a >> b;
    int fullLen=strlen(tot);
    int lenA=strlen(a);
    int lenB=strlen(b);
    bool flagA1=false,flagB1=false,flagA2=false,flagB2=false;
    int tempPos=0;
    for(int i=0; i<fullLen; i++)    //正向寻找
    {
        flagA1=true;
        for(int j=0; j<lenA; j++)
        {
            if(tot[i+j] != a[j])
            {
                flagA1=false;
                break;
            }
        }
        if(flagA1)
        {
            tempPos=i+lenA;
            break;
        }
    }
    if(flagA1)
    {
        for(int i=tempPos; i<fullLen; i++)
        {
            flagB1=true;
            for(int j=0; j<lenB; j++)
            {
                if(tot[i+j] != b[j])
                {
                    flagB1=false;
                    break;
                }
            }
            if(flagB1)
                break;
        }
    }
    for(int i=fullLen-1; i>=0; i--)    //反向寻找
    {
        flagA2=true;
        for(int j=0; j<lenA; j++)
        {
            if(tot[i-j] != a[j])
            {
                flagA2=false;
                break;
            }
        }
        if(flagA2)
        {
            tempPos=i-lenA;
            break;
        }
    }
    if(flagA2)
    {
        for(int i=tempPos; i>=0; i--)
        {
            flagB2=true;
            for(int j=0; j<lenB; j++)
            {
                if(tot[i-j] != b[j])
                {
                    flagB2=false;
                    break;
                }
            }
            if(flagB2)
                break;
        }
    }
    if(flagB1 && flagB2)
        cout << "both" << endl;
    else if(flagB1)
        cout << "forward" << endl;
    else if(flagB2)
        cout << "backward" << endl;
    else
        cout << "fantasy" << endl;
    return 0;
}
