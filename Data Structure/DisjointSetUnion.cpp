struct dsu {
    int n;
    vector<int> data;
    dsu(int N)
        : n(N), data(N, -1) {}
    int leader(int x) {
        assert(0 <= x && x < n);
        if(data[x] < 0) return x;
        return data[x] = leader(data[x]);
    }
    int merge(int x, int y) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        x = leader(x);
        y = leader(y);
        if(x == y) return false;
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }
    bool same(int x, int y) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        return leader(x) == leader(y);
    }
    int size(int x) {
        assert(0 <= x && x < n);
        return -data[leader(x)];
    }
};
