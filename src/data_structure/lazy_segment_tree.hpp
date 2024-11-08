#pragma once
#include "../template/template.hpp"
template <typename S, auto op, auto e, typename F, auto mapping, auto composition, auto id>
struct LazySegmentTree {
    LazySegmentTree(const int N)
        : LazySegmentTree(vector<S>(N, e())) {}
    LazySegmentTree(const vector<S>& v)
        : n((int)v.size()) {
        size = bit_ceil((unsigned int)n);
        log = countr_zero((unsigned int)size);
        data = vector<S>(2 * size, e());
        lazy = vector<F>(size, id());
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
        for(int i = log; i >= 1; --i) {
            push(p >> i);
        }
        data[p] = x;
        for(int i = 1; i <= log; ++i) {
            update(p >> i);
        }
    }
    S get(int p) {
        assert(0 <= p and p < n);
        p += size;
        for(int i = log; i >= 1; --i) {
            push(p >> i);
        }
        return data[p];
    }
    S prod(int l, int r) {
        assert(0 <= l and l <= r and r <= n);
        if(l == r) return e();
        l += size;
        r += size;
        for(int i = log; i >= 1; --i) {
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push((r - 1) >> i);
        }
        S sml = e(), smr = e();
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
    void apply(int l, int r, const F& f) {
        assert(0 <= l and l <= r and r <= n);
        if(l == r) return;
        l += size;
        r += size;
        for(int i = log; i >= 1; --i) {
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push((r - 1) >> i);
        }
        {
            int l2 = l, r2 = r;
            while(l < r) {
                if(l & 1) all_apply(l++, f);
                if(r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }
        for(int i = 1; i <= log; ++i) {
            if(((l >> i) << i) != l) update(l >> i);
            if(((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)>
    int max_right(const int l) {
        return max_right(l, [](const S& x) { return g(x); });
    }
    template <class G>
    int max_right(int l, const G& g) {
        assert(0 <= l and l <= n);
        assert(g(e()));
        if(l == n) return n;
        l += size;
        for(int i = log; i >= 1; --i) push(l >> i);
        S sm = e();
        do {
            while(l % 2 == 0) l >>= 1;
            if(!g(op(sm, data[l]))) {
                while(l < size) {
                    push(l);
                    l = 2 * l;
                    if(g(op(sm, data[l]))) {
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

    template <bool (*g)(S)>
    int min_left(const int r) {
        return min_left(r, [](const S& x) { return g(x); });
    }
    template <class G>
    int min_left(int r, const G& g) {
        assert(0 <= r and r <= n);
        assert(g(e()));
        if(r == 0) return 0;
        r += size;
        for(int i = log; i >= 1; --i) push((r - 1) >> i);
        S sm = e();
        do {
            --r;
            while(r > 1 and (r % 2)) r >>= 1;
            if(!g(op(data[r], sm))) {
                while(r < size) {
                    push(r);
                    r = 2 * r + 1;
                    if(g(op(data[r], sm))) {
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
    vector<F> lazy;
    inline void update(const int k) {
        data[k] = op(data[2 * k], data[2 * k + 1]);
    }
    inline void all_apply(const int k, const F& f) {
        data[k] = mapping(f, data[k]);
        if(k < size) {
            lazy[k] = composition(f, lazy[k]);
        }
    }
    inline void push(const int k) {
        all_apply(2 * k, lazy[k]);
        all_apply(2 * k + 1, lazy[k]);
        lazy[k] = id();
    }
    inline unsigned int bit_ceil(const unsigned int n) const {
        unsigned int res = 1;
        while(res < n) res *= 2;
        return res;
    }
    inline int countr_zero(const unsigned int n) const {
        return __builtin_ctz(n);
    }
};