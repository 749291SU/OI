/*
    749291
                               .--.  
      /\_/\                   |o_o | 
     ( o.o )                  |:_/ |
     >  ^  <                 //   \ \ 
     /      \               (|     | )
     ｜　　　｜ ／￣￣＼       /'\  __/`\
      UU￣UU￣￣￣￣U       \___)=(___/ 
    wow~ ⊙o⊙
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using i64 = long long;

#define fi first
#define se second

template<typename T>
inline T min(const T& a, const T& b) {
    return a <= b ? a : b;
}
template<typename T>
inline T min(const T& a, const T& b, const T& c) {
    return min(a, min(b, c)); 
}
template<typename T>
inline T max(const T& a, const T& b) {
    return a >= b ? a : b;
}
template<typename T>
inline T max(const T& a, const T& b, const T& c) {
    return max(a, max(b, c)); 
}

inline bool topo() {
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i ++) {
        if (deg[i] == 0) q[++ tt] = i;
    } 

    while (hh <= tt) {
        int t = q[hh ++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if ((-- deg[j]) == 0) q[++ tt] = j;
        } 
    } 
    return tt == n - 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

            

    return 0;
}
