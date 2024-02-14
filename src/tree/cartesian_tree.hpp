#pragma once
#include "../template/template.hpp"
#include "../graph/graph_template.hpp"
template <typename T>
pair<Graph<int>, int> cartesian_tree(const vector<T>& a) {
    int n = (int)a.size();
    Graph<int> g(n);
    vector<int> p(n, -1), st;
    st.reserve(n);
    for(int i = 0; i < n; ++i) {
        int prv = -1;
        while(!st.empty() and a[i] < a[st.back()]) {
            prv = st.back();
            st.pop_back();
        }
        if(prv != -1) p[prv] = i;
        if(!st.empty()) p[i] = st.back();
        st.push_back(i);
    }
    int root = -1;
    for(int i = 0; i < n; ++i) {
        if(p[i] != -1) g.add_directed_edge(p[i], i);
        else root = i;
    }
    return {g, root};
}