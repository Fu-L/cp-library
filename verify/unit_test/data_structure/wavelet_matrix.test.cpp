#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/data_structure/wavelet_matrix.hpp"
int main() {
    {
        WaveletMatrix<int> wm(vector<int>{});
        assert(wm.range_freq(0, 0, -1) == 0);
        assert(wm.range_freq(0, 0, 0) == 0);
        assert(wm.range_freq(0, 0, 10) == 0);
        assert(wm.prev_value(0, 0, 10) == -1);
        assert(wm.next_value(0, 0, 0) == -1);
    }
    {
        WaveletMatrix<int> wm(5);
        for(int i = 0; i < 5; ++i) wm.set(i, i * i % 7);
        wm.build();
        assert(wm.get(0) == 0);
        assert(wm.get(1) == 1);
        assert(wm.get(2) == 4);
        assert(wm.get(3) == 2);
        assert(wm.get(4) == 2);
    }
    mt19937 mt(0);
    for(int n = 0; n <= 80; ++n) {
        vector<int> a(n);
        for(int& x : a) x = mt() % 32;
        WaveletMatrix<int> wm(a);
        for(int l = 0; l <= n; ++l) {
            for(int r = l; r <= n; ++r) {
                vector<int> b(a.begin() + l, a.begin() + r);
                sort(b.begin(), b.end());
                for(int upper = -2; upper <= 35; ++upper) {
                    const int freq = lower_bound(b.begin(), b.end(), upper) - b.begin();
                    assert(wm.range_freq(l, r, upper) == freq);
                    if(upper >= 0) assert(wm.range_freq(l, r, 0, upper) == freq);
                    const int less = lower_bound(b.begin(), b.end(), upper) - b.begin();
                    assert(wm.prev_value(l, r, upper) == (less == 0 ? -1 : b[less - 1]));
                    assert(wm.next_value(l, r, upper) == (less == (int)b.size() ? -1 : b[less]));
                }
                for(int k = 0; k < (int)b.size(); ++k) {
                    assert(wm.kth_smallest(l, r, k) == b[k]);
                    assert(wm.kth_largest(l, r, k) == b[(int)b.size() - 1 - k]);
                }
            }
        }
    }
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}