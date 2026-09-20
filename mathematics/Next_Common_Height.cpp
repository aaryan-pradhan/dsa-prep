// Problem: Next Common Height (Nandu and Chandu)
// Pattern: LCM of two step sizes — divide-before-multiply to avoid overflow
// Time: O(log(min(a,b))) per test case  Space: O(1)
//
// Both start at height x. One jumps up by a each move, the other by b each
// move. T test cases, each (x, a, b). Output the next height (strictly above
// x) both will visit.
//
// Example:
//     (1, 1, 2)  -> 3
//         (1, 19, 19) -> 20
//         (17, 2, 3) -> 23

#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        long long x, a, b;
        cin >> x >> a >> b;
        long long lcm = a / gcd(a, b) * b;
        cout << x + lcm << '\n';
    }
    return 0;
}

// Recall Trail
// - A shared height above x needs k*a = m*b for some positive integers
//   k, m — the smallest such value is lcm(a, b). Answer: x + lcm(a, b).
// - lcm(a,b) = a / gcd(a,b) * b — divide by gcd *before* multiplying by b,
//   not after, to avoid a*b overflowing when a and b are both large.
// - All of x, a, b, and the result cast to long long — safe default for
//   number-theory problems where inputs can be large enough that int
//   overflows silently.
