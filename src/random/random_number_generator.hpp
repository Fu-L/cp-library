#pragma once
#include "../template/template.hpp"
struct RandomNumberGenerator {
    RandomNumberGenerator()
        : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    template <typename T>
    inline T operator()(const T lower, const T upper) {
        static_assert(is_integral_v<T> or is_floating_point_v<T>);
        assert(lower <= upper);
        if constexpr(is_integral_v<T>) {
            uniform_int_distribution<T> dist(lower, upper);
            return dist(mt);
        } else if constexpr(is_floating_point_v<T>) {
            uniform_real_distribution<T> dist(lower, upper);
            return dist(mt);
        }
    }
    template <typename T>
    inline vector<T> vec(const int n, const T lower, const T upper, const bool dup = true) {
        static_assert(is_integral_v<T> or is_floating_point_v<T>);
        assert(0 <= n and n <= (int)1e8);
        assert(lower <= upper);
        if(n == 0) return {};
        vector<T> res(n);
        if(dup or is_floating_point_v<T>) {
            for(int i = 0; i < n; ++i) res[i] = this->operator()(lower, upper);
        } else {
            assert(upper - lower + 1 >= n);
            if(upper - lower + 1 >= 2 * n) {
                set<T> used;
                while((int)used.size() < n) {
                    const T a = this->operator()(lower, upper);
                    used.insert(a);
                }
                int i = 0;
                for(const T a : used) {
                    res[i] = a;
                    ++i;
                }
            } else {
                const vector<int> p = perm(upper - lower + 1, false);
                for(int i = 0; i < n; ++i) {
                    res[i] = p[i] + lower;
                }
            }
        }
        return res;
    }
    inline vector<int> perm(const int n, const bool one = true) {
        assert(0 <= n and n <= (int)1e8);
        vector<int> res(n);
        for(int i = 0; i < n; ++i) res[i] = i + one;
        for(int i = n - 1; i > 0; --i) {
            swap(res[i], res[this->operator()(0, i)]);
        }
        return res;
    }
    inline pair<vector<int>, vector<int>> tree(const int n, const bool one = true) {
        assert(0 <= n and n <= (int)1e8);
        if(n <= 1) return {{}, {}};
        if(n == 2) return {{0 + one}, {1 + one}};
        vector<int> u(n - 1), v(n - 1);
        const vector<int> pruefer = vec(n - 2, 0, n - 1);
        set<int> st;
        vector<int> cnt(n);
        for(int i = 0; i < n; ++i) st.insert(i);
        auto add = [&](const int x) -> void {
            if(x > n) return;
            if(cnt[x] == 0) st.erase(x);
            ++cnt[x];
        };
        auto del = [&](const int x) -> void {
            if(x > n) return;
            --cnt[x];
            if(cnt[x] == 0) st.insert(x);
        };
        for(int i = 0; i < n - 2; ++i) add(pruefer[i]);
        for(int i = 0; i < n - 2; ++i) {
            const int a = *st.begin();
            const int b = pruefer[i];
            u[i] = a + one;
            v[i] = b + one;
            del(b);
            add(a);
        }
        const int a = *st.begin();
        add(a);
        const int b = *st.begin();
        u[n - 2] = a + one;
        v[n - 2] = b + one;
        return {u, v};
    }
    template <typename T>
    inline tuple<vector<int>, vector<int>, vector<T>> weighted_tree(const int n, const T lower, const T upper, const bool one = true) {
        static_assert(is_integral_v<T> or is_floating_point_v<T>);
        assert(0 <= n and n <= (int)1e8);
        assert(lower <= upper);
        if(n == 0) return {{}, {}, {}};
        const auto [u, v] = tree(n, one);
        const vector<T> w = vec(n - 1, lower, upper, true);
        return {u, v, w};
    }
    inline pair<vector<int>, vector<int>> graph(const int n, const int m, const bool one = true) {
        assert(0 <= n and n <= (int)1e8);
        assert(0 <= m and m <= (int)min((ll)1e8, 1ll * n * (n - 1) / 2));
        vector<int> u, v;
        u.reserve(m);
        v.reserve(m);
        if(1ll * n * (n - 1) / 2 >= 2e6) {
            set<pair<int, int>> edge;
            while((int)edge.size() < m) {
                const int a = this->operator()(0, n - 1);
                const int b = this->operator()(0, n - 1);
                if(a >= b) continue;
                edge.insert({a, b});
            }
            for(const auto& [a, b] : edge) {
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
            const vector<int> p = perm(n * (n - 1) / 2, false);
            for(int i = 0; i < m; ++i) {
                u.push_back(edge[p[i]].first + one);
                v.push_back(edge[p[i]].second + one);
            }
        }
        return {u, v};
    }
    template <typename T>
    inline tuple<vector<int>, vector<int>, vector<T>> weighted_graph(const int n, const int m, const T lower, const T upper, const bool one = true) {
        static_assert(is_integral_v<T> or is_floating_point_v<T>);
        assert(0 <= n and n <= (int)1e8);
        assert(0 <= m and m <= (int)min((ll)1e8, 1ll * n * (n - 1) / 2));
        assert(lower <= upper);
        const auto [u, v] = graph(n, m, one);
        const vector<T> w = vec(m, lower, upper, true);
        return {u, v, w};
    }
    inline pair<vector<int>, vector<int>> connected_graph(const int n, const int m, const bool one = true) {
        assert(0 <= n and n <= (int)1e8);
        assert(max(n - 1, 0) <= m and m <= (int)min((ll)1e8, 1ll * n * (n - 1) / 2));
        if(n <= 1) return {{}, {}};
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
                const int a = this->operator()(0, n - 1);
                const int b = this->operator()(0, n - 1);
                if(a >= b) continue;
                edge.insert({a, b});
            }
            for(const auto& [a, b] : edge) {
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
            const vector<int> p = perm(n * (n - 1) / 2 - (n - 1), false);
            for(int i = 0; i < m - (n - 1); ++i) {
                u.push_back(edge[p[i]].first + one);
                v.push_back(edge[p[i]].second + one);
            }
        }
        return {u, v};
    }
    template <typename T>
    inline tuple<vector<int>, vector<int>, vector<T>> weighted_connected_graph(const int n, const int m, const T lower, const T upper, const bool one = true) {
        static_assert(is_integral_v<T> or is_floating_point_v<T>);
        assert(0 <= n and n <= (int)1e8);
        assert(max(n - 1, 0) <= m and m <= (int)min((ll)1e8, 1ll * n * (n - 1) / 2));
        assert(lower <= upper);
        const auto [u, v] = connected_graph(n, m, one);
        const vector<T> w = vec(m, lower, upper, true);
        return {u, v, w};
    }
    inline string parenthesis(const int n) {
        assert(0 <= n and n <= 1e8);
        string res = "";
        int N = n, M = n;
        for(int i = 0; i < 2 * n; ++i) {
            if(this->operator()(0.0l, 1.0l) > 1.0l * (N - M) * (N + 1) / ((N - M + 1) * (N + M))) {
                res += "(";
                --M;
            } else {
                res += ")";
                --N;
            }
        }
        return res;
    }

   private:
    mt19937_64 mt;
} rng;