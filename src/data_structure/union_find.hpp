#pragma once
#include "../template/template.hpp"
struct UnionFind {
    UnionFind(const int N)
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
        vector<vector<int>> result;
        result.reserve(count_if(group_size.begin(), group_size.end(), [](const int sz) { return sz > 0; }));
        for(int i = 0; i < n; ++i) {
            if(group_size[i] == 0) continue;
            const int id = result.size();
            result.emplace_back();
            result.back().reserve(group_size[i]);
            group_size[i] = id;
        }
        for(int i = 0; i < n; ++i) {
            result[group_size[leader_buf[i]]].push_back(i);
        }
        return result;
    }

   private:
    int n;
    vector<int> data;
};