/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V6.0
 *  Date: 2018-02-12
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: POJ
 *  Algorithm: 高精度乘法
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#include <bits/stdc++.h>  //For CodeForces only

//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
template<class T> inline T sqr(T x)
{
    return x * x;
}
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<LL, LL> PLL;
typedef pair<LL, int> PLI;
typedef pair<LD, LD> PDD;
#define MP make_pair
#define PB push_back
#define sz(x) ((int)(x).size())
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

using namespace std;

struct BigInteger
{
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;

    BigInteger& clean()
    {
        while(!s.back()&&s.size()>1)
            s.pop_back();
        return *this;
    }
    BigInteger(ULL num = 0)
    {
        *this = num;
    }
    BigInteger(string s)
    {
        *this = s;
    }
    BigInteger& operator = (long long num)
    {
        s.clear();
        do
        {
            s.push_back(num % BASE);
            num /= BASE;
        }
        while (num > 0);
        return *this;
    }
    BigInteger& operator = (const string& str)
    {
        s.clear();
        int x, len = (str.length() - 1) / WIDTH + 1;
        for (int i = 0; i < len; i++)
        {
            int end = str.length() - i*WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start,end-start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return (*this).clean();
    }

    BigInteger operator + (const BigInteger& b) const
    {
        BigInteger c;
        c.s.clear();
        for (int i = 0, g = 0; ; i++)
        {
            if (g == 0 && i >= s.size() && i >= b.s.size())
                break;
            int x = g;
            if (i < s.size())
                x += s[i];
            if (i < b.s.size())
                x += b.s[i];
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }
    BigInteger operator - (const BigInteger& b) const
    {
        assert(b <= *this); // 减数不能大于被减数
        BigInteger c;
        c.s.clear();
        for (int i = 0, g = 0; ; i++)
        {
            if (g == 0 && i >= s.size() && i >= b.s.size())
                break;
            int x = s[i] + g;
            if (i < b.s.size())
                x -= b.s[i];
            if (x < 0)
            {
                g = -1;
                x += BASE;
            }
            else
                g = 0;
            c.s.push_back(x);
        }
        return c.clean();
    }
    BigInteger operator * (const BigInteger& b) const
    {
        int i, j;
        ULL g;
        vector<ULL> v(s.size()+b.s.size(), 0);
        BigInteger c;
        c.s.clear();
        for(i=0; i<s.size(); i++)
            for(j=0; j<b.s.size(); j++)
                v[i+j]+=ULL(s[i])*b.s[j];
        for (i = 0, g = 0; ; i++)
        {
            if (g ==0 && i >= v.size())
                break;
            ULL x = v[i] + g;
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c.clean();
    }
    BigInteger operator / (const BigInteger& b) const
    {
        assert(b > 0);  // 除数必须大于0
        BigInteger c = *this;       // 商:主要是让c.s和(*this).s的vector一样大
        BigInteger m;               // 余数:初始化为0
        for (int i = s.size()-1; i >= 0; i--)
        {
            m = m*BASE + s[i];
            c.s[i] = bsearch(b, m);
            m -= b*c.s[i];
        }
        return c.clean();
    }
    BigInteger operator % (const BigInteger& b) const   //方法与除法相同
    {
        BigInteger c = *this;
        BigInteger m;
        for (int i = s.size()-1; i >= 0; i--)
        {
            m = m*BASE + s[i];
            c.s[i] = bsearch(b, m);
            m -= b*c.s[i];
        }
        return m;
    }
    // 二分法找出满足bx<=m的最大的x
    int bsearch(const BigInteger& b, const BigInteger& m) const
    {
        int L = 0, R = BASE-1, x;
        while (1)
        {
            x = (L+R)>>1;
            if (b*x<=m)
            {
                if (b*(x+1)>m)
                    return x;
                else
                    L = x;
            }
            else
                R = x;
        }
    }
    BigInteger& operator += (const BigInteger& b)
    {
        *this = *this + b;
        return *this;
    }
    BigInteger& operator -= (const BigInteger& b)
    {
        *this = *this - b;
        return *this;
    }
    BigInteger& operator *= (const BigInteger& b)
    {
        *this = *this * b;
        return *this;
    }
    BigInteger& operator /= (const BigInteger& b)
    {
        *this = *this / b;
        return *this;
    }
    BigInteger& operator %= (const BigInteger& b)
    {
        *this = *this % b;
        return *this;
    }

    bool operator < (const BigInteger& b) const
    {
        if (s.size() != b.s.size())
            return s.size() < b.s.size();
        for (int i = s.size()-1; i >= 0; i--)
            if (s[i] != b.s[i])
                return s[i] < b.s[i];
        return false;
    }
    bool operator >(const BigInteger& b) const
    {
        return b < *this;
    }
    bool operator<=(const BigInteger& b) const
    {
        return !(b < *this);
    }
    bool operator>=(const BigInteger& b) const
    {
        return !(*this < b);
    }
    bool operator!=(const BigInteger& b) const
    {
        return b < *this || *this < b;
    }
    bool operator==(const BigInteger& b) const
    {
        return !(b < *this) && !(b > *this);
    }
};

ostream& operator << (ostream& out, const BigInteger& x)
{
    out << x.s.back();
    for (int i = x.s.size()-2; i >= 0; i--)
    {
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        for (int j = 0; j < strlen(buf); j++)
            out << buf[j];
    }
    return out;
}

istream& operator >> (istream& in, BigInteger& x)
{
    string s;
    if (!(in >> s))
        return in;
    x = s;
    return in;
}

int main()
{
    int n;
    scanf("%d",&n);
    BigInteger x = 2;
    for(int i=1; i<=n; i++)
    {
        cout << x << endl;
        x = x * (x - 1) + 1;
    }
    return 0;
}

