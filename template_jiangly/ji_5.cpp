#include <bits/stdc++.h>
 
using i64 = long long;

struct Max {
    int x = -1E9;
    Max &operator+=(Max a) {
        x = std::max(x, a.x);
        return *this;
    }
};