#pragma once
#include "../template/template.hpp"
template <typename T>
vector<int> suffix_array(const vector<T>& s, const bool compress = true) {
    auto sa_is = [&](auto& sa_is, const vector<int>& s, const int upper) -> vector<int> {
        const int n = (int)s.size();
        if(n == 0) return {};
        if(n == 1) return {0};
        if(n == 2) {
            if(s[0] < s[1]) return {0, 1};
            else return {1, 0};
        }
        vector<int> sa(n);
        vector<bool> ls(n);
        for(int i = n - 2; i >= 0; --i) {
            ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
        }
        vector<int> sum_l(upper + 1), sum_s(upper + 1);
        for(int i = 0; i < n; ++i) {
            if(!ls[i]) {
                ++sum_s[s[i]];
            } else {
                ++sum_l[s[i] + 1];
            }
        }
        for(int i = 0; i <= upper; ++i) {
            sum_s[i] += sum_l[i];
            if(i < upper) sum_l[i + 1] += sum_s[i];
        }
        auto induce = [&](const vector<int>& lms) {
            fill(sa.begin(), sa.end(), -1);
            vector<int> buf(upper + 1);
            copy(sum_s.begin(), sum_s.end(), buf.begin());
            for(const int d : lms) {
                if(d == n) continue;
                sa[buf[s[d]]++] = d;
            }
            copy(sum_l.begin(), sum_l.end(), buf.begin());
            sa[buf[s[n - 1]]++] = n - 1;
            for(int i = 0; i < n; ++i) {
                const int v = sa[i];
                if(v >= 1 and !ls[v - 1]) {
                    sa[buf[s[v - 1]]++] = v - 1;
                }
            }
            copy(sum_l.begin(), sum_l.end(), buf.begin());
            for(int i = n - 1; i >= 0; --i) {
                const int v = sa[i];
                if(v >= 1 and ls[v - 1]) {
                    sa[--buf[s[v - 1] + 1]] = v - 1;
                }
            }
        };
        vector<int> lms_map(n + 1, -1);
        int m = 0;
        for(int i = 1; i < n; ++i) {
            if(!ls[i - 1] and ls[i]) {
                lms_map[i] = m++;
            }
        }
        vector<int> lms;
        lms.reserve(m);
        for(int i = 1; i < n; ++i) {
            if(!ls[i - 1] and ls[i]) {
                lms.push_back(i);
            }
        }
        induce(lms);
        if(m) {
            vector<int> sorted_lms;
            sorted_lms.reserve(m);
            for(const int v : sa) {
                if(lms_map[v] != -1) sorted_lms.push_back(v);
            }
            vector<int> rec_s(m);
            int rec_upper = 0;
            rec_s[lms_map[sorted_lms[0]]] = 0;
            for(int i = 1; i < m; ++i) {
                int l = sorted_lms[i - 1], r = sorted_lms[i];
                const int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
                const int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
                bool same = true;
                if(end_l - l != end_r - r) {
                    same = false;
                } else {
                    while(l < end_l) {
                        if(s[l] != s[r]) {
                            break;
                        }
                        ++l;
                        ++r;
                    }
                    if(l == n or s[l] != s[r]) same = false;
                }
                if(!same) ++rec_upper;
                rec_s[lms_map[sorted_lms[i]]] = rec_upper;
            }
            const auto rec_sa = sa_is(sa_is, rec_s, rec_upper);
            for(int i = 0; i < m; ++i) {
                sorted_lms[i] = lms[rec_sa[i]];
            }
            induce(sorted_lms);
        }
        return sa;
    };
    if(compress) {
        int n = (int)s.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
        vector<int> s2(n);
        int upper = 0;
        for(int i = 0; i < n; ++i) {
            if(i and s[idx[i - 1]] != s[idx[i]]) ++upper;
            s2[idx[i]] = upper;
        }
        return sa_is(sa_is, s2, upper);
    }
    return sa_is(sa_is, s, *max_element(s.begin(), s.end()));
}
vector<int> suffix_array(const string& s) {
    int n = (int)s.size();
    vector<int> s2(n);
    for(int i = 0; i < n; ++i) {
        s2[i] = s[i];
    }
    return suffix_array(s2, false);
}
template <typename T>
vector<int> lcp_array(const vector<T>& s, const vector<int>& sa) {
    int n = (int)s.size();
    assert(n >= 1);
    vector<int> rnk(n);
    for(int i = 0; i < n; ++i) {
        rnk[sa[i]] = i;
    }
    vector<int> lcp(n - 1);
    int h = 0;
    for(int i = 0; i < n; ++i) {
        if(h > 0) --h;
        if(rnk[i] == 0) continue;
        int j = sa[rnk[i] - 1];
        for(; j + h < n and i + h < n; ++h) {
            if(s[j + h] != s[i + h]) break;
        }
        lcp[rnk[i] - 1] = h;
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