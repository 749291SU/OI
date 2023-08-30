struct SegmentTree {
    int l, r, sum, lmax, rmax, dat;
    SegmentTree() { } 
} t[4 * N];

inline void pushup(SegmentTree& p, SegmentTree& l, SegmentTree& r) {
    
}

inline void pushup(int p) {
    pushup(t[p], t[p << 1], t[p << 1 | 1]);
}

void build(int p, int l, int r) {
    t[p].l = l; t[p].r = r;
    if (l == r) { 
        
        return ;
    }  
    int mid = l + r >> 1;
    build(p << 1, l, mid); build(p << 1 | 1, mid + 1, r);
    pushup(p);
}
void modify(int p, int x, int v) {
    if (t[p].l == t[p].r) {
        
        return ;
    } 
    int mid = t[p].l + t[p].r >> 1;
    x <= mid ? modify(p << 1, x, v) : modify(p << 1 | 1, x, v);
    pushup(p);
}
SegmentTree ask(int p, int l, int r) {
    if (l <= t[p].l && r >= t[p].r) return t[p];
    int mid = t[p].l + t[p].r >> 1;
    if (l > mid) return ask(p << 1 | 1, l, r);
    if (r <= mid) return ask(p << 1, l, r);
    SegmentTree t, t1 = ask(p << 1, l, r), t2 = ask(p << 1 | 1, l, r);
    pushup(t, t1, t2);
    return t;
}