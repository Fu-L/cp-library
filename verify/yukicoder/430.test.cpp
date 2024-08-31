#define PROBLEM "https://yukicoder.me/problems/no/430"
#include "../../src/template/template.hpp"
#include "../../src/string/aho_corasick.hpp"
int main(void) {
    string S;
    int M;
    cin >> S >> M;
    AhoCorasick<26, 'A', true> aho;
    for(int i = 0; i < M; i++) {
        string T;
        cin >> T;
        aho.insert(T, i);
    }
    aho.build();
    unordered_map<int, ll> cnt = aho.match(S);
    int ans = 0;
    for(const auto& it : cnt) {
        ans += it.second;
    }
    cout << ans << '\n';
}