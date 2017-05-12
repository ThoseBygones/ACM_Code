#include <iostream>
#include <cstring>
using namespace std;

char s[1010];
int a[100];
long long ans;  //long long才能存下

int main()
{
    cin >> s;
    int len=strlen(s);
    for(int i=0; i<len; i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            int temp=0,p=0;
            for(; (s[i]>='0' && s[i]<='9') || s[i]=='.'; i++)
            {
                if(s[i]=='.')
                    p=i;
                else
                    temp=temp*10+s[i]-'0';
            }
            i--;
            if(i-p==2)  //判断'.'代表的是每三位数字之间的分隔符还是小数点
                ans+=temp;
            else
                ans+=temp*100;
        }
    }
    int cnt;
    for(cnt=0; ans!=0; ans/=10)
        a[++cnt]=ans%10;
    for(int i=cnt; i>3; i--)
    {
        if(i%3==0)
            cout << a[i] << ".";
        else
            cout << a[i];
    }
    cout << a[3];
    if(a[1] || a[2])    //特判：若小数点后两位都为零则不输出小数点和这两位，否则都输出
        cout << "." << a[2] << a[1] << endl;
    else
        cout << endl;
    return 0;
}

/*
chipsy48.32televizor12.390
a1b2c3.38
aa0.01t0.03
*/
