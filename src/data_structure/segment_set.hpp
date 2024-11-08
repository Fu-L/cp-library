#pragma once
#include "../template/template.hpp"
template <typename T>
struct SegmentSet {
    SegmentSet() = default;
    using const_iterator = typename map<T, T>::const_iterator;
    const_iterator begin() const {
        return st.begin();
    }
    const_iterator end() const {
        return st.end();
    }
    const_iterator find(const T& x) const {
        auto it = st.upper_bound(x);
        if(it == st.begin() or (--it)->second <= x) return st.end();
        return it;
    }
    const_iterator lower_bound(const T& x) const {
        auto it = st.lower_bound(x);
        if(it == st.begin() or prev(it)->second <= x) return it;
        return prev(it);
    }
    void insert(T l, T r) {
        auto L = st.upper_bound(l), R = st.upper_bound(r);
        if(L != st.begin() and l <= prev(L)->second) --L;
        if(L != R) {
            l = min(l, L->first);
            r = max(r, prev(R)->second);
            st.erase(L, R);
        }
        st[l] = r;
    }
    void erase(const T& l, const T& r) {
        auto L = st.upper_bound(l), R = st.upper_bound(r);
        if(L != st.begin() and l <= prev(L)->second) --L;
        if(L == R) return;
        const T nl = min(l, L->first), nr = max(r, prev(R)->second);
        st.erase(L, R);
        if(nl < l) st[nl] = l;
        if(r < nr) st[r] = nr;
    }
    T next(const T& x) const {
        auto it = this->lower_bound(x);
        if(it == this->end()) return numeric_limits<T>::max();
        return max<T>(x, it->first);
    }
    size_t size() const {
        return st.size();
    }

   private:
    map<T, T> st;
};