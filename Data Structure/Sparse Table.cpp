// vector<int> vec(n); SparseTable<int> st(vec); でSparseTableを構築。
// st.query(l,r); でvec[l]~vec[r-1]のminを求める。minをmax,gcd,lcmに変えることもできる。vecの更新はできない。
// string s; vector<int> sa=saffix_array(s); vector<int> lcp=lcp_array(s,sa); SparseTable<int> st(lcp);を求めておくと、
// int len=st.query(l,r); でsのsa[l]からとsa[r]からの接頭辞が何文字共通しているかが求められる。
template<typename T>
struct SparseTable{
    vector<vector<T>> st;
    SparseTable(vector<T> &a){
        int n=a.size();
        int LOG=32-__builtin_clz(n);
        st=vector<vector<T>>(LOG,vector<T>(n));
        rep(i,0,n){
            st[0][i]=a[i];
        }
        rep(i,0,LOG-1){
            rep(j,0,n-(1<<i)){
                st[i+1][j]=min(st[i][j],st[i][j+(1<<i)]);
            }
        }
    }
    T query(int l,int r){
        int d=31-__builtin_clz(r-l);
        return min(st[d][l],st[d][r-(1<<d)]);
    }
};
