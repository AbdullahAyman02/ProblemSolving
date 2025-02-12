#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eb emplace_back

ll current_gcd = 0;

void add(ll x) {
}

void remove() {
}

bool good() {
}

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0;
    int result = INT_MAX;
    for (int r = 0; r < n; r++) {
        current_gcd = gcd(current_gcd, a[r]);
        while (current_gcd == 1) {
            result = min(result, r - l + 1);
            l++;

            if (l <= r) {
                current_gcd = a[l];
                for (int k = l + 1; k <= r; k++) {
                    current_gcd = gcd(current_gcd, a[k]);
                }
            }
        }
    }
    cout << (result == INT_MAX ? -1 : result) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t;
    while (t--)
        solve();
    return 0;
}