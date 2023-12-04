#include <bits/stdc++.h>
using namespace std;
struct S {
    long long value;
    long long size;
};
using F = long long;
S op(S a, S b) {
    return {a.value + b.value, a.size + b.size};
}
S e() {
    return {0, 0};
}
S mapping(F f, S x) {
    return {x.value + f * x.size, x.size};
}
F composition(F f, F g) {
    return f + g;
}
F id() {
    return 0;
}
