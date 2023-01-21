#include <bits/stdc++.h>
using namespace std;
struct Data {
    // 持ちたいデータ。
    double x, y, vx, vy;
    // 加法演算の定義。ベクトルの成分ごとに加算。
    Data& operator+=(const Data& d) {
        (*this).x += d.x;
        (*this).y += d.y;
        (*this).vx += d.vx;
        (*this).vy += d.vy;
        return (*this);
    }
    Data operator+(const Data& d) {
        return (Data(*this) += d);
    }
    // 乗法演算の定義。ベクトルの全成分を定数倍。
    Data& operator*=(const double& k) {
        (*this).x *= k;
        (*this).y *= k;
        (*this).vx *= k;
        (*this).vy *= k;
        return (*this);
    }
    Data operator*(const double& k) {
        return (Data(*this) *= k);
    }
};
// 微分方程式f(X)の定義。
Data func(Data X) {
    Data res;
    res.x = X.vx;
    res.y = X.vy;
    res.vx = X.vy;
    res.vy = -X.vx;
    return res;
}
void Euler(vector<Data>& Y, double h, int period) {
    for(int i = 0; i < period; i++) {
        Data k = func(Y[i]);
        Y[i + 1] = Y[i] + k * h;
    }
}
void Heun(vector<Data>& Y, double h, int period) {
    for(int i = 0; i < period; i++) {
        Data k1 = func(Y[i]);
        Data k2 = func(Y[i] + k1 * h);
        Y[i + 1] = Y[i] + (k1 + k2) * (h / 2.0);
    }
}
void RK4(vector<Data>& Y, double h, int period) {
    for(int i = 0; i < period; i++) {
        Data k1 = func(Y[i]);
        Data k2 = func(Y[i] + k1 * (h / 2.0));
        Data k3 = func(Y[i] + k2 * (h / 2.0));
        Data k4 = func(Y[i] + k3 * h);
        Y[i + 1] = Y[i] + (k1 + k2 * 2.0 + k3 * 2.0 + k4) * (h / 6.0);
    }
}
int main(void) {
    // 定数などの宣言。
    const double m = 1.0;
    const double q = 1.0;
    const double B = 1.0;
    const double tau = 2.0 * M_PI * m / (q * B);
    const int period = 64;
    const double dt = tau / period;
    vector<Data> Y(period + 1);
    Y[0] = {-1.0, 0.0, 0.0, 1.0};
    // Euler(Y, dt, period);
    // Heun(Y, dt, period);
    RK4(Y, dt, period);
    for(int i = 0; i <= period; i++) {
        cout << fixed << setprecision(15) << Y[i].x << ' ' << Y[i].y << '\n';
    }
    return 0;
}
