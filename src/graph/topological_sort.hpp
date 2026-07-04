#pragma once
#include "../template/template.hpp"
#include "./graph_template.hpp"
template <typename T>
vector<int> topological_sort(const Graph<T>& g) {
    const int n = g.size();
    vector<int> deg(n);
    for(int i = 0; i < n; ++i) {
        for(const auto& e : g[i]) {
            ++deg[e.to];
        }
    }
    vector<int> st;
    st.reserve(n);
    for(int i = 0; i < n; ++i) {
        if(deg[i] == 0) {
            st.emplace_back(i);
        }
    }
    vector<int> res;
    res.reserve(n);
    while(!st.empty()) {
        const int p = st.back();
        st.pop_back();
        res.emplace_back(p);
        for(const Edge<T>& e : g[p]) {
            if(--deg[e.to] == 0) {
                st.emplace_back(e.to);
            }
        }
    }
    if((int)res.size() != n) return {};
    return res;
}