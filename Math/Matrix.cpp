template <typename T>
struct Matrix {
    int h, w;
    vector<vector<T>> A;
    Matrix(int h, int w, T val = 0)
        : h(h), w(w), A(h, vector<T>(w, val)) {}
    const vector<T>& operator[](int i) const {
        return A[i];
    }
    vector<T>& operator[](int i) {
        return A[i];
    }
    static Matrix I(int n) {
        Matrix mat(n, n);
        rep(i, 0, n) mat[i][i] = 1;
        return mat;
    }
    Matrix& operator+=(const Matrix& B) {
        assert(h == B.h and w == B.w);
        rep(i, 0, h) {
            rep(j, 0, w) {
                (*this)[i][j] += B[i][j];
            }
        }
        return (*this);
    }
    Matrix& operator-=(const Matrix& B) {
        assert(h == B.h and w == B.w);
        rep(i, 0, h) {
            rep(j, 0, w) {
                (*this)[i][j] -= B[i][j];
            }
        }
        return (*this);
    }
    Matrix& operator*=(const Matrix& B) {
        assert(w == B.h);
        vector<vector<T>> C(h, vector<T>(B.w, 0));
        rep(i, 0, h) rep(k, 0, w) rep(j, 0, B.w) {
            C[i][j] += (*this)[i][k] * B[k][j];
        }
        A.swap(C);
        return (*this);
    }
    Matrix pow(ll t) const {
        assert(h == w);
        if(!t) return Matrix::I(h);
        if(t == 1) return *this;
        Matrix B = pow(t >> 1);
        B *= B;
        if(t & 1) B *= (*this);
        return B;
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
        rep(i, 0, h) {
            rep(j, 0, w) {
                if(A[i][j] != B[i][j]) return true;
            }
        }
        return false;
    }
    T determinant() const {
        assert(h == w);
        Matrix B(*this);
        T res = 1;
        rep(i, 0, h) {
            int idx = -1;
            rep(j, i, w) {
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
            rep(j, 0, w) {
                B[i][j] *= inv;
            }
            rep(j, i + 1, h) {
                T a = B[j][i];
                if(a == 0) continue;
                rep(k, i, w) {
                    B[j][k] -= B[i][k] * a;
                }
            }
        }
        return res;
    }
};
