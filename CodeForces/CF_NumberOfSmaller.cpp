#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eb emplace_back
 
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    vector<int> c(m, 0);
    int i = 0;
    for (int j = 0; j < m; j++) {
        while (i < n && a[i] < b[j]) i++;
        c[j] = i;
    }
    for (int i = 0; i < m; i++) cout << c[i] << " ";
    cout << endl;
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