#pragma once
#include "../template/template.hpp"
#include "./bit_vector.hpp"
template <typename T>
struct WaveletMatrix {
   private:
    using u32 = uint32_t;
    using i64 = int64_t;
    using u64 = uint64_t;
    int n, lg;
    vector<T> a;
    vector<BitVector> bv;
    inline pair<u32, u32> succ0(const int l, const int r, const int h) const {
        return make_pair(bv[h].rank0(l), bv[h].rank0(r));
    }
    inline pair<u32, u32> succ1(const int l, const int r, const int h) const {
        const u32 l0 = bv[h].rank0(l);
        const u32 r0 = bv[h].rank0(r);
        const u32 zeros = bv[h].zeros;
        return make_pair(l + zeros - l0, r + zeros - r0);
    }

   public:
    WaveletMatrix(const u32 _n)
        : n(_n), lg(0), a(n) {}
    WaveletMatrix(const vector<T>& _a)
        : n(_a.size()), lg(0), a(_a) {
        build();
    }
    __attribute__((optimize("O3"))) void build() {
        if(n == 0) {
            lg = 0;
            bv.clear();
            return;
        }
        for(const T& x : a) assert(x >= 0);
        lg = __lg(max<T>(*max_element(begin(a), end(a)), 1)) + 1;
        bv.assign(lg, n);
        vector<T> cur = a, nxt(n);
        for(int h = lg - 1; h >= 0; --h) {
            for(int i = 0; i < n; ++i)
                if((cur[i] >> h) & 1) bv[h].set(i);
            bv[h].build();
            array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt) + bv[h].zeros};
            for(int i = 0; i < n; ++i) *it[bv[h].get(i)]++ = cur[i];
            swap(cur, nxt);
        }
        return;
    }
    void set(const int i, const T& x) {
        assert(0 <= i and i < n);
        assert(x >= 0);
        a[i] = x;
    }
    T get(u32 k) const {
        assert(int(k) < n);
        T ret = 0;
        for(int h = lg - 1; h >= 0; --h) {
            const u32 f = bv[h].get(k);
            ret |= f ? T(1) << h : 0;
            k = f ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);
        }
        return ret;
    }
    T kth_smallest(u32 l, u32 r, u32 k) const {
        assert(l <= r and int(r) <= n);
        assert(k < r - l);
        T res = 0;
        for(int h = lg - 1; h >= 0; --h) {
            const u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
            if(k < r0 - l0)
                l = l0, r = r0;
            else {
                k -= r0 - l0;
                res |= (T)1 << h;
                l += bv[h].zeros - l0;
                r += bv[h].zeros - r0;
            }
        }
        return res;
    }
    T kth_largest(const int l, const int r, const int k) const {
        assert(0 <= l and l <= r and r <= n);
        assert(0 <= k and k < r - l);
        return kth_smallest(l, r, r - l - k - 1);
    }
    int range_freq(int l, int r, const T& upper) const {
        assert(0 <= l and l <= r and r <= n);
        if(upper <= 0) return 0;
        if(lg < (int)numeric_limits<T>::digits and upper >= (T(1) << lg)) return r - l;
        int ret = 0;
        for(int h = lg - 1; h >= 0; --h) {
            const bool f = (upper >> h) & 1;
            const u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
            if(f) {
                ret += r0 - l0;
                l += bv[h].zeros - l0;
                r += bv[h].zeros - r0;
            } else {
                l = l0;
                r = r0;
            }
        }
        return ret;
    }
    int range_freq(const int l, const int r, const T& lower, const T& upper) const {
        assert(0 <= l and l <= r and r <= n);
        assert(lower <= upper);
        return range_freq(l, r, upper) - range_freq(l, r, lower);
    }
    T prev_value(const int l, const int r, const T& upper) const {
        assert(0 <= l and l <= r and r <= n);
        const int cnt = range_freq(l, r, upper);
        return cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);
    }
    T next_value(const int l, const int r, const T& lower) const {
        assert(0 <= l and l <= r and r <= n);
        const int cnt = range_freq(l, r, lower);
        return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt);
    }
};