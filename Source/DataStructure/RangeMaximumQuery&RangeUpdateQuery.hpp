#include <bits/stdc++.h>
using namespace std;
using S = long long;
using F = long long;
const S INF = 8e18;
const F ID = 8e18;
S op(S a, S b) {
    return max(a, b);
}
S e() {
    return -INF;
}
S mapping(F f, S x) {
    return (f == ID ? x : f);
}
F composition(F f, F g) {
    return (f == ID ? g : f);
}
F id() {
    return ID;
}
