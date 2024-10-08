#pragma once
#include "./template.hpp"
struct RandomNumberGenerator {
    mt19937_64 mt;
    RandomNumberGenerator()
        : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    inline ll operator()(const ll lower, const ll upper) {
        assert(lower <= upper);
        return num(lower, upper);
    }
    inline ll num(const ll lower, const ll upper) {
        assert(lower <= upper);
        uniform_int_distribution<ll> dist(lower, upper);
        return dist(mt);
    }
    inline long double rnum(const long double lower, const long double upper) {
        uniform_real_distribution<long double> dist(lower, upper);
        return dist(mt);
    }
    inline vector<ll> vec(const int n, const ll lower, const ll upper, const bool dup = true) {
        assert(1 <= n and n <= (int)1e8);
        assert(lower <= upper);
        vector<ll> res(n);
        if(dup) {
            for(int i = 0; i < n; ++i) res[i] = num(lower, upper);
        } else {
            assert(upper - lower + 1 >= n);
            if(upper - lower + 1 >= 2 * n) {
                set<ll> used;
                while((int)used.size() < n) {
                    ll a = num(lower, upper);
                    used.insert(a);
                }
                int i = 0;
                for(ll a : used) {
                    res[i] = a;
                    ++i;
                }
            } else {
                vector<int> p = perm(upper - lower + 1, false);
                for(int i = 0; i < n; ++i) {
                    res[i] = p[i] + lower;
                }
            }
        }
        return res;
    }
    inline vector<long double> rvec(const int n, const long double lower, const long double upper) {
        assert(1 <= n and n <= (int)1e8);
        vector<long double> res(n);
        for(int i = 0; i < n; ++i) res[i] = rnum(lower, upper);
        return res;
    }
    inline vector<int> perm(const int n, const bool one = true) {
        assert(1 <= n and n <= (int)1e8);
        vector<int> res(n);
        for(int i = 0; i < n; ++i) res[i] = i + one;
        for(int i = n - 1; i > 0; --i) {
            swap(res[i], res[num(0, i)]);
        }
        return res;
    }
    inline pair<vector<int>, vector<int>> tree(const int n, const bool one = true) {
        assert(1 <= n and n <= (int)1e8);
        if(n == 1) return {{}, {}};
        if(n == 2) return {{0 + one}, {1 + one}};
        vector<int> u(n - 1), v(n - 1);
        vector<ll> pruefer = vec(n - 2, 0, n - 1);
        set<int> st;
        vector<int> cnt(n);
        for(int i = 0; i < n; ++i) st.insert(i);
        auto add = [&](int x) -> void {
            if(x > n) return;
            if(cnt[x] == 0) st.erase(x);
            ++cnt[x];
        };
        auto del = [&](int x) -> void {
            if(x > n) return;
            --cnt[x];
            if(cnt[x] == 0) st.insert(x);
        };
        for(int i = 0; i < n - 2; ++i) add(pruefer[i]);
        for(int i = 0; i < n - 2; ++i) {
            int a = *st.begin();
            int b = pruefer[i];
            u[i] = a + one;
            v[i] = b + one;
            del(b);
            add(a);
        }
        int a = *st.begin();
        add(a);
        int b = *st.begin();
        u[n - 2] = a + one;
        v[n - 2] = b + one;
        return {u, v};
    }
    inline tuple<vector<int>, vector<int>, vector<int>> weighted_tree(const int n, const int lower, const int upper, const bool one = true) {
        assert(1 <= n and n <= (int)1e8);
        assert(lower <= upper);
        auto [u, v] = tree(n, one);
        vector<int> w(n - 1);
        for(int i = 0; i < n - 1; ++i) w[i] = num(lower, upper);
        return {u, v, w};
    }
    inline pair<vector<int>, vector<int>> graph(const int n, const int m, const bool one = true) {
        assert(1 <= n and n <= (int)1e8);
        assert(1 <= m and m <= (int)min((ll)1e8, 1ll * n * (n - 1) / 2));
        vector<int> u, v;
        u.reserve(m);
        v.reserve(m);
        if(1ll * n * (n - 1) / 2 >= 2e6) {
            set<pair<int, int>> edge;
            while((int)edge.size() < m) {
                int a = num(0, n - 1);
                int b = num(0, n - 1);
                if(a >= b) continue;
                edge.insert({a, b});
            }
            for(auto& [a, b] : edge) {
                u.push_back(a + one);
                v.push_back(b + one);
            }
        } else {
            vector<pair<int, int>> edge;
            edge.reserve(n * (n - 1) / 2);
            for(int i = 0; i < n; ++i) {
                for(int j = i + 1; j < n; ++j) {
                    edge.push_back({i, j});
                }
            }
            vector<int> p = perm(n * (n - 1) / 2, false);
            for(int i = 0; i < m; ++i) {
                u.push_back(edge[p[i]].first + one);
                v.push_back(edge[p[i]].second + one);
            }
        }
        return {u, v};
    }
    inline tuple<vector<int>, vector<int>, vector<int>> weighted_graph(const int n, const int m, const int lower, const int upper, const bool one = true) {
        assert(1 <= n and n <= (int)1e8);
        assert(1 <= m and m <= (int)min((ll)1e8, 1ll * n * (n - 1) / 2));
        assert(lower <= upper);
        auto [u, v] = graph(n, m, one);
        vector<int> w(m);
        for(int i = 0; i < m; ++i) w[i] = num(lower, upper);
        return {u, v, w};
    }
    inline pair<vector<int>, vector<int>> connected_graph(const int n, const int m, const bool one = true) {
        assert(1 <= n and n <= (int)1e8);
        assert(n - 1 <= m and m <= (int)min((ll)1e8, 1ll * n * (n - 1) / 2));
        vector<int> u, v;
        u.reserve(m);
        v.reserve(m);
        auto [ut, vt] = tree(n, false);
        if(1ll * n * (n - 1) / 2 >= 2e6) {
            set<pair<int, int>> edge;
            for(int i = 0; i < n - 1; ++i) {
                edge.insert({min(ut[i], vt[i]), max(ut[i], vt[i])});
            }
            while((int)edge.size() < m) {
                int a = num(0, n - 1);
                int b = num(0, n - 1);
                if(a >= b) continue;
                edge.insert({a, b});
            }
            for(auto& [a, b] : edge) {
                u.push_back(a + one);
                v.push_back(b + one);
            }
        } else {
            set<pair<int, int>> used;
            for(int i = 0; i < n - 1; ++i) {
                u.push_back(ut[i] + one);
                v.push_back(vt[i] + one);
                used.insert({min(ut[i], vt[i]), max(ut[i], vt[i])});
            }
            vector<pair<int, int>> edge;
            edge.reserve(n * (n - 1) / 2 - (n - 1));
            for(int i = 0; i < n; ++i) {
                for(int j = i + 1; j < n; ++j) {
                    if(used.find({i, j}) == used.end()) edge.push_back({i, j});
                }
            }
            vector<int> p = perm(n * (n - 1) / 2 - (n - 1), false);
            for(int i = 0; i < m - (n - 1); ++i) {
                u.push_back(edge[p[i]].first + one);
                v.push_back(edge[p[i]].second + one);
            }
        }
        return {u, v};
    }
    inline tuple<vector<int>, vector<int>, vector<int>> weighted_connected_graph(const int n, const int m, const int lower, const int upper, const bool one = true) {
        assert(1 <= n and n <= (int)1e8);
        assert(n - 1 <= m and m <= (int)min((ll)1e8, 1ll * n * (n - 1) / 2));
        assert(lower <= upper);
        auto [u, v] = connected_graph(n, m, one);
        vector<int> w(m);
        for(int i = 0; i < m; ++i) w[i] = num(lower, upper);
        return {u, v, w};
    }
    inline string parenthesis(int n) {
        assert(1 <= n and n <= 1e8);
        string res = "";
        int N = n, M = n;
        for(int i = 0; i < 2 * n; ++i) {
            if(rnum(0.0l, 1.0l) > 1.0l * (N - M) * (N + 1) / ((N - M + 1) * (N + M))) {
                res += "(";
                --M;
            } else {
                res += ")";
                --N;
            }
        }
        return res;
    }
} rng;