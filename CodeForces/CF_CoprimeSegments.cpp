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

    ll result = LLONG_MAX;
    for (ll l = 0, r = 0; r < n; r++) {
        current_gcd = gcd(current_gcd, a[r]);

        if (current_gcd == 1) {
            ll x = 0;
            for (l = r; x != 1; l--)
                current_gcd = exchange(x, gcd(x, a[l]));

            result = min(result, r - l);
            l += 2;
        }
    }

    cout << (result == LLONG_MAX ? -1 : result) << endl;
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