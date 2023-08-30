int d[N];
inline int ask(int x) {
    int ans = 0;
    for (; x; x -= x & (-x)) {
        ans += d[x];   
    }    
    return ans;
}
inline void add(int x, int v) {
    for (; x <= n; x += x & (-x)) {
        d[x] += v;
    } 
}
