template<typename T>
vector<vector<T>> rotate(vector<vector<T>> vec){
    int n=vec.size(),m=vec[0].size();
    vector<vector<T>> res(m,vector<T>(n));
    rep(i,0,n){
        rep(j,0,m){
            res[j][n-1-i]=vec[i][j];
        }
    }
    return res;
}
