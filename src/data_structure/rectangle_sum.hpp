#pragma once
#include "../template/template.hpp"
#include <immintrin.h>
struct BitVector {
    using u32 = uint32_t;
    using i64 = int64_t;
    using u64 = uint64_t;
    static constexpr u32 w = 64;
    vector<u64> block;
    vector<u32> count;
    u32 n, zeros;
    inline u32 get(u32 i) const {
        return u32(block[i / w] >> (i % w)) & 1u;
    }
    inline void set(u32 i) {
        block[i / w] |= 1LL << (i % w);
    }
    BitVector() {}
    BitVector(int _n) {
        init(_n);
    }
    __attribute__((optimize("O3,unroll-loops"))) void init(int _n) {
        n = zeros = _n;
        block.resize(n / w + 1, 0);
        count.resize(block.size(), 0);
    }
    __attribute__((target("popcnt"))) void build() {
        for(u32 i = 1; i < block.size(); ++i) {
            count[i] = count[i - 1] + _mm_popcnt_u64(block[i - 1]);
        }
        zeros = rank0(n);
    }
    inline u32 rank0(u32 i) const {
        return i - rank1(i);
    }
    __attribute__((target("bmi2,popcnt"))) inline u32 rank1(u32 i) const {
        return count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i / w], i % w));
    }
};
template <typename S, typename T>
struct RectangleSum {
    RectangleSum() {}
    void add_point(const S& x, const S& y, const T& w) {
        ps.emplace_back(make_pair(x, y), w);
        ys.emplace_back(y);
    }
    __attribute__((optimize("O3"))) void build() {
        n = ps.size();
        sort(begin(ps), end(ps));
        sort(begin(ys), end(ys));
        ys.erase(unique(begin(ys), end(ys)), end(ys));
        lg = __lg(max(n, 1)) + 1;
        bv.assign(lg, n);
        vector<int> cur(n), nxt(n);
        for(int i = 0; i < n; ++i) {
            cur[i] = yid(ps[i].first.second);
        }
        for(int h = lg - 1; h >= 0; --h) {
            for(int i = 0; i < n; ++i)
                if((cur[i] >> h) & 1) bv[h].set(i);
            bv[h].build();
            array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt) + bv[h].zeros};
            for(int i = 0; i < n; ++i) *it[bv[h].get(i)]++ = cur[i];
            swap(cur, nxt);
        }
        s.assign(lg, vector<T>(n + 1));
        for(int _i = 0; _i < n; ++_i) {
            int i = _i;
            for(int h = lg - 1; h >= 0; --h) {
                int i0 = bv[h].rank0(i);
                if(bv[h].get(i)) i += bv[h].zeros - i0;
                else i = i0;
                s[h][i + 1] += ps[_i].second;
            }
        }
        for(int h = 0; h < lg; ++h) {
            for(int i = 0; i < n; ++i) {
                s[h][i + 1] += s[h][i];
            }
        }
    }
    T sum(const S& l, const S& d, const S& r, const S& u) const {
        assert(l <= r and d <= u);
        int left = xid(l), right = xid(r);
        return range_sum(left, right, yid(u)) - range_sum(left, right, yid(d));
    }

   private:
    using u32 = uint32_t;
    using i64 = int64_t;
    using u64 = uint64_t;
    using P = pair<S, S>;
    int n, lg;
    vector<BitVector> bv;
    vector<vector<T>> s;
    vector<pair<P, T>> ps;
    vector<S> ys;
    inline int xid(const S& x) const {
        return lower_bound(begin(ps), end(ps), make_pair(make_pair(x, S()), T()), [](const pair<P, T>& a, const pair<P, T>& b) { return a.first.first < b.first.first; }) - begin(ps);
    }
    inline int yid(const S& y) const {
        return lower_bound(begin(ys), end(ys), y) - begin(ys);
    }
    T range_sum(int l, int r, int upper) const {
        T ret = 0;
        for(int h = lg - 1; h >= 0; --h) {
            u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
            if((upper >> h) & 1) {
                ret += s[h][r0] - s[h][l0];
                l += bv[h].zeros - l0;
                r += bv[h].zeros - r0;
            } else {
                l = l0;
                r = r0;
            }
        }
        return ret;
    }
};