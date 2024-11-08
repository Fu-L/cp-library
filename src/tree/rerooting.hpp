#pragma once
#include "../template/template.hpp"
#include "../graph/graph_template.hpp"
template <typename DP, typename T, typename F1, typename F2>
vector<DP> rerooting(const Graph<T>& g, const F1& f1, const F2& f2, const DP& id) {
    const int n = g.size();
    vector<DP> memo(n, id), dp(n, id);
    auto dfs = [&](auto& dfs, const int cur, const int par) -> void {
        for(const Edge<T>& e : g[cur]) {
            if(e.to == par) continue;
            dfs(dfs, e.to, cur);
            memo[cur] = f1(memo[cur], f2(memo[e.to], e.to, cur));
        }
    };
    auto efs = [&](auto& efs, const int cur, const int par, const DP& pval) -> void {
        vector<DP> buf;
        for(const Edge<T>& e : g[cur]) {
            if(e.to == par) continue;
            buf.emplace_back(f2(memo[e.to], e.to, cur));
        }
        vector<T> head(buf.size() + 1), tail(buf.size() + 1);
        head[0] = tail[buf.size()] = id;
        for(int i = 0; i < (int)buf.size(); ++i) head[i + 1] = f1(head[i], buf[i]);
        for(int i = (int)buf.size() - 1; i >= 0; --i) {
            tail[i] = f1(tail[i + 1], buf[i]);
        }
        dp[cur] = par == -1 ? head.back() : f1(pval, head.back());
        int idx = 0;
        for(const Edge<T>& e : g[cur]) {
            if(e.to == par) continue;
            efs(efs, e.to, cur, f2(f1(pval, f1(head[idx], tail[idx + 1])), cur, e));
            ++idx;
        }
    };
    dfs(dfs, 0, -1);
    efs(efs, 0, -1, id);
    return dp;
}