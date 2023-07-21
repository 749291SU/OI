const int MT = 362880, P = 1e6;
int e[MT], ne[MT], h[P], idx;

inline int ha(int x) {
    return x % P;
}

inline bool fi(int x, int f) {
    int p = ha(x), t = h[p];
    while (t != -1 && e[t] != x) t = ne[t];
    if (t == -1) { 
        if (f) e[idx] = x; ne[idx] = h[p]; h[p] = idx ++;
        return false;
    }
    return true;
}
