#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/modint/static_modint.hpp"
#include "../../../src/convolution/gcd_convolution.hpp"
#include "../../../src/convolution/lcm_convolution.hpp"
#include "../../../src/convolution/xor_convolution.hpp"
#include "../../../src/math/divisor_multiple_transform.hpp"
#include "../../../src/math/walsh_hadamard_transform.hpp"
using mint = modint998244353;
int main() {
    vector<mint> empty;
    DivisorTransform::zeta_transform(empty);
    DivisorTransform::moebius_transform(empty);
    MultipleTransform::zeta_transform(empty);
    MultipleTransform::moebius_transform(empty);
    assert(empty.empty());
    assert(gcd_convolution(empty, empty).empty());
    assert(lcm_convolution(empty, empty).empty());
    assert(xor_convolution(empty, empty).empty());
    walsh_hadamard_transform(empty, true);
    assert(empty.empty());
    vector<mint> one{5};
    DivisorTransform::zeta_transform(one);
    DivisorTransform::moebius_transform(one);
    MultipleTransform::zeta_transform(one);
    MultipleTransform::moebius_transform(one);
    assert(one == vector<mint>{5});
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}