#pragma once
#include "../template/template.hpp"
struct RollbackUnionFind {
    RollbackUnionFind(const int N)
        : n(N), data(N, -1), inner_snap(0) {
    }
    int merge(const int a, const int b) {
        assert(0 <= a and a < n);
        assert(0 <= b and b < n);
        int x = leader(a), y = leader(b);
        history.emplace(x, data[x]);
        history.emplace(y, data[y]);
        if(x == y) return x;
        if(-data[x] < -data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return x;
    }
    bool same(const int a, const int b) const {
        assert(0 <= a and a < n);
        assert(0 <= b and b < n);
        return leader(a) == leader(b);
    }
    int leader(const int a) const {
        assert(0 <= a and a < n);
        if(data[a] < 0) return a;
        return leader(data[a]);
    }
    int size(const int a) const {
        assert(0 <= a and a < n);
        return (-data[leader(a)]);
    }
    void undo() {
        assert((int)history.size() >= 2);
        data[history.top().first] = history.top().second;
        history.pop();
        data[history.top().first] = history.top().second;
        history.pop();
    }
    void snapshot() {
        inner_snap = (int)history.size() / 2;
    }
    int get_state() const {
        return (int)history.size() / 2;
    }
    void rollback(int state = -1) {
        if(state == -1) state = inner_snap;
        state *= 2;
        assert(state <= (int)history.size());
        while(state < (int)history.size()) undo();
    }

   private:
    int n;
    vector<int> data;
    stack<pair<int, int>> history;
    int inner_snap;
};