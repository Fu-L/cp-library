template <typename T>
struct fenwick_tree {
    int n;
    vector<T> data;
    fenwick_tree(int N)
        : n(N), data(N) {}
    void add(int p, T x) {
        assert(0 <= p && p < n);
        p++;
        while(p <= n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }
    T sum(int r) {
        T s = 0;
        while(r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        return sum(r) - sum(l);
    }
    T operator[](int x) const {
        assert(0 <= x && x < n);
        return sum(x, x + 1);
    }
};
