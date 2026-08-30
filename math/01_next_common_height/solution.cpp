// Problem: Next Common Height (Nandu and Chandu)
// Pattern: LCM of two step sizes — divide-before-multiply to avoid overflow
// Time: O(log(min(a,b))) per test case  Space: O(1)

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
