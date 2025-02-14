#pragma once
#include "../template/template.hpp"
#include "./trie.hpp"
template <size_t X = 26, char margin = 'a', bool heavy = true>
struct AhoCorasick : Trie<X + 1, margin> {
    using TRIE = Trie<X + 1, margin>;
    using TRIE::next;
    using TRIE::st;
    using TRIE::TRIE;
    vector<int> cnt;
    void build() {
        const int n = (int)st.size();
        cnt.resize(n);
        for(int i = 0; i < n; ++i) {
            if(heavy) sort(st[i].idxs.begin(), st[i].idxs.end());
            cnt[i] = (int)st[i].idxs.size();
        }
        queue<int> que;
        for(int i = 0; i < (int)X; ++i) {
            if(~next(0, i)) {
                next(next(0, i), X) = 0;
                que.emplace(next(0, i));
            } else {
                next(0, i) = 0;
            }
        }
        while(!que.empty()) {
            auto& x = st[que.front()];
            int fail = x.nxt[X];
            cnt[que.front()] += cnt[fail];
            que.pop();
            for(int i = 0; i < (int)X; ++i) {
                int& nx = x.nxt[i];
                if(nx < 0) {
                    nx = next(fail, i);
                    continue;
                }
                que.emplace(nx);
                next(nx, X) = next(fail, i);
                if(heavy) {
                    auto& idx = st[nx].idxs;
                    auto& idy = st[next(fail, i)].idxs;
                    vector<int> idz;
                    set_union(idx.begin(), idx.end(), idy.begin(), idy.end(), back_inserter(idz));
                    idx = idz;
                }
            }
        }
    }
    conditional_t<heavy, unordered_map<int, long long>, long long> match(const string& s, int pos = 0) {
        unordered_map<int, int> pos_cnt;
        for(const auto& c : s) {
            pos = next(pos, c - margin);
            ++pos_cnt[pos];
        }
        conditional_t<heavy, unordered_map<int, long long>, long long> res{};
        for(const auto& [key, val] : pos_cnt) {
            if constexpr(heavy) {
                for(const auto& x : st[key].idxs) res[x] += val;
            } else {
                res += 1ll * cnt[key] * val;
            }
        }
        return res;
    }
    pair<long long, int> move(const char c, int pos = 0) {
        pos = next(pos, c - margin);
        return {cnt[pos], pos};
    }
    pair<long long, int> move(const string& s, int pos = 0) {
        long long sum = 0;
        for(const char c : s) {
            auto nxt = move(c, pos);
            sum += nxt.first;
            pos = nxt.second;
        }
        return {sum, pos};
    }
    int count(const int pos) const {
        return cnt[pos];
    }
};