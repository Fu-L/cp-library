#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/data_structure/bit_vector.hpp"
int main() {
    BitVector bv(130);
    bv.set(0);
    bv.set(63);
    bv.set(64);
    bv.set(129);
    bv.build();
    assert(bv.get(0) == 1);
    assert(bv.get(1) == 0);
    assert(bv.get(63) == 1);
    assert(bv.get(64) == 1);
    assert(bv.get(129) == 1);
    assert(bv.rank1(0) == 0);
    assert(bv.rank1(64) == 2);
    assert(bv.rank1(65) == 3);
    assert(bv.rank1(130) == 4);
    assert(bv.rank0(130) == 126);
    bv.init(4);
    bv.build();
    assert(bv.rank1(4) == 0);
    assert(bv.rank0(4) == 4);
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}