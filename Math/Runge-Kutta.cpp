#include <bits/stdc++.h>
using namespace std;
struct RungeKutta : vector<double> {
    using vector<double>::vector;
    RungeKutta& operator+=(const RungeKutta& v) {
        for(int i = 0; i < (int)this->size(); i++) {
            (*this)[i] += v[i];
        }
        return *this;
    }
    RungeKutta operator+(const RungeKutta& v) {
        return (RungeKutta)(*this) += v;
    }
    RungeKutta& operator*=(const double& k) {
        for(int i = 0; i < (int)this->size(); i++) {
            (*this)[i] *= k;
        }
        return *this;
    }
    RungeKutta operator*(const double& k) {
        return (RungeKutta)(*this) *= k;
    }
    RungeKutta func() const;
    vector<RungeKutta> calc(double dt, int period) {
        vector<RungeKutta> Y;
        Y.push_back(*this);
        for(int i = 0; i < period; i++) {
            RungeKutta k1 = Y.back().func();
            RungeKutta k2 = (Y.back() + k1 * (dt / 2.0)).func();
            RungeKutta k3 = (Y.back() + k2 * (dt / 2.0)).func();
            RungeKutta k4 = (Y.back() + k3 * dt).func();
            Y.push_back(Y.back() + (k1 + k2 * 2.0 + k3 * 2.0 + k4) * (dt / 6.0));
        }
        return Y;
    }
};
RungeKutta RungeKutta::func() const {
    const int n = this->size();
    RungeKutta res(n);
    // To do 微分方程式f(X)の定義 [0] : x, [1] : y, [2] : vx, [3] : vy
    res[0] = (*this)[2];
    res[1] = (*this)[3];
    res[2] = (*this)[3];
    res[3] = -(*this)[2];
    return res;
}
int main(void) {
    // To do 定数などの宣言
    const double m = 1.0;
    const double q = 1.0;
    const double B = 1.0;
    const double tau = 2.0 * M_PI * m / (q * B);
    const int period = 64;
    const double dt = tau / period;
    // To do 初期値の設定
    RungeKutta Y_0 = {-1.0, 0.0, 0.0, 1.0};
    // To do 時間幅と繰り返し回数を指定
    vector<RungeKutta> Y = Y_0.calc(dt, period);
    for(int i = 0; i <= period; i++) {
        cout << fixed << setprecision(15) << Y[i][0] << ' ' << Y[i][1] << '\n';
    }
    return 0;
}
