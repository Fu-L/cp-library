#pragma once
#include "../template/template.hpp"
#include "../template/modint_2_61m1.hpp"
#include "../graph/graph_template.hpp"
template <typename T>
vector<ll> rooted_tree_hash(const Graph<T>& g, const int root = 0) {
    const int n = g.size();
    assert(0 <= root and root < n);
    static mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
    static vector<Modint_2_61m1> hash;
    while((int)hash.size() < n) {
        static uniform_int_distribution<unsigned long long> dist(0, Modint_2_61m1::mod() - 1);
        hash.emplace_back(dist(mt));
    }
    vector<ll> res(n);
    auto dfs = [&](auto& dfs, const int cur, const int par) -> int {
        int depth = 0;
        for(const auto& e : g[cur]) {
            if(e.to == par) continue;
            depth = max(depth, dfs(dfs, e.to, cur) + 1);
        }
        Modint_2_61m1 h = 1, r = hash[depth];
        for(const auto& e : g[cur]) {
            if(e.to == par) continue;
            h *= (r + res[e.to]);
        }
        res[cur] = h.val();
        return depth;
    };
    dfs(dfs, root, -1);
    return res;
}