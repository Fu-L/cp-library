#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, a, b) for(ll i = a; i < b; ++i)
#define rrep(i, a, b) for(ll i = a; i >= b; --i)
constexpr ll inf = 4e18;
struct SetupIO {
    SetupIO() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout << fixed << setprecision(30);
    }
} setup_io;