#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

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

int main()
{
    ios ::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    return 0;
}