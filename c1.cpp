#include<bits/stdc++.h>
using namespace std;

#define ll long long

// C1. Make Nonzero Sum (easy version)   

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);

    long long sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if(sum % 2 != 0) {
        cout << "-1\n";
        return ;
    }

    vector<pair<int, int>> ans;
    for(int i = 2; i <= n; i += 2) {
        if(a[i - 1] == a[i])
            ans.push_back({i-1, i});
        else {
            ans.push_back({i-1, i-1});
            ans.push_back({i, i});
        }
    }

    cout << ans.size() << "\n";
    for(auto x : ans) {
        cout << x.first << " " << x.second << "\n";
    }
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
