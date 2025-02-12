#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eb emplace_back
 
void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < m; i++) cin >> b[i];
    ll i = 0, j = 0, result = 0, curr_value = INT_MIN, count_a = 0, count_b = 0;
    while(i < n && j < m) { 
        if (a[i] == b[j]) {
            curr_value = a[i];
            count_a = 0, count_b = 0;
            while (i < n && a[i] == curr_value) i++, count_a++;
            while (j < m && b[j] == curr_value) j++, count_b++;
            result += count_a * count_b;
        }
        else if (a[i] < b[j]) i++;
        else j++;
    }
    cout << result << endl;
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