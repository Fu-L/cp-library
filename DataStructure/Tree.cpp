#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
using Tree = tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>; // set
// using Tree = tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>; // multiset

Tree st;

st.insert(5);
st.insert(6);
st.insert(7);
st.insert(5);
st.erase(7); multisetの場合は効かないので注意。

auto itr=st.find_by_order(k); // stの中のk番目(0-indexed)のイテレータを返す。
int k=st.order_of_key(x); // stの中のx以上の最小値が何番目に小さいかを返す。

auto itr = st.find_by_order(st.order_og_key(x)); // stの中のx以上の最小値のイテレータ

st.erase(st.find_by_order(st.order_of_key(x))); // multisetの場合のerase