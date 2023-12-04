# RandomNumberGenerator

乱数生成，ランダムな配列の生成，ランダムな順列の生成を行う．

## コンストラクタ
```cpp
RandomNumberGenerator rng;
```

## num, operator()
```cpp
long long rng.num(long long lower, long long upper)
long long rng(long long lower, long long upper)
```
- $[lower, upper]$の一様乱数を生成する．

## vec
```cpp
vector<long long> rng.vec(int n, long long lower, long long upper)
```
- $[lower, upper]$の一様乱数に従った長さ$n$の配列を生成する．

## perm
```cpp
vector<long long> rng.perm(int n)
```
- $1 ~ n$を並べ替えたランダムな順列を生成する．