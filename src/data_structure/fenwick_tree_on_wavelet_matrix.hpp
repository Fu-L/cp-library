#pragma once
#include "../template/template.hpp"
#include "./bit_vector.hpp"
template <typename S, typename T>
struct FenwickTreeonWaveletMatrix {
   private:
    using u32 = uint32_t;
    using i64 = int64_t;
    using u64 = uint64_t;
    struct FenwickTree {
        u32 N;
        vector<T> data;
        FenwickTree() = default;
        FenwickTree(const int size) {
            init(size);
        }
        void init(const int size) {
            N = size;
            data.assign(N + 1, 0);
        }
        CP_LIBRARY_TARGET_BMI void add(u32 k, const T& x) {
            for(++k; k <= N; k += lowbit(k)) data[k] += x;
        }
        CP_LIBRARY_TARGET_BMI T sum(u32 k) const {
            T ret = T();
            for(; k; k = clear_lowbit(k)) ret += data[k];
            return ret;
        }
        CP_LIBRARY_TARGET_BMI T sum(int l, int r) const {
            T ret = T();
            while(l != r) {
                if(l < r) {
                    ret += data[r];
                    r = clear_lowbit(r);
                } else {
                    ret -= data[l];
                    l = clear_lowbit(l);
                }
            }
            return ret;
        }
    };
    using P = pair<S, S>;
    int n, lg;
    vector<BitVector> bv;
    vector<FenwickTree> bit;
    vector<P> ps;
    vector<S> ys;
    inline int xid(const S& x) const {
        return lower_bound(begin(ps), end(ps), make_pair(x, S()), [](const P& a, const P& b) { return a.first < b.first; }) - begin(ps);
    }
    inline int yid(const S& y) const {
        return lower_bound(begin(ys), end(ys), y) - begin(ys);
    }
    T sum(int l, int r, const u32 upper) const {
        T res = 0;
        for(int h = lg; h--;) {
            const int l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
            if((upper >> h) & 1) {
                res += bit[h].sum(l0, r0);
                l += bv[h].zeros - l0;
                r += bv[h].zeros - r0;
            } else {
                l = l0, r = r0;
            }
        }
        return res;
    }

   public:
    FenwickTreeonWaveletMatrix() {}
    void add_point(const S& x, const S& y) {
        ps.emplace_back(x, y);
        ys.emplace_back(y);
    }
    __attribute__((optimize("O3"))) void build() {
        sort(begin(ps), end(ps));
        ps.erase(unique(begin(ps), end(ps)), end(ps));
        n = ps.size();
        sort(begin(ys), end(ys));
        ys.erase(unique(begin(ys), end(ys)), end(ys));
        vector<u32> cur(n), nxt(n);
        for(int i = 0; i < n; ++i) cur[i] = yid(ps[i].second);
        lg = __lg(max(n, 1)) + 1;
        bv.assign(lg, n);
        bit.assign(lg, n);
        for(int h = lg - 1; h >= 0; --h) {
            for(int i = 0; i < n; ++i) {
                if((cur[i] >> h) & 1) bv[h].set(i);
            }
            bv[h].build();
            array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt) + bv[h].zeros};
            for(int i = 0; i < n; ++i) *it[bv[h].get(i)]++ = cur[i];
            swap(cur, nxt);
        }
    }
    void add(const S& x, const S& y, const T& val) {
        int i = lower_bound(begin(ps), end(ps), P{x, y}) - begin(ps);
        for(int h = lg - 1; h >= 0; --h) {
            const int i0 = bv[h].rank0(i);
            if(bv[h].get(i)) i += bv[h].zeros - i0;
            else i = i0;
            bit[h].add(i, val);
        }
    }
    T sum(const S& l, const S& d, const S& r, const S& u) const {
        assert(l <= r and d <= u);
        const int left = xid(l), right = xid(r);
        return sum(left, right, yid(u)) - sum(left, right, yid(d));
    }
};