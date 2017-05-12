#include <iostream>
#include <cstring>
using namespace std;

char s[20],excel[20];

void solve1()
{
    int len=strlen(s);
    int num1=0,num2=0;
    int p1;
    for(p1=1; s[p1]>='0' && s[p1]<='9'; p1++)
        num2=num2*10+s[p1]-'0';
    p1++;
    for( ; p1<len; p1++)
        num1=num1*10+s[p1]-'0';
    int cnt=0;
    while(num1)
    {
        if(num1%26==0)
        {
            excel[cnt++]='Z';
            num1=num1/26-1;
        }
        else
        {
            excel[cnt++]=(num1%26)+'A'-1;
            num1=num1/26;
        }
    }
    for(int i=cnt-1; i>=0; i--)
        cout << excel[i];
    cout << num2 << endl;
}

void solve2()
{
    int len=strlen(s);
    int num1=0,num2=0;
    int p2;
    for(p2=0; s[p2]>='A' && s[p2]<='Z'; p2++)
        num1=num1*26+s[p2]-'A'+1;
    for( ; p2<len; p2++)
        num2=num2*10+s[p2]-'0';
    cout << "R" << num2 << "C" << num1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        int len=strlen(s);
        bool flag=false;
        for(int i=1; i<len; i++)
        {
            if(s[i]>='A' && s[i]<='Z' && s[i-1]>='0' && s[i-1]<='9')
            {
                flag=true;
                break;
            }
        }
        if(flag)
            solve1();
        else
            solve2();
    }
    return 0;
}
