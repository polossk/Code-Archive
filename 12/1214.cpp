// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1214                                             *
*****************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline string nextStr() { string s; cin >> s; return s; }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  nextlld() { int64 d; scanf("%lld", &d); return d; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

class BigInt
{
    private:
        char *digits;
        int size;            // number of used bytes (digits)
        int capacity;        // size of digits
        int sign;            // -1, 0 or +1

    public:
        /** Creates a BigInt with initial value n and initial capacity cap **/
        BigInt(int n, int cap);

        /** Creates a BigInt with initial value n **/
        BigInt(int n);

        /** Creates a BigInt with initial value floor(d) **/
        BigInt(long double d);

        /** Creates a BigInt with value 0 **/
        BigInt();

        /** Creates a BigInt by reading the value from a string **/
        BigInt(string s);

        /** Creates a BigInt by reading the value from a C string **/
        BigInt(const char s[]);

        /** Copy constructor **/
        BigInt(const BigInt& n);

        /** Assignment operators **/
        const BigInt &operator=(const BigInt& n);
        const BigInt &operator=(int n);

        /** Cleans up **/
        ~BigInt();

        /** Removes any leading zeros and adjusts the sign **/
        void normalize();

        /** Returns the sign of n: -1, 0 or 1 **/
        static int sig(int n);

        /** Returns the sign of n: -1, 0 or 1 **/
        static int sig(long double n);

        /** Returns the number of decimal digits **/
        inline int length() { return size; }

        /** Arithmetic **/
        BigInt operator-();
        BigInt operator+ (BigInt n);
        BigInt&operator+=(BigInt n);
        BigInt operator- (BigInt n);
        BigInt&operator-=(BigInt n);
        BigInt operator* (BigInt n);
        void   operator*=(BigInt n);
        BigInt operator/ (BigInt n);
        void   operator/=(BigInt n);
        BigInt operator% (BigInt n);
        void   operator%=(BigInt n);
        int divide(int n);              // Divides storing quotient in *this and returning the remainder
        BigInt divide(BigInt n);        // Divides storing quotient in *this and returning the remainder

        /** Casting **/
        bool operator!();
        operator bool();
        operator string();

        /** Comparison **/
        bool operator<(BigInt n);
        bool operator>(BigInt n);
        bool operator==(BigInt n);
        bool operator<=(BigInt n);
        bool operator>=(BigInt n);
        int compare(BigInt n);

        /** Returns the lowest value as an integer (watch out for overflow) **/
        int toInt();

        /** Returns the value as a decimal string **/
        string toString();

        /** Outputs decimal value to stdout **/
        void print();

        /** Outputs the decimal value, with commas **/
        void printWithCommas(ostream &out);

    private:
        /** Expansion **/
        void grow();

    /** I/O Friends **/
    friend istream &operator>>(istream &in, BigInt& n);
    friend ostream &operator<<(ostream &out, BigInt n);
};

/** Misc **/
inline bool isDigit(int c) { return(c >= (int)'0' && c <= (int)'9'); }

/** Input/Output **/
istream& operator>>(istream& in, BigInt& n)
{
    n.size = 0;
    n.sign = 1;
    int sign = 1;
    int c;
    while((c = in.peek()) >= 0 &&
           (c == ' ' || c == '\t' || c == '\r' || c == '\n'))
        in.get();
    if (c < 0 || (c != (int)'-' && !isDigit(c))) { in >> c; return in; }
    if (c == (int)'-') { sign = -1; in.get(); }

    // FIXME: Extremely inefficient! Use a string.
    while((c = in.peek()) >= 0 && isDigit(c))
    {
        in.get();
        n *= 10;
        n += (c - (int)'0');
    }
    n.sign = sign;      //XXX: assign n.sign directly after fixing the FIXME
    n.normalize();
    return in;
}

ostream& operator<<(ostream& out, BigInt n) { return out << n.toString(); }

BigInt::BigInt(int n, int cap)
{
    cap = max(cap, (int)sizeof(n) * 8);
    capacity = cap;
    sign = sig(n);
    n *= sign;
    digits = new char[cap];
    memset(digits, 0, cap);
    for (size = 0; n; size++)
    {
        digits[size] = n % 10;
        n /= 10;
    }
}

BigInt::BigInt(int n)
{
    capacity = 1024;
    sign = sig(n);
    n *= sign;
    digits = new char[capacity];
    memset(digits, 0, capacity);
    size = 0;
    while(n)
    {
        digits[size++] = n % 10;
        n /= 10;
    }
}

BigInt::BigInt()
{
    capacity = 128;
    sign = 0;
    digits = new char[capacity];
    memset(digits, 0, capacity);
    size = 0;
}

BigInt::BigInt(string s)
{
    capacity = max((int)s.size(), 16);
    sign = 0;
    digits = new char[capacity];
    memset(digits, 0, capacity);
    istringstream in(s);
    in >> (*this);
}

BigInt::BigInt(const char s[])
{
    capacity = max((int)strlen(s), 16);
    sign = 0;
    digits = new char[capacity];
    memset(digits, 0, capacity);
    istringstream in(s);
    in >> (*this);
}

BigInt::BigInt(const BigInt& n)
{
    capacity = n.capacity;
    sign = n.sign;
    size = n.size;
    digits = new char[capacity];
    memcpy(digits, n.digits, capacity);
}

const BigInt& BigInt::operator=(const BigInt& n)
{
    if (&n != this)
    {
        if (capacity < n.size)
        {
            capacity = n.capacity;
            delete [] digits;
            digits = new char[capacity];
        }
        sign = n.sign;
        size = n.size;
        memcpy(digits, n.digits, size);
        memset(digits + size, 0, capacity - size);
    }
    return *this;
}

const BigInt& BigInt::operator=(int n)
{
    sign = sig(n);
    n *= sign;
    for (size = 0; n; size++)
    {
        digits[size] = n % 10;
        n /= 10;
    }
    return *this;
}

BigInt::~BigInt() { delete [] digits; }

void BigInt::normalize()
{
    while(size && !digits[size-1]) size--;
    if (!size) sign = 0;
}

int BigInt::sig(int n) {return(n > 0 ? 1 : (n == 0 ? 0 : -1)); }

int BigInt::sig(long double n) { return(n > 0 ? 1 : (n == 0 ? 0 : -1)); }

string BigInt::toString()
{
    string s = (sign >= 0 ? "" : "-");
    for (int i = size - 1; i >= 0; i--)
        s += (digits[i] + '0');
    if (size == 0) s += '0';
    return s;
}

void BigInt::print() { cout << toString(); }

void BigInt::grow()
{
    char *olddigits = digits;
    int oldCap = capacity;
    capacity *= 2;
    digits = new char[capacity];
    memcpy(digits, olddigits, oldCap);
    memset(digits + oldCap, 0, oldCap);
    delete [] olddigits;
}

BigInt BigInt::operator-()
{
    BigInt result(*this);
    result.sign *= -1;
    return result;
}

BigInt BigInt::operator+(BigInt n)
{
    BigInt result(*this);
    result += n;
    return result;
}

BigInt &BigInt::operator+=(BigInt n)
{
    int maxS = max(size, n.size) + 1;
    while(maxS >= capacity) grow();        //FIXME: this is stupid
    if (!n.sign) return *this;
    if (!sign) sign = n.sign;
    if (sign == n.sign)
    {
        int carry = 0;
        int i;
        for (i = 0; i < maxS - 1 || carry; i++)
        {
            int newdig = carry;
            if (i < size) newdig += digits[i];
            if (i < n.size) newdig += n.digits[i];
            digits[i] = newdig % 10;
            carry = newdig / 10;
        }
        size = max(i, size);
    }
    else
    {
        n.sign *= -1;
        operator-=(n);
        n.sign *= -1;
    }
    return *this;
}

BigInt BigInt::operator-(BigInt n)
{
    BigInt result(*this);
    result -= n;
    return result;
}

BigInt &BigInt::operator-=(BigInt n)
{
    int maxS = max(size, n.size) + 1;
    while(maxS >= capacity) grow();        //FIXME: this is stupid
    if (!n.sign) return *this;
    if (!sign) sign = 1;
    if (sign == n.sign)
    {
        if (sign >= 0 && *this < n || sign < 0 && *this > n)
        {
            // Subtracting a bigger number
            BigInt tmp = n;
            tmp -= *this;
            *this = tmp;
            sign = -sign;
            return *this;
        }

        int carry = 0;
        int i;
        for (i = 0; i < maxS - 1; i++)
        {
            int newdig = carry;
            if (i < size) newdig += digits[i];
            if (i < n.size) newdig -= n.digits[i];
            if (newdig < 0) newdig += 10, carry = -1;
            else carry = 0;
            digits[i] = newdig;
        }
        if (carry)     // Subtracted a bigger number, need to flip sign
        {
            if (i) digits[0] = 10 - digits[0];
            size = (i ? 1 : 0);
            for (int j = 1; j < i; j++)
            {
                digits[j] = 9 - digits[j];
                if (digits[i]) size = j + 1;
            }
            sign *= -1;
        }
        normalize();
    }
    else
    {
        n.sign *= -1;
        operator+=(n);
        n.sign *= -1;
    }
    return *this;
}

BigInt BigInt::operator*(BigInt n)
{
    BigInt result(0, size + n.size);
    result.sign = sign * n.sign;
    if (!result.sign) return result;
    int i, j;
    for (i = 0; i < n.size; i++)
    {
        if (n.digits[i])
        {
            int carry = 0;
            for (j = 0; j < size || carry; j++)
            {
                int newDig =
                    result.digits[i + j] +
                    (j < size ? n.digits[i] * digits[j] : 0) +
                    carry;
                result.digits[i + j] = newDig % 10;
                carry = newDig / 10;
            }
        }
    }
    result.size = i + j - 1;
    return result;
}

void BigInt::operator*=(BigInt n)
{
    operator=(operator*(n));
}

BigInt BigInt::operator/(BigInt n)
{
    if (!n) n.size /= n.size;       //XXX: force a crash
    BigInt result(*this);
    result /= n;
    return result;
}

void BigInt::operator/=(BigInt n){ divide(n); }

BigInt BigInt::operator%(BigInt n)
{
    BigInt tmp(*this);
    return tmp.divide(n);
}

BigInt BigInt::divide(BigInt n)
{
    if (!n) n.size /= n.size;         //XXX: force a crash
    if (!sign) return 0;
    sign *= n.sign;
    int oldSign = n.sign;
    n.sign = 1;
    BigInt tmp(0, size);
    for (int i = size - 1; i >= 0; i--)
    {
        tmp *= 10;
        tmp += digits[i];
        digits[i] = 0;
        while(tmp >= n) { tmp -= n; digits[i]++; }
    }
    normalize();
    n.sign = oldSign;
    return tmp;
}

bool BigInt::operator!() { return !size; }

BigInt::operator bool() { return size; }

BigInt::operator string() { return toString(); }

bool BigInt::operator<(BigInt n) { return(compare(n) < 0); }

bool BigInt::operator>(BigInt n) { return(compare(n) > 0); }

bool BigInt::operator==(BigInt n) { return(compare(n) == 0); }

bool BigInt::operator<=(BigInt n) { return(compare(n) <= 0); }

bool BigInt::operator>=(BigInt n) { return(compare(n) >= 0); }

int BigInt::compare(BigInt n)
{
    if (sign < n.sign) return -1;
    if (sign > n.sign) return 1;
    if (size < n.size) return -sign;
    if (size > n.size) return sign;
    for (int i = size - 1; i >= 0; i--)
    {
        if (digits[i] < n.digits[i]) return -sign;
        else if (digits[i] > n.digits[i]) return sign;
    }
    return 0;
}

const BigInt Zero(0);
const char aye[] = "divisible";
const char nay[] = "not divisible";
int t, tt;
BigInt a, b;

void solve()
{
    cin >> a >> b;
    BigInt c; c = a % b;
    if (c == Zero) printf("Case %d: %s\n", ++tt, aye);
    else           printf("Case %d: %s\n", ++tt, nay);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
