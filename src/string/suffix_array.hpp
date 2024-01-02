#pragma once
#include "../template/template.hpp"
vector<int> suffix_array(const vector<int>& s) {
    int n = (int)s.size();
    vector<int> sa(n), rank(n), tmp(n);
    for(int i = 0; i < n; ++i) rank[i] = s[i];
    iota(sa.begin(), sa.end(), 0);
    for(int k = 1; k < n; k *= 2) {
        auto cmp = [&](int x, int y) -> bool {
            if(rank[x] != rank[y]) return rank[x] < rank[y];
            int rx = x + k < n ? rank[x + k] : -1;
            int ry = y + k < n ? rank[y + k] : -1;
            return rx < ry;
        };
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for(int i = 1; i < n; ++i) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
        swap(tmp, rank);
    }
    return sa;
}
vector<int> suffix_array(const string& s) {
    int n = (int)s.size();
    vector<int> s2(n);
    for(int i = 0; i < n; ++i) {
        s2[i] = s[i];
    }
    return suffix_array(s2);
}
vector<int> lcp_array(const vector<int>& s, const vector<int>& sa) {
    int n = (int)s.size();
    assert(n >= 1);
    vector<int> rank(n);
    for(int i = 0; i < n; ++i) {
        rank[sa[i]] = i;
    }
    vector<int> lcp(n - 1);
    int h = 0;
    for(int i = 0; i < n; ++i) {
        if(h > 0) --h;
        if(rank[i] == 0) continue;
        int j = sa[rank[i] - 1];
        for(; j + h < n and i + h < n; ++h) {
            if(s[j + h] != s[i + h]) break;
        }
        lcp[rank[i] - 1] = h;
    }
    return lcp;
}
vector<int> lcp_array(const string& s, const vector<int>& sa) {
    int n = (int)s.size();
    vector<int> s2(n);
    for(int i = 0; i < n; ++i) {
        s2[i] = s[i];
    }
    return lcp_array(s2, sa);
}