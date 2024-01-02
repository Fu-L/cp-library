# DynamicModint

自動で $\mathrm{mod}$ をとる構造体です．

基本的には `StaticModint` と同じなので違いだけを書きます．

`StaticModint` は $\mathrm{mod}$ がコンパイル時定数である必要がありましたが， `DynamicModint` はそうでない場合でも使用できます．

## set_mod

```cpp
void modint::set_mod(int m)
```

$\mathrm{mod}$ を $m$ に設定します．<br>
最初に呼んでください．

**制約**

- $1 \leq m \leq 2 \times 10^9 + 1000$

**計算量**

- $O(1)$

## Tips (複数mod)

複数種類 $\mathrm{mod}$ を使用したい場合，以下のようにできます．

```cpp
using mint0 = DynamicModint<0>;
using mint1 = DynamicModint<1>;
int main(void){
    int p0, p1;
    cin >> p0 >> p1;
    mint0::set_mod(p0);
    mint1::set_mod(p1);
}
```

`modint` は `DynamicModint<-1>` のエイリアスになっています．