#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/data_structure/binary_trie.hpp"
int main() {
    BinaryTrie<int, 3> trie;
    trie.insert(0);
    trie.insert(3);
    trie.insert(7);
    assert(trie.lower_bound(0) == 0);
    assert(trie.lower_bound(8) == 3);
    assert(trie.upper_bound(7) == 3);
    assert(trie.kth_element(1, 1) == 2);
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}