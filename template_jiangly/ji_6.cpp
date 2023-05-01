#include <bits/stdc++.h>
 
using i64 = long long;
using u64 = unsigned long long;
 
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
 
struct Tree {
    Tree *l;
    Tree *r;
    int siz;
    i64 val;
    int id;
    i64 ta;
    i64 td;
    u64 w;
    
    Tree(i64 v = 0, int id = 0) : l{}, r{}, siz{1}, val{v}, id{id}, ta{}, td{}, w{rng()} {}
};
 
void add(Tree *t, i64 a, i64 d) {
    if (!t) return;
    t->ta += a;
    t->td += d;
    int v = 0;
    if (t->l) v = t->l->siz;
    t->val += a + d * v;
}
 
void push(Tree *t) {
    add(t->l, t->ta, t->td);
    int v = 1;
    if (t->l) v += t->l->siz;
    add(t->r, t->ta + t->td * v, t->td);
    t->ta = t->td = 0;
}
 
void pull(Tree *t) {
    t->siz = 1;
    if (t->l) t->siz += t->l->siz;
    if (t->r) t->siz += t->r->siz;
}
 
std::pair<Tree *, Tree *> split(Tree *t, Tree *v) {
    if (!t) return {t, t};
    push(t);
    if (v->val > t->val || (v->val == t->val && v->id > t->id)) {
        auto [l, r] = split(t->l, v);
        t->l = r;
        pull(t);
        return {l, t};
    } else {
        auto [l, r] = split(t->r, v);
        t->r = l;
        pull(t);
        return {t, r};
    }
}
 
void insert(Tree *&t, Tree *x) {
    if (!t) {
        t = x;
        return;
    }
    if (x->w > t->w) {
        auto [l, r] = split(t, x);
        x->l = l;
        x->r = r;
        pull(x);
        t = x;
        return;
    }
    push(t);
    if (x->val > t->val || (x->val == t->val && x->id > t->id)) {
        insert(t->l, x);
    } else {
        insert(t->r, x);
    }
    pull(t);
}
 
i64 get(Tree *t) {
    if (!t) return 0;
    i64 val = std::max(0LL, t->val);
    push(t);
    val += get(t->l);
    val += get(t->r);
    delete t;
    return val;
}
 
void dfs(Tree *t) {
    if (!t) return;
    std::cerr << t->val << " ";
    push(t);
    dfs(t->l);
    dfs(t->r);
}