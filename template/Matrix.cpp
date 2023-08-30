template<typename T>
struct Mat {
    int rs, cs;
    std::vector<std::vector<T>> a;

    Mat() { }
    Mat(int rs, int cs) : rs(rs), cs(cs), a(rs, std::vector<T>(cs)) {}
    Mat(int rs, int cs, int f) : rs(rs), cs(cs), a(rs, std::vector<T>(cs)) {
        init_eye();
    }

    inline void init_eye() {
        for (int i = 0; i < rs; i ++) a[i][i] = 1;
    }

    inline void set(int i, int j, T v) { a[i][j] = v; }

    Mat operator * (const Mat& rhs) {
        Mat res(rs, rhs.cs);
        for (int i = 0; i < rs; i ++) {
            for (int j = 0; j < rhs.cs; j ++) {
                for (int k = 0; k < cs; k ++) {
                    res.a[i][j] = res.a[i][j] + a[i][k] * rhs.a[k][j];  
                } 
            }
        }
        return res;
    }

    Mat operator + (const Mat&rhs) {
        Mat res(rs, cs);
        for (int i = 0; i < rs; i ++) {
            for (int j = 0; j < cs; j ++) {
                res.a[i][j] = a[i][j] + rhs.a[i][j];
            }
        }
    }

    inline T get(int i, int j) { return a[i][j]; }

    inline void print() {
        for (int i = 0; i < rs; i ++) {
            for (int j = 0; j < cs; j ++) std::cout << a[i][j] << " ";
            std::cout << "\n"; 
        } 
    }
};
