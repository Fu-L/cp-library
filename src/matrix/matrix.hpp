#pragma once
#include "../template/template.hpp"
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
    const vector<T>& operator[](int i) const {
        assert(0 <= i and i < h);
        return A[i];
    }
    vector<T>& operator[](int i) {
        assert(0 <= i and i < h);
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
    Matrix& pow(long long t) {
        assert(h == w);
        assert(t >= 0);
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
        assert(h == B.H() and w == B.W());
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(A[i][j] != B[i][j]) return false;
            }
        }
        return true;
    }
    bool operator!=(const Matrix& B) const {
        assert(h == B.H() and w == B.W());
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(A[i][j] != B[i][j]) return true;
            }
        }
        return false;
    }

   private:
    int h, w;
    vector<vector<T>> A;
};