#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eb emplace_back
 
void solve() {
    ll n, s; cin >> n >> s;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    int l = 0, result = INT_MAX;
    ll sum = 0;
    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (sum - a[l] >= s) sum -= a[l++];
        if (sum >= s) result = min(result, r - l + 1);
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