inline void insert(int x) {
    int p = 0;
    bool flag = false;
    // std::cout << "i " << x << "| ";
    for (int i = 30; i >= 0; i --) {
        int u = x >> i & 1;
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
        if (!f[p]) {
            // std::cout << p << " ";
            flag = true;
        }
        f[p] = true;
    }   
    cnt[p] ++;
    // std::cout << "\n";
}

inline int find(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i --) {
        int u = x >> i & 1;
        if (son[p][!u] && f[son[p][!u]]) {
            p = son[p][!u];
            res += 1 << i;
        }
        else p = son[p][u];
    }
    return res;
}

inline void del(int x) {
    // std::cout << "d " << x << "| ";
    int p = 0, la = 0, li = 31;
    for (int i = 30; i >= 0; i --) {
        int u = x >> i & 1;
        if (son[p][!u] && f[son[p][!u]]) {
            // std::cout << u << " " << p << " " << son[p][!u] << " ";
            la = p;
            li = i;
        }
        p = son[p][u];
        // std::cout << p << " ";
    } 
    cnt[p] --;
    // std::cout << la << " " << li << "|  ";
    if (!cnt[p]) {
        while (li >= 0) {
            f[son[la][x >> li & 1]] = false; 
            // std::cout << son[la][x >> li & 1] << " ";
            la = son[la][x >> li & 1];
            li --;
        }
    }
    // std::cout << "\n";
}
