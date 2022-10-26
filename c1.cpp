#include<bits/stdc++.h>
using namespace std;

#define ll long long

// C1. Make Nonzero Sum (easy version) 

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for(auto &x : a) {
        cin >> x;
        sum += x;
    }

    cout << sum << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);

    int tc = 1;
    cin >> tc;
    for(int i = 1; i <= tc; i++) {
        // cout << "Case: #" << i << " ";
        solve();
    }

    return 0;
}
