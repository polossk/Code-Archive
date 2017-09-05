/****
    *@PoloShen
    *Title:G
    */
#include <iostream>
#include <string>

using namespace std;
typedef long long int64;

int64 q_mul_mod(int64 a,int64 b,int64 m){
    int64 t = 0; a %= m; b %= m;
    while (b){
        if (b&1){ t += a;
            if  (t >= m) t -= m;
        }
        a <<= 1; b >>= 1;
        if (a >= m) a -= m;
    }
    return t;
}

int64 q_pow_mod(int64 a, int64 b, int64 m){
    int64 ans = 1;
    a %= m;
    while (b){
        if (b&1){
            ans = q_mul_mod(ans, a, m);
            b--;
        }
        b /= 2;
        a = q_mul_mod(a, a, m);
    }
    return ans;
}

int64 mod; string s;
inline int64 qmul(int64 a, int64 b){ return q_mul_mod(a, b, mod); }
inline int64 qmod(int64 a, int64 k){ return q_pow_mod(a, k, mod); }

struct num{
    int64 length;
    int64 value;
    num(){length = 0;value = 0;}
    num(int64 l, int64 v){length = l;value = v;}
};

num build(int l,int r){
    num p, t;
    int i,flag = 0;
    int left = 0, right = 0, cnt = 0;
    for (i = l; i <= r; i++){
        if (s[i] == '['){
            if (flag == 0) left = i + 1;
            flag++;
        }
        else if (s[i] == ']'){
            flag--;
            if (flag == 0){
                right = i - 1;
                i++;
                cnt = s[i] - '0';
                t = build(left, right);
                int64 base = qmod(10, t.length);
                int64 g = 1,e = base;
                p.length += cnt * t.length;
                p.value = qmul(p.value, qmod(base, cnt));
                while (--cnt){
                    g += e;
                    g %= mod;
                    e = qmul(e, base);
                }
                t.value = qmul(t.value, g);
                p.value = (p.value + t.value) % mod;
            }
        }
        else if (flag == 0){
            p.value = p.value * 10 + s[i] - '0';
            p.value %= mod;
            p.length++;
        }
    }
    p.value %= mod;
    return p;
}

void solve(){
    cin >> s >> mod;
    num ans = build(0, s.size() - 1);
    cout << ans.value << endl;
}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
