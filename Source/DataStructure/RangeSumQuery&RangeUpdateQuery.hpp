#include <bits/stdc++.h>
using namespace std;
struct S {
    long long value;
    long long size;
};
using F = long long;
const F ID = 8e18;
S op(S a, S b) {
    return {a.value + b.value, a.size + b.size};
}
S e() {
    return {0, 0};
}
S mapping(F f, S x) {
    if(f != ID) x.value = f * x.size;
    return x;
}
F composition(F f, F g) {
    return (f == ID ? g : f);
}
F id() {
    return ID;
}
