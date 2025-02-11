#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eb emplace_back
 
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    vector<int> c(n + m);
    int i = 0, j = 0, k = 0;
    while (i < n || j < m) {
        if (j == m || (i < n && a[i] < b[j])) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    for (int i = 0; i < n + m; i++) cout << c[i] << " ";
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