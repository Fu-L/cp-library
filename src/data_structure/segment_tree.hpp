#pragma once
#include "src/template/template.hpp"
template <typename S, auto op, auto e>
struct SegmentTree {
    SegmentTree(int N)
        : SegmentTree(vector<S>(N, e())) {}
    SegmentTree(const vector<S>& v)
        : n((int)v.size()) {
        size = bit_ceil((unsigned int)n);
        log = countr_zero((unsigned int)size);
        data = vector<S>(2 * size, e());
        for(int i = 0; i < n; ++i) {
            data[size + i] = v[i];
        }
        for(int i = size - 1; i >= 1; --i) {
            update(i);
        }
    }
    void set(int p, const S& x) {
        assert(0 <= p and p < n);
        p += size;
        data[p] = x;
        for(int i = 1; i <= log; ++i) {
            update(p >> i);
        }
    }
    S get(int p) const {
        assert(0 <= p and p < n);
        return data[p + size];
    }
    S prod(int l, int r) const {
        assert(0 <= l and l <= r and r <= n);
        S sml = e(), smr = e();
        l += size;
        r += size;
        while(l < r) {
            if(l & 1) sml = op(sml, data[l++]);
            if(r & 1) smr = op(data[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }
    S all_prod() const {
        return data[1];
    }

    template <bool (*f)(S)>
    int max_right(int l) const {
        return max_right(l, [](const S& x) { return f(x); });
    }
    template <class F>
    int max_right(int l, const F& f) const {
        assert(0 <= l and l <= n);
        assert(f(e()));
        if(l == n) return n;
        l += size;
        S sm = e();
        do {
            while(l % 2 == 0) l >>= 1;
            if(!f(op(sm, data[l]))) {
                while(l < size) {
                    l = l * 2;
                    if(f(op(sm, data[l]))) {
                        sm = op(sm, data[l]);
                        ++l;
                    }
                }
                return l - size;
            }
            sm = op(sm, data[l]);
            ++l;
        } while((l & -l) != l);
        return n;
    }

    template <bool (*f)(S)>
    int min_left(int r) const {
        return min_left(r, [](const S& x) { return f(x); });
    }
    template <class F>
    int min_left(int r, const F& f) const {
        assert(0 <= r and r <= n);
        assert(f(e()));
        if(r == 0) return 0;
        r += size;
        S sm = e();
        do {
            --r;
            while(r > 1 and (r % 2)) r >>= 1;
            if(!f(op(data[r], sm))) {
                while(r < size) {
                    r = 2 * r + 1;
                    if(f(op(data[r], sm))) {
                        sm = op(data[r], sm);
                        --r;
                    }
                }
                return r + 1 - size;
            }
            sm = op(data[r], sm);
        } while((r & -r) != r);
        return 0;
    }

   private:
    int n, size, log;
    vector<S> data;
    inline void update(int k) {
        data[k] = op(data[2 * k], data[2 * k + 1]);
    }
    inline unsigned int bit_ceil(unsigned int n) {
        unsigned int res = 1;
        while(res < n) res *= 2;
        return res;
    }
    inline int countr_zero(unsigned int n) {
        return __builtin_ctz(n);
    }
};