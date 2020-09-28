/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-09-23
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: AOJ
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

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
//#include <bits/stdc++.h>
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int DEFAULT_SIZE = 100;
struct BigInteger : vector<long long>
{
    static const long long BASE = 100000000;
    static const int BASE_DIGIT = 8;
    int sign;

    // constructor
    BigInteger(long long num = 0) : vector<long long>(DEFAULT_SIZE, 0), sign(1)
    {
        if (num < 0) sign = -1, num = -num;
        (*this)[0] = num;
        this->normalize();
    }
    BigInteger(int size, long long num) : vector<long long>(size, num), sign(1) {}
    BigInteger& normalize()
    {
        long long c = 0;
        bool exist = false;
        for (int i = 0;; ++i)
        {
            if (i >= this->size()) this->push_back(0);
            if ((*this)[i] < 0 && i+1 >= this->size()) this->push_back(0);
            while ((*this)[i] < 0)
            {
                (*this)[i+1] -= 1;
                (*this)[i] += BASE;
            }
            long long a = (*this)[i] + c;
            (*this)[i] = a % BASE;
            if ((*this)[i]) exist = true;
            c = a / BASE;
            if (c == 0 && i == this->size()-1) break;
        }
        if (!exist) sign = 1;
        return (*this);
    }
    friend BigInteger abs(const BigInteger &x)
    {
        BigInteger z = x;
        if (z.sign == -1) z.sign = 1;
        return z;
    }
    friend ostream &operator << (ostream &os, const BigInteger &x)
    {
        if (x.sign == -1) os << '-';
        int d = x.size()-1;
        for (d = x.size()-1; d >= 0; --d) if (x[d] > 0) break;
        if (d == -1) os << 0;
        else os << x[d];
        for (int i = d-1; i >= 0; --i)
        {
            os.width(BigInteger::BASE_DIGIT);
            os.fill('0');
            os << x[i];
        }
        return os;
    }

    // operation
    BigInteger operator - () const
    {
        BigInteger res = *this;
        bool allzero = true;
        for (int i = 0; i < this->size(); ++i)
        {
            if (res[i] != 0)
            {
                allzero = false;
                break;
            }
        }
        if (!allzero) res.sign = -res.sign;
        return res;
    }
    BigInteger& operator += (const BigInteger& r)
    {
        while (size() < r.size()) this->emplace_back(0);
        if (sign == r.sign)
        {
            for (int i = 0; i < r.size(); ++i) (*this)[i] += r[i];
        }
        else
        {
            if (sign == 1 && abs(*this) < abs(r)) sign = -1;
            else if (sign == -1 && abs(*this) <= abs(r)) sign = 1;
            if (abs(*this) >= abs(r))
            {
                for (int i = 0; i < r.size(); ++i) (*this)[i] -= r[i];
            }
            else
            {
                for (int i = 0; i < size(); ++i) (*this)[i] = -(*this)[i];
                for (int i = 0; i < r.size(); ++i) (*this)[i] += r[i];
            }
        }
        return this->normalize();
    }
    BigInteger& operator -= (const BigInteger& r)
    {
        while (size() < r.size()) this->emplace_back(0);
        if (sign == -r.sign)
        {
            for (int i = 0; i < r.size(); ++i) (*this)[i] += r[i];
        }
        else
        {
            if (sign == 1 && abs(*this) < abs(r)) sign = -1;
            else if (sign == -1 && abs(*this) <= abs(r)) sign = 1;
            if (abs(*this) >= abs(r))
            {
                for (int i = 0; i < r.size(); ++i) (*this)[i] -= r[i];
            }
            else
            {
                for (int i = 0; i < size(); ++i) (*this)[i] = -(*this)[i];
                for (int i = 0; i < r.size(); ++i) (*this)[i] += r[i];
            }
        }
        return this->normalize();
    }
    BigInteger& operator *= (long long r)
    {
        if ( (sign == 1 && r >= 0) || (sign == -1 && r < 0) ) sign = 1;
        else sign = -1;
        if (r < 0) r = -r;
        for (int i = 0; i < size(); ++i) (*this)[i] *= r;
        return this->normalize();
    }
    BigInteger& operator *= (const BigInteger& r)
    {
        int tx = (int)size()-1, ty = (int)r.size()-1;
        for (tx = size()-1; tx >= 0; --tx) if ((*this)[tx] > 0) break;
        for (ty = r.size()-1; ty >= 0; --ty) if (r[ty] > 0) break;
        BigInteger res(0);
        res.resize(tx+ty+2);
        if (sign == r.sign) res.sign = 1;
        else res.sign = -1;
        for (int i = 0; i <= tx; ++i)
        {
            for (int j = 0; j <= ty && i+j < (int)res.size()-1; ++j)
            {
                long long val = (*this)[i] * r[j] + res[i+j];
                res[i+j+1] += val / BigInteger::BASE;
                res[i+j] = val % BigInteger::BASE;
            }
        }
        return (*this) = res.normalize();
    }
    friend BigInteger pow(const BigInteger& a, long long n)
    {
        BigInteger res(1), b = a;
        while (n > 0)
        {
            if (n & 1) res = res * b;
            b = b * b;
            n >>= 1;
        }
        return res;
    }
    BigInteger operator + (const BigInteger& r) const
    {
        return BigInteger(*this) += r;
    }
    BigInteger operator - (const BigInteger& r) const
    {
        return BigInteger(*this) -= r;
    }
    BigInteger operator * (long long r) const
    {
        return BigInteger(*this) *= r;
    }
    BigInteger operator * (const BigInteger& r) const
    {
        return BigInteger(*this) *= r;
    }

    // divide
    BigInteger& operator /= (long long r)
    {
        if (r < 0) sign *= -1, r = -r;
        long long c = 0, t = 0;
        for (int i = (int)size()-1; i >= 0; --i)
        {
            t = BigInteger::BASE * c + (*this)[i];
            (*this)[i] = t / r;
            c = t % r;
        }
        this->normalize();
        return (*this);
    }
    long long operator %= (long long r)
    {
        if (r < 0) sign *= -1, r = -r;
        long long c = 0, t = 0;
        for (int i = (int)size()-1; i >= 0; --i)
        {
            t = BigInteger::BASE * c + (*this)[i];
            (*this)[i] = t / r;
            c = t % r;
        }
        return c;
    }
    BigInteger operator / (long long r) const
    {
        return BigInteger(*this) /= r;
    }
    long long operator % (long long r) const
    {
        return BigInteger(*this) %= r;
    }
    friend pair<BigInteger, BigInteger> divmod(const BigInteger &a, const BigInteger &r)
    {
        BigInteger zero = 0, s = 0, t = 0;
        if (abs(a) < abs(r)) return {zero, a};
        BigInteger ar = abs(r);
        s.resize((int)a.size()), t.resize((int)r.size());
        int tx = (int)a.size()-1;
        for (; tx >= 0; --tx) if (a[tx] > 0) break;
        for (int i = tx; i >= 0; --i)
        {
            t = t * BigInteger::BASE + a[i];
            long long lo = 0, hi = BigInteger::BASE;
            if (t >= ar)
            {
                while (hi - lo > 1)
                {
                    int mid = (hi + lo) / 2;
                    if (ar * mid > t) hi = mid;
                    else lo = mid;
                }
                t -= ar * lo;
            }
            s[i] = lo;
        }
        if (a.sign == r.sign) s.sign = 1, t.sign = 1;
        else s.sign = -1, t.sign = 1;
        return make_pair(s.normalize(), t.normalize());
    }
    BigInteger operator / (const BigInteger& r) const
    {
        return divmod((*this), r).first;
    }
    BigInteger operator % (const BigInteger& r) const
    {
        return divmod((*this), r).second;
    }
    BigInteger& operator /= (const BigInteger& r)
    {
        return (*this) = (*this) / r;
    }
    BigInteger& operator %= (const BigInteger& r)
    {
        return (*this) = (*this) % r;
    }

    // equality
    friend bool operator < (const BigInteger &x, const BigInteger& y)
    {
        if (x.sign < y.sign) return true;
        else if (x.sign > y.sign) return false;
        else
        {
            int tx = (int)x.size()-1, ty = (int)y.size()-1;
            for (tx = x.size()-1; tx >= 0; --tx) if (x[tx] > 0) break;
            for (ty = y.size()-1; ty >= 0; --ty) if (y[ty] > 0) break;
            if (tx < ty) return true;
            else if (tx > ty) return false;
            else if (x.sign == 1)
            {
                for (int i = tx; i >= 0; --i)
                    if (x[i] != y[i]) return x[i] < y[i];
                return false;
            }
            else
            {
                for (int i = tx; i >= 0; --i)
                    if (x[i] != y[i]) return x[i] > y[i];
                return false;
            }
        }
    }
    friend bool operator > (const BigInteger& x, const BigInteger& y)
    {
        return y < x;
    }
    friend bool operator <= (const BigInteger& x, const BigInteger& y)
    {
        return !(x > y);
    }
    friend bool operator >= (const BigInteger& x, const BigInteger& y)
    {
        return !(x < y);
    }
    friend bool operator == (const BigInteger &x, const BigInteger& y)
    {
        if (x.sign != y.sign) return false;
        int tx = (int)x.size()-1, ty = (int)y.size()-1;
        for (tx = x.size()-1; tx >= 0; --tx) if (x[tx] > 0) break;
        for (ty = y.size()-1; ty >= 0; --ty) if (y[ty] > 0) break;
        if (tx != ty) return false;
        for (int i = tx; i >= 0; --i)
            if (x[i] != y[i]) return false;
        return true;
    }
    friend bool operator != (const BigInteger& x, const BigInteger& y)
    {
        return !(x == y);
    }
};

BigInteger toBigInteger(const string &is)
{
    string s = is;
    if (s[0] == '-') s = s.substr(1);
    while (s.size() % 8 != 0) s = "0" + s;
    int N = (int)s.size();
    BigInteger res(N/8, 0);
    for (int i = 0; i < (int)s.size(); ++i)
    {
        res[(N-i-1)/8] *= 10;
        res[(N-i-1)/8] += s[i] - '0';
    }
    if (is[0] == '-') res.sign = -1;
    return res;
}

string toStr(const BigInteger &r)
{
    stringstream ss;
    if (r.sign == -1) ss << '-';
    int d = (int)r.size()-1;
    for (; d >= 0; --d) if (r[d] > 0) break;
    if (d == -1) ss << 0;
    else ss << r[d];
    for (int i = d-1; i >= 0; --i)
    {
        ss.width(BigInteger::BASE_DIGIT);
        ss.fill('0');
        ss << r[i];
    }
    return ss.str();
}

int main()
{
    string A, B;
    cin >> A >> B;
    cout << toBigInteger(A) - toBigInteger(B) << endl;
}
