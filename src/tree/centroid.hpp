#pragma once
#include "../template/template.hpp"
#include "../graph/graph_template.hpp"
template <typename T>
vector<int> centroid(const Graph<T>& g) {
    int n = (int)g.size();
    stack<pair<int, int>> st;
    st.emplace(0, -1);
    vector<int> sz(n), par(n);
    while(!st.empty()) {
        pair<int, int> p = st.top();
        if(sz[p.first] == 0) {
            sz[p.first] = 1;
            for(const Edge<T>& e : g[p.first]) {
                if(e.to != p.second) {
                    st.emplace(e.to, p.first);
                }
            }
        } else {
            for(const Edge<T>& e : g[p.first]) {
                if(e.to != p.second) {
                    sz[p.first] += sz[e.to];
                }
            }
            par[p.first] = p.second;
            st.pop();
        }
    }
    vector<int> ret;
    int size = n;
    for(int i = 0; i < n; ++i) {
        int val = n - sz[i];
        for(const Edge<T>& e : g[i]) {
            if(e.to != par[i]) {
                val = max(val, sz[e.to]);
            }
        }
        if(val < size) size = val, ret.clear();
        if(val == size) ret.emplace_back(i);
    }
    return ret;
}