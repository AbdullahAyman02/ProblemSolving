#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        if(a + b == c)
            cout << "+\n";
        else
            cout << "-\n";
    }
    return 0;
}