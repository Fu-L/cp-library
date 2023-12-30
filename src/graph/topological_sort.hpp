#pragma once
#include "cp-library/src/template/template.hpp"
#include "cp-library/src/graph/graph_template.hpp"
template <typename T = int>
vector<int> topological_sort(const Graph<T>& g) {
    const int n = (int)g.size();
    vector<int> deg(n);
    for(int i = 0; i < n; ++i) {
        for(const int& to : g[i]) {
            ++deg[to];
        }
    }
    stack<int> st;
    for(int i = 0; i < n; ++i) {
        if(deg[i] == 0) {
            st.push(i);
        }
    }
    vector<int> res;
    res.reserve(n);
    while(!st.empty()) {
        int p = st.top();
        st.pop();
        res.push_back(p);
        for(const int& to : g[p]) {
            if(--deg[to] == 0) {
                st.push(to);
            }
        }
    }
    if((int)res.size() != n) return {};
    return res;
}