Tree st;

st.insert(5);
st.insert(6);
st.insert(7);
st.insert(5);
st.erase(7);  // multisetの場合は効かないので注意。

auto itr = st.find_by_order(2);  // stの中のk番目(0-indexed)のイテレータを返す。
int k = st.order_of_key(6);      // stの中のx以上の最小値が何番目に小さいかを返す。

auto itr = st.find_by_order(st.order_of_key(6));  // stの中のx以上の最小値のイテレータ

st.erase(st.find_by_order(st.order_of_key(6)));  // multisetの場合のerase