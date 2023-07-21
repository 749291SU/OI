int heap[N], idx;

inline void sinn() {
    int a = 1, p = 2;
    while (p <= idx) {
        if (p + 1 <= idx && heap[p + 1] > heap[p]) p ++;
        if (heap[p] <= heap[a]) break;
        std::swap(heap[p], heap[a]); a = p;
    }
}

inline void swim() {
    int a = idx >> 1, p = idx;
    while (a && heap[a] < heap[p]) {
        std::swap(heap[a], heap[p]);
        p = a; a = p >> 1;
    }  
}

inline int get() {
    return heap[1]; 
}

inline void pop() {
    std::swap(heap[1], heap[idx --]); 
    sinn();
}

inline void insert(int x) {
    heap[++ idx] = x;
    swim(); 
}
