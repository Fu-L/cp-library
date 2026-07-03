#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/random/permuted_congruential_generator.hpp"
#include "../../../src/data_structure/segment_set.hpp"
vector<pair<int, int>> enumerate_segments(const vector<bool>& used) {
    vector<pair<int, int>> res;
    const int n = used.size();
    int i = 0;
    while(i < n) {
        if(!used[i]) {
            ++i;
            continue;
        }
        int j = i;
        while(j < n and used[j]) ++j;
        res.emplace_back(i, j);
        i = j;
    }
    return res;
}
void assert_same(const SegmentSet<int>& st, const vector<bool>& used) {
    const vector<pair<int, int>> expected = enumerate_segments(used);
    assert(st.size() == expected.size());
    vector<pair<int, int>> actual;
    for(const auto& p : st) actual.push_back(p);
    assert(actual == expected);

    const int n = used.size();
    rep(x, 0, n) {
        const auto it = st.find(x);
        if(used[x]) {
            assert(it != st.end());
            assert(it->first <= x and x < it->second);
        } else {
            assert(it == st.end());
        }

        int expected_next = numeric_limits<int>::max();
        rep(y, x, n) {
            if(used[y]) {
                expected_next = y;
                break;
            }
        }
        assert(st.next(x) == expected_next);

        const auto lb = st.lower_bound(x);
        pair<int, int> expected_lb{-1, -1};
        for(const auto& p : expected) {
            if(p.second <= x) continue;
            expected_lb = p;
            break;
        }
        if(expected_lb.first == -1) {
            assert(lb == st.end());
        } else {
            assert(lb != st.end());
            assert(*lb == expected_lb);
        }
    }
}
void test_sample_like() {
    SegmentSet<int> st;
    vector<bool> used(25);
    auto insert = [&](int l, int r) {
        st.insert(l, r);
        rep(i, l, r) used[i] = true;
        assert_same(st, used);
    };
    auto erase = [&](int l, int r) {
        st.erase(l, r);
        rep(i, l, r) used[i] = false;
        assert_same(st, used);
    };
    insert(3, 7);
    insert(10, 15);
    insert(13, 20);
    erase(5, 13);
}
void test_random() {
    constexpr int n = 80;
    SegmentSet<int> st;
    vector<bool> used(n);
    const int query_num = 1000;
    rep(_, 0, query_num) {
        int l = rng(0, n - 1);
        int r = rng(l + 1, n);
        if(rng(0, 1)) {
            st.insert(l, r);
            rep(i, l, r) used[i] = true;
        } else {
            st.erase(l, r);
            rep(i, l, r) used[i] = false;
        }
        assert_same(st, used);
    }
}
int main(void) {
    test_sample_like();
    constexpr int test_num = 100;
    rep(_, 0, test_num) {
        test_random();
    }
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}
