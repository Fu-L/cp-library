#define PROBLEM "https://yukicoder.me/problems/no/649"
#include "../../src/template/template.hpp"
#include "../../src/data_structure/sorted_set.hpp"
int main(void) {
    int q, k;
    cin >> q >> k;
    SortedMultiSet st;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            ll v;
            cin >> v;
            st.insert(v);
        } else {
            if((int)st.size() < k) {
                cout << -1 << '\n';
            } else {
                auto itr = st.find_by_order(k - 1);
                cout << *itr << '\n';
                st.erase(itr);
            }
        }
    }
}