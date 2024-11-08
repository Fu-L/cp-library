#include "../template/template.hpp"
constexpr long long extgcd(const long long a, const long long b, long long& x, long long& y) {
    long long d = a;
    if(b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}