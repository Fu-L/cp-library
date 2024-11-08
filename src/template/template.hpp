#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
#define rep(i, a, b) for(long long i = (a); i < (b); ++i)
#define rrep(i, a, b) for(long long i = (a); i >= (b); --i)
constexpr long long inf = 4e18;
struct SetupIO {
    SetupIO() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout << fixed << setprecision(30);
    }
} setup_io;