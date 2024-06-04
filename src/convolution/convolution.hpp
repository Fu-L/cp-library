#pragma once
#include "../template/template.hpp"
#include "../math/primitive_root.hpp"
constexpr int countr_zero(unsigned int n) {
    int res = 0;
    while(!(n & (1 << res))) ++res;
    return res;
}
template <typename mint, int g = primitive_root(mint::mod())>
struct FFT_Info {
    static constexpr int rank2 = countr_zero(mint::mod() - 1);
    array<mint, rank2 + 1> root;
    array<mint, rank2 + 1> iroot;
    array<mint, max(0, rank2 - 2 + 1)> rate2;
    array<mint, max(0, rank2 - 2 + 1)> irate2;
    array<mint, max(0, rank2 - 3 + 1)> rate3;
    array<mint, max(0, rank2 - 3 + 1)> irate3;
    FFT_Info() {
        root[rank2] = mint(g).pow((mint::mod() - 1) >> rank2);
        iroot[rank2] = root[rank2].inv();
        for(int i = rank2 - 1; i >= 0; --i) {
            root[i] = root[i + 1] * root[i + 1];
            iroot[i] = iroot[i + 1] * iroot[i + 1];
        }
        {
            mint prod = 1, iprod = 1;
            for(int i = 0; i <= rank2 - 2; ++i) {
                rate2[i] = root[i + 2] * prod;
                irate2[i] = iroot[i + 2] * iprod;
                prod *= iroot[i + 2];
                iprod *= root[i + 2];
            }
        }
        {
            mint prod = 1, iprod = 1;
            for(int i = 0; i <= rank2 - 3; ++i) {
                rate3[i] = root[i + 3] * prod;
                irate3[i] = iroot[i + 3] * iprod;
                prod *= iroot[i + 3];
                iprod *= root[i + 3];
            }
        }
    }
};
template <typename mint>
void butterfly(vector<mint>& a) {
    int n = (int)a.size();
    int h = __builtin_ctz((unsigned int)n);
    static const FFT_Info<mint> info;
    int len = 0;
    while(len < h) {
        if(h - len == 1) {
            int p = 1 << (h - len - 1);
            mint rot = 1;
            for(int s = 0; s < (1 << len); ++s) {
                int offset = s << (h - len);
                for(int i = 0; i < p; ++i) {
                    auto l = a[i + offset];
                    auto r = a[i + offset + p] * rot;
                    a[i + offset] = l + r;
                    a[i + offset + p] = l - r;
                }
                if(s + 1 != (1 << len)) rot *= info.rate2[__builtin_ctz(~(unsigned int)(s))];
            }
            ++len;
        } else {
            int p = 1 << (h - len - 2);
            mint rot = 1, imag = info.root[2];
            for(int s = 0; s < (1 << len); ++s) {
                mint rot2 = rot * rot;
                mint rot3 = rot2 * rot;
                int offset = s << (h - len);
                for(int i = 0; i < p; ++i) {
                    auto mod2 = 1ULL * mint::mod() * mint::mod();
                    auto a0 = 1ULL * a[i + offset].val();
                    auto a1 = 1ULL * a[i + offset + p].val() * rot.val();
                    auto a2 = 1ULL * a[i + offset + 2 * p].val() * rot2.val();
                    auto a3 = 1ULL * a[i + offset + 3 * p].val() * rot3.val();
                    auto a1na3imag = 1ULL * mint(a1 + mod2 - a3).val() * imag.val();
                    auto na2 = mod2 - a2;
                    a[i + offset] = a0 + a2 + a1 + a3;
                    a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));
                    a[i + offset + 2 * p] = a0 + na2 + a1na3imag;
                    a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);
                }
                if(s + 1 != (1 << len)) rot *= info.rate3[__builtin_ctz(~(unsigned int)(s))];
            }
            len += 2;
        }
    }
}
template <typename mint>
void butterfly_inv(vector<mint>& a) {
    int n = (int)a.size();
    int h = __builtin_ctz((unsigned int)n);
    static const FFT_Info<mint> info;
    int len = h;
    while(len) {
        if(len == 1) {
            int p = 1 << (h - len);
            mint irot = 1;
            for(int s = 0; s < (1 << (len - 1)); ++s) {
                int offset = s << (h - len + 1);
                for(int i = 0; i < p; ++i) {
                    auto l = a[i + offset];
                    auto r = a[i + offset + p];
                    a[i + offset] = l + r;
                    a[i + offset + p] = (unsigned long long)(mint::mod() + l.val() - r.val()) * irot.val();
                }
                if(s + 1 != (1 << (len - 1))) irot *= info.irate2[__builtin_ctz(~(unsigned int)(s))];
            }
            --len;
        } else {
            int p = 1 << (h - len);
            mint irot = 1, iimag = info.iroot[2];
            for(int s = 0; s < (1 << (len - 2)); ++s) {
                mint irot2 = irot * irot;
                mint irot3 = irot2 * irot;
                int offset = s << (h - len + 2);
                for(int i = 0; i < p; ++i) {
                    auto a0 = 1ULL * a[i + offset + 0 * p].val();
                    auto a1 = 1ULL * a[i + offset + 1 * p].val();
                    auto a2 = 1ULL * a[i + offset + 2 * p].val();
                    auto a3 = 1ULL * a[i + offset + 3 * p].val();
                    auto a2na3iimag = 1ULL * mint((mint::mod() + a2 - a3) * iimag.val()).val();
                    a[i + offset] = a0 + a1 + a2 + a3;
                    a[i + offset + 1 * p] = (a0 + (mint::mod() - a1) + a2na3iimag) * irot.val();
                    a[i + offset + 2 * p] = (a0 + a1 + (mint::mod() - a2) + (mint::mod() - a3)) * irot2.val();
                    a[i + offset + 3 * p] = (a0 + (mint::mod() - a1) + (mint::mod() - a2na3iimag)) * irot3.val();
                }
                if(s + 1 != (1 << (len - 2))) irot *= info.irate3[__builtin_ctz(~(unsigned int)(s))];
            }
            len -= 2;
        }
    }
}
template <typename mint>
vector<mint> convolution_naive(const vector<mint>& a, const vector<mint>& b) {
    int n = (int)a.size(), m = (int)b.size();
    vector<mint> res(n + m - 1);
    if(n < m) {
        for(int j = 0; j < m; ++j) {
            for(int i = 0; i < n; ++i) {
                res[i + j] += a[i] * b[j];
            }
        }
    } else {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                res[i + j] += a[i] * b[j];
            }
        }
    }
    return res;
}
template <typename mint>
vector<mint> convolution(vector<mint> a, vector<mint> b) {
    const int n = (int)a.size(), m = (int)b.size();
    if(n == 0 or m == 0) return {};
    int z = 1;
    while(z < n + m - 1) z *= 2;
    assert((mint::mod() - 1) % z == 0);
    if(min(n, m) <= 60) return convolution_naive(a, b);
    a.resize(z);
    b.resize(z);
    butterfly(a);
    butterfly(b);
    for(int i = 0; i < z; ++i) a[i] *= b[i];
    butterfly_inv(a);
    a.resize(n + m - 1);
    const mint iz = mint(z).inv();
    for(int i = 0; i < n + m - 1; ++i) a[i] *= iz;
    return a;
}