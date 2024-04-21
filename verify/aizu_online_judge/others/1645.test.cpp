#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1645"
#include "../../../src/template/template.hpp"
#include "../../../src/data_structure/rollback_union_find.hpp"
struct Edge {
    int u, v, s;
};
bool comp(const Edge& e1, const Edge& e2) {
    return e1.s < e2.s;
}
int main(void) {
    while(1) {
        int n, m;
        cin >> n >> m;
        if(n == 0 and m == 0) break;
        vector<Edge> e(m);
        rep(i, 0, m) {
            cin >> e[i].u >> e[i].v >> e[i].s;
            e[i].u--;
            e[i].v--;
        }
        sort(e.begin(), e.end(), comp);
        RollbackUnionFind uf(n);
        rrep(i, m - 1, 0) {
            uf.merge(e[i].u, e[i].v);
        }
        set<int> stl;
        stl.insert(uf.leader(0));
        rep(i, 0, m) {
            int j;
            for(j = i; j < m; ++j) {
                if(e[i].s != e[j].s) break;
            }
            set<int> er, id;
            rep(k, i, j) {
                if(stl.find(uf.leader(e[k].u)) != stl.end()) {
                    er.insert(uf.leader(e[k].u));
                    id.insert(k);
                }
            }
            rep(k, i, j) {
                uf.undo();
            }
            for(const int x : er) {
                stl.erase(x);
            }
            for(const int x : id) {
                stl.insert(uf.leader(e[x].u));
                stl.insert(uf.leader(e[x].v));
            }
            int ma = 0;
            for(const int x : stl) {
                ma = max(ma, uf.size(x));
            }
            set<int> nst;
            for(const int x : stl) {
                if(uf.size(x) == ma) {
                    nst.insert(x);
                }
            }
            swap(stl, nst);
            i = j - 1;
        }
        bool flag = false;
        for(const int x : stl) {
            if(flag) cout << ' ';
            cout << x + 1;
            flag = true;
        }
        cout << '\n';
    }
}