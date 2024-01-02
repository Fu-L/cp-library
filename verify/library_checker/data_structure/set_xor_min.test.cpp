#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include "../../../src/template/template.hpp"
#include "../../../src/data_structure/binary_trie.hpp"
int main(void) {
    int q;
    cin >> q;
    BinaryTrie<int, 30> trie;
    while(q--) {
        int t, x;
        cin >> t >> x;
        if(t == 0) {
            trie.insert(x);
        } else if(t == 1) {
            trie.erase(x);
        } else {
            cout << trie.min(x) << '\n';
        }
    }
}