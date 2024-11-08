#pragma once
#include "../template/template.hpp"
struct UnionFind {
    UnionFind(int N)
        : n(N), data(N, -1) {}
    int merge(const int a, const int b) {
        assert(0 <= a and a < n);
        assert(0 <= b and b < n);
        int x = leader(a), y = leader(b);
        if(x == y) return x;
        if(-data[x] < -data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return x;
    }
    bool same(const int a, const int b) {
        assert(0 <= a and a < n);
        assert(0 <= b and b < n);
        return leader(a) == leader(b);
    }
    int leader(const int a) {
        assert(0 <= a and a < n);
        if(data[a] < 0) return a;
        return data[a] = leader(data[a]);
    }
    int size(const int a) {
        assert(0 <= a and a < n);
        return -data[leader(a)];
    }
    vector<vector<int>> groups() {
        vector<int> leader_buf(n), group_size(n);
        for(int i = 0; i < n; ++i) {
            leader_buf[i] = leader(i);
            ++group_size[leader_buf[i]];
        }
        vector<vector<int>> result(n);
        for(int i = 0; i < n; ++i) {
            result[i].reserve(group_size[i]);
        }
        for(int i = 0; i < n; ++i) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(remove_if(result.begin(), result.end(), [&](const vector<int>& v) { return v.empty(); }), result.end());
        return result;
    }

   private:
    int n;
    vector<int> data;
};