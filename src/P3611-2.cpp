#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int n, p;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline int fast_pow(LL x, int k) {
    int res = 1;    
    while (k) {
        if (k & 1) res = res * x % p;
        x = x * x % p;
        k >>= 1;
    }
    return res;
}

int main()
{
    // ios ::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    n = read(); p = read();
    for (LL i = 1; i <= n; i ++) {
        printf("%d\n", fast_pow(i, p - 2));
    }
    return 0;
}