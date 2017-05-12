#include <iostream>
using namespace std;

int main()
{
    int kase;
    cin >> kase;
    while(kase--)
    {
        int ah,am,as,bh,bm,bs,h,m,s;
        cin >> ah >> am >> as >> bh >> bm >> bs;
        h=ah+bh;
        m=am+bm;
        s=as+bs;
        if(s>=60)
        {
            s-=60;
            m++;
        }
        if(m>=60)
        {
            m-=60;
            h++;
        }
        cout << h << " " << m << " " << s << endl;
    }
    return 0;
}
