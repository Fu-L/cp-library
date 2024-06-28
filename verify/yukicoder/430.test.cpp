#define PROBLEM "https://yukicoder.me/problems/no/430"
#include "../../src/template/template.hpp"
#include "../../src/string/aho_corasick.hpp"
int main(void) {
    string S;
    int M;
    cin >> S >> M;
    AhoCorasick<26, 'A'> aho;
    for(int i = 0; i < M; i++) {
        string T;
        cin >> T;
        aho.insert(T, i);
    }
    aho.build();
    vector<int> cnt = aho.match(S);
    int ans = 0;
    rep(i, 0, (int)cnt.size()) {
        ans += cnt[i];
    }
    cout << ans << '\n';
}