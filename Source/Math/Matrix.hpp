#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct Matrix {
    Matrix(int h, int w, T val = 0)
        : h(h), w(w), A(h, vector<T>(w, val)) {}
    int H() const {
        return h;
    }
    int W() const {
        return w;
    }
    inline const vector<T>& operator[](int i) const {
        return A[i];
    }
    inline vector<T>& operator[](int i) {
        return A[i];
    }
    static Matrix I(int n) {
        Matrix mat(n, n);
        for(int i = 0; i < n; ++i) mat[i][i] = 1;
        return mat;
    }
    Matrix& operator+=(const Matrix& B) {
        assert(h == B.h and w == B.w);
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                (*this)[i][j] += B[i][j];
            }
        }
        return (*this);
    }
    Matrix& operator-=(const Matrix& B) {
        assert(h == B.h and w == B.w);
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                (*this)[i][j] -= B[i][j];
            }
        }
        return (*this);
    }
    Matrix& operator*=(const Matrix& B) {
        assert(w == B.h);
        vector<vector<T>> C(h, vector<T>(B.w, 0));
        for(int i = 0; i < h; ++i) {
            for(int k = 0; k < w; ++k) {
                for(int j = 0; j < B.w; ++j) {
                    C[i][j] += (*this)[i][k] * B[k][j];
                }
            }
        }
        A.swap(C);
        return (*this);
    }
    Matrix& pow(ll t) {
        assert(h == w);
        Matrix B = Matrix::I(h);
        while(t > 0) {
            if(t & 1ll) B *= (*this);
            (*this) *= (*this);
            t >>= 1ll;
        }
        A.swap(B.A);
        return (*this);
    }
    Matrix operator+(const Matrix& B) const {
        return (Matrix(*this) += B);
    }
    Matrix operator-(const Matrix& B) const {
        return (Matrix(*this) -= B);
    }
    Matrix operator*(const Matrix& B) const {
        return (Matrix(*this) *= B);
    }
    bool operator==(const Matrix& B) const {
        assert(h == B.h and w == B.w);
        rep(i, 0, h) {
            rep(j, 0, w) {
                if(A[i][j] != B[i][j]) return false;
            }
        }
        return true;
    }
    bool operator!=(const Matrix& B) const {
        assert(h == B.h and w == B.w);
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(A[i][j] != B[i][j]) return true;
            }
        }
        return false;
    }
    T determinant() const {
        assert(h == w);
        Matrix B(*this);
        T res = 1;
        for(int i = 0; i < h; ++i) {
            int idx = -1;
            for(int j = i; j < w; ++j) {
                if(B[j][i] != 0) {
                    idx = j;
                    break;
                }
            }
            if(idx == -1) return 0;
            if(i != idx) {
                res *= T(-1);
                swap(B[i], B[idx]);
            }
            res *= B[i][i];
            T inv = T(1) / B[i][i];
            for(int j = 0; j < w; ++j) {
                B[i][j] *= inv;
            }
            for(int j = i + 1; j < h; ++j) {
                T a = B[j][i];
                if(a == 0) continue;
                for(int k = i; k < w; ++k) {
                    B[j][k] -= B[i][k] * a;
                }
            }
        }
        return res;
    }

   private:
    int h, w;
    vector<vector<T>> A;
};