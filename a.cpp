#include<bits/stdc++.h>
using namespace std;

#define ll long long

// A. Technical Support

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int cnt = 0;
    for(auto x : s) {
        if(x == 'Q')
            cnt++;
    }

    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'Q') {
            int j = i + 1;
            while(j < n and s[j] != 'A') 
                j++;
            if(s[j] != 'A') {
                mp[i] = 0;
            } else {
                mp[i] = j;
                s[j] = 'B';
            }
        }
    }

    bool ok = true;
    for(auto p : mp) {
        if(p.second == 0)
            ok = false;
    }
    ok ? cout << "YES\n" : cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    
    int tc = 1;
    cin >> tc;
    for(int i = 1; i <= tc; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
