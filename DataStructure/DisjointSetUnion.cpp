struct dsu {
    int n;
    vector<int> data;
    dsu(int N)
        : n(N), data(N, -1) {}
    int merge(int a, int b) {
        assert(0 <= a && a < n);
        assert(0 <= b && b < n);
        int x = leader(a), y = leader(b);
        if(x == y) return x;
        if(-data[x] < -data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return x;
    }
    bool same(int a, int b) {
        assert(0 <= a && a < n);
        assert(0 <= b && b < n);
        return leader(a) == leader(b);
    }
    int leader(int a) {
        assert(0 <= a && a < n);
        if(data[a] < 0) return a;
        return data[a] = leader(data[a]);
    }
    int size(int a) {
        assert(0 <= a && a < n);
        return -data[leader(a)];
    }
    vector<vector<int>> groups() {
        vector<int> leader_buf(n), group_size(n);
        for(int i = 0; i < n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        vector<vector<int>> result(n);
        for(int i = 0; i < n; i++) {
            result[i].reserve(group_size[i]);
        }
        for(int i = 0; i < n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(remove_if(result.begin(), result.end(), [&](const vector<int>& v) { return v.empty(); }), result.end());
        return result;
    }
};
